//
//  Student.h
//  FinalTeamProject
//
//  Created by Alfred Holland on 4/28/21.
//

#ifndef Student_h
#define Student_h

using namespace std;

class Student{
    private:
        string firstName;
        string lastName;
        double grade;
        float GPA;
    
    public:
    Student(string firstName, string lastName, double grade, float GPA);
    string getFirstName();
    string getLastName();
    double getGrade();
    float getGPA();
};

#endif /* Student_h */
