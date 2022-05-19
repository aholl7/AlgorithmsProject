//
//  Student.cpp
//  FinalTeamProject
//
//  Created by Alfred Holland on 4/28/21.
//

#include <stdio.h>
#include <iostream>
#include "Student.h"

Student::Student(string firstName, string lastName, double grade, float GPA){
    this->firstName = firstName;
    this->lastName = lastName;
    this->grade = grade;
    this->GPA = GPA;
};

string Student::getFirstName(){
    return this->firstName;
};

string Student::getLastName(){
    return this->lastName;
};

double Student::getGrade(){
    return this->grade;
};

float Student::getGPA(){
    return this->GPA;
};
