#include <array>
#include <string>
#include <iomanip>
#include <iostream>
#include "constants.h"
#include "grading.h"
#include "utilities.h"
#include "printing.h"


bool isAtRisk(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    if ( studentAverage(scores, studentIndex) < 70.0 ) {
        return true;
    }

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] < 50.0 ) {
            return true;
        }
    }

    return false;
}

bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] >= 100.0 ) {
            return true;
        }
    }
    return false;
}


void printHeader() {
    std::cout << padName("STUDENT", NAME_WIDTH);

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        std::cout << std::setw(5) << "A" << i;
    }

    std::cout << std::setw(8) << "AVG" << std::setw(6) << "GRADE" << std::endl;

    for ( auto i{0}; i < 60; i++) {
        std::cout << "-";
    }

    std::cout << std::endl;
}

void printStudentRow(const std::array<std::string, STUDENT_COUNT> &names, const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT> &scores, int studentIndex) {
    std::cout << padName(names[studentIndex], NAME_WIDTH);

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        std::cout << std::setw(6) << std::setprecision(1) << std::fixed << scores[studentIndex][i];
    }
    double avg{studentAverage(scores, studentIndex)};
    std::cout << std::setw(8) << std::setprecision(2) << std::fixed << avg
              << " \t" << letterGrade(avg);
    if ( hasPerfectScore(scores, studentIndex) ) {
        std::cout << "  *";
    }
    if ( isAtRisk(scores, studentIndex) ) {
        std::cout << "  !";
    }
    std::cout << std::endl;
}

void printHistogram(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT> &scores, const std::array<std::string, STUDENT_COUNT> &names) {
    std::array<char,5> letters{{'A', 'B', 'C', 'D', 'F'}};

    std::cout << "\nGRADE DISTRIBUTION\n";

    for ( auto letter : letters ) {
        auto count{countGrade(scores, letter)};

        std::cout << letter << " | ";
        for ( auto i{0}; i < count; i++ ) {
            std::cout << "#";
        }
        std::cout << "\t\t(" << count << ")\n";
    }
}

void printAssignmentSummary(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT> &scores) {
    std::cout << "\nASSIGNMENT AVERAGES\n";

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        auto avg{assignmentAverage(scores, i)};
        std::cout << "  A" << i+1 << ": " << std::setw(6) << std::setprecision(2) << std::fixed << avg;
        if ( avg < 70.0 ) {
            std::cout << "\t<-- review this assignment";
        }
        std::cout << std::endl;
    }
}

void printRoster(const std::array<std::string, STUDENT_COUNT> &names) {
    std::cout << "\nROSTER\n";

    for ( auto name : names ) {
        std::cout << initialsOf(name) << "\t" << name << std::endl;
    }
}
