 * @mainpage Gradebook
 *
 * @section overview Project Overview
 * Welcome to the project documentation.
 *
 * - Click here to view the source file documentation: @ref gradebook.cpp
 */

/**
 * @file gradebook.cpp
 * @author Michael Nutt
 * @date 2026-08-31
 * @brief Functions for the gradebook project
 *
 * This file is the implementation of all the gradebook functions for this project.
 * */

#include <iostream>
#include <array>
#include <string>
#include <limits>
#include <iomanip>

constexpr int STUDENT_COUNT = 6;
constexpr int ASSIGNMENT_COUNT = 5;
constexpr int NAME_WIDTH = 14;
/**
 * @brief Calculates the selected students average
 *
 * This function takes the& scores 2d array and calculates the student's average.
 *
 * @param[in] scores The array of student/assignment scores
 * @param[in] studentIndex Index of the row of student data
 * @return The average of the student grades
 */
double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

/**
 * @brief Determines the average of selected assignment
 *
 * This function loops through the student& scores of the specified assignment and calculates the average
 * of the& scores stored.
 *
 * @param[in] scores The array of student/assignment scores
 * @param[in] assignmentIndex The index of the assignment to generate the average for
 * @return The average grade of the assignment
 */
double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex);

/**
 * @brief Finds the highest and lowest grades for a given student
 *
 * Iterates through all assignments and finds the highest and lowest assignment grades for a given
 * student.
 *
 * @param[in]& scores The array of student/assignment& scores
 * @param[in] studentIndex The index of the student to find the grades for
 * @param[out] lowest Variable passed by reference to contain the lowest score
 * @param[out] highest Variable passed by reference to contain the highest score
 */
void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest);

/**
 * @brief Returns the letter grade from the numeric average
 *
 * This function returns the character letter grade based on the numeric average passed in.
 *
 * @param[in] average The numeric average passed in
 * @return The character letter grade received
 */
char letterGrade(double average);

/**
 * @brief Returns the numeric gradepoints for the letter grade
 *
 * @param[in] letter The character letter grade the student received
 * @return The numeric grade point average received
 */
double gradePoints(char letter);

/**
 * @brief Returns how many students earned target letter grade
 *
 * @param[in] scores The array of student/assignment scores
 * @param[in] target The letter grade to look for
 */
int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target);

/**
 * @brief Returns the class average across all students and assignments
 *
 * @param[in] scores The array of student/assignment scores
 * @return The average of the grades
 */
double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);

/**
 * @brief Returns if the student has any scores 100 or above
 *
 * @param[in] scores The array of student/assignment scores
 * @param[in] studentIndex The index of the student to check
 */
bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

/**
 * @brief Returns true if the student's average is below 70
 *
 * @param[in] scores The array of student/assignment scores
 * @param[in] studentIndex The index of the student to check
 * @return True if the student average is below 70, False otherwise
 */
