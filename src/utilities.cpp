#include "constants.h"
#include <string>

std::string padName(std::string fullName, int width) {
    fullName.resize(width, ' ');
    return fullName;
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
