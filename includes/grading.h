#ifndef GRADING_H
#define GRADING_H

// Look through specific student's grades and using the total amount of assignments to calculate their grade average
double studentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex);

// Looks through all student's letter grade and counts the amount of students that has that grade
int countGrade(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, char target);

// Looks through all student's number grade and calculates the average down to the decimal
double classAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores);

// Looks through a specific assignment and adds each student's grades to get the average for that assignment
double assignmentAverage(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int assignmentIndex);

// Looks through a specific assignment and adds each student's grades to get the average for that assignment
void findExtremes(const std::array<std::array<double, ASSIGNMENT_COUNT>, STUDENT_COUNT>& scores, int studentIndex, double &lowest, double &highest);

#endif
