//includes/printing.h
#ifndef PRINTING_H
#define PRINTING_H
#include "constants.h"

// Writes the top row which explains the format of the chart
void printHeader();

// Writes the actual names of students, grades, average, and checks if they are at risk or have perfect score
void printStudentRow(const std::array<std::string, STUDENT_COUNT>&names, const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

// Writes how many students received each grade
void printHistogram(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, const std::array<std::string, STUDENT_COUNT>&names);


// Writes the averages for each assignment and if the average is less than 70, mark it for review
void printAssignmentSummary(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);

// Writes the names for every student in class
void printRoster(const std::array<std::string, STUDENT_COUNT>& names);

#endif

