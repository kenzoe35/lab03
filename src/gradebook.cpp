#include <iostream>
#include <array>
#include <string>
#include <limits>
#include <iomanip>
#include "constants.h"
#include "grading.h"
#include "utilities.h"
#include "printing.h"

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