bool isAtRisk(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

/**
 */
std::string initialsOf(std::string fullName);

/**
 */
std::string padName(std::string fullName, int width);

/**
 */
void printHeader();

/**
 */
void printStudentRow(const std::array<std::string, STUDENT_COUNT>&names, const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

/**
 * @brief 
 */
void printHistogram(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, const std::array<std::string, STUDENT_COUNT>&names);

/**
 * @brief Prints the averages of the assignments
 *
 * @param[in] scores The array of student/assignment scores
 */
void printAssignmentSummary(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);

/**
 * @brief Print the roster of students
 *
 * @param[in] names Array of student names to print
 */
void printRoster(const std::array<std::string, STUDENT_COUNT>& names);

int main(int argc, char** argv) {
    
    int input{-1};
    std::array<std::string, STUDENT_COUNT> names = {
        "Ada Lovelace", "Grace Hopper", "Alan Turing", "Katherine Johnson", "Linus Torvalds", "Bill Gates"
    };
    
    // Program Loop
    while(input != 0) {
        const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores = {{
            {  95.0, 88.5, 92.0, 78.0, 100.0 },
            {  72.5, 80.0, 68.0, 91.0,  85.5 },
            {  55.0, 62.5, 48.0, 70.0,  59.0 },
            { 100.0, 98.0, 95.5, 99.0,  97.0 },
            {  83.0, 79.5, 88.0, 84.0,  91.5 },
            {  45.0, 52.0, 61.0, 38.5,  55.0 }
        }};

        // Program menu
        std::cout << "\n=== GRADEBOOK ===\n"
                  << "1. Full Report\n"
                  << "2. Grade Distribution\n"
                  << "3. Assignment Averages\n"
                  << "4. Roster\n"
                  << "5. Class Average\n"
                  << "0. Quit\n"
                  << "Choice: ";

        if ( std::cin >> input ) {
            switch(input) {
                case 1: {
                            // Full Report
                            printHeader();
                            for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
                                printStudentRow(names, scores, i);
                            }
                            std::cout << "\t* perfect score\t! at risk\n";
                            break;
                        }
                case 2: {
                            // Grade Distribution
                            printHistogram(scores, names);
                            break;
                        }
                case 3: {
                            // Assignment Averages
                            printAssignmentSummary(scores);
                            break;
                        }
                case 4: {
                            // Roster
                            printRoster(names);
                            break;
                        }
                case 5: {
                            // Class Average
                            double avg = classAverage(scores);
                            std::cout << "Class Average: " << std::setw(6) << std::setprecision(2) << std::fixed << avg << std::endl;
                            break;
                        }
                case 0: {
                            // Exit
                            std::cout << "Goodbye!\n";
                            break;
                        }
                case 7: {
                            std::cout << initialsOf("First Name") << std::endl;
                            break;
                        }
                default: 
                        {
                            std::cout << "Invalid choice, try again\n";
                        }
            }
        } else {
            // Clear the input stream after invalid input
            std::cout << "Invalid input!\n";

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max());
        }
       
    }


    return 0;
}

double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    // Check that the student index is correct
    if ( studentIndex < 0 || studentIndex >= STUDENT_COUNT ) {
        std::cout << "Invalid index provided\n";
        return -1.0;
    }
    double total{};

    // Gets the total of the assignment grades for the student
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        total += scores[studentIndex][i];
    }

    return total / ASSIGNMENT_COUNT;
}

double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex) {
    double total{};

    for (auto i{0}; i < STUDENT_COUNT; i++) {
        total += scores[i][assignmentIndex];
    }

    return total / STUDENT_COUNT;
}

void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest) {
    lowest = std::numeric_limits<double>::max();
    highest = std::numeric_limits<double>::min();

    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++) {
        if ( scores[studentIndex][i] < lowest ) {
            lowest = scores[studentIndex][i];
        }
        if (scores[studentIndex][i] > highest ) {
            highest = scores[studentIndex][i];
        }
    }

}

char letterGrade(double average) {
    if ( average >= 90 ) {
        return 'A';
    } else if ( average >= 80 ) {
        return 'B';
    } else if ( average >= 70 ) {
        return 'C';
    } else if ( average >= 60 ) {
        return 'D';
    } else {
        return 'F';
    }
}

double gradePoints(char letter) {
    switch(letter) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        default: return 0.0;
      }
}

int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target) {
    int count{};

    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        if ( letterGrade(studentAverage(scores, i)) == target ) {
            count++;
        }
    }

    return count;
}

double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores) {
    auto total{0.0};

    for ( auto i{0}; i < STUDENT_COUNT; i++ ) {
        for ( auto j{0}; j < ASSIGNMENT_COUNT; j++ ) {
            total += scores[i][j];
        }
    }

    return total / (STUDENT_COUNT * ASSIGNMENT_COUNT);
}

bool hasPerfectScore(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex) {
    for ( auto i{0}; i < ASSIGNMENT_COUNT; i++ ) {
        if ( scores[studentIndex][i] >= 100.0 ) {
            return true;
        }
    }
    return false;
}

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

std::string initialsOf(std::string fullName) {
    std::string result{};

    result += fullName[0];
    result += ". ";
    auto index = fullName.find(" ");
    result += fullName[index+1];
    result += ".";

    return result;
}

std::string padName(std::string fullName, int width) {
    fullName.resize(width, ' '); 
    return fullName;
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
