#ifndef UTILITIES_H
#define UTILITIES_H

// Evens out student names to take the same amount of space
std::string padName(std::string fullName, int width);

// Gets initials of students by taking the first letter of their first and last name
std::string initialsOf(std::string fullName);

// Finds the average so that it can give the proper letter grade
char letterGrade(double average);

// Finds the student letter grade and gives a grade point average down to the decimals
double gradePoints(char letter);

#endif
