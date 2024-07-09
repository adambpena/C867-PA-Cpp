#include <stdio.h>
#include "degree.h"

class Student {
    public:
        void setStudentID(string newID);
        void setFirstName(string newFirstName);
        void setLastName(string newLastName);
        void setEmailAddress(string newEmail);
        void setAge(int newAge);
        void setDaysToComplete(int newArr[3]);
        void setDegreeProgram(DegreeProgram newDegree);

        string getStudentID();
        string getFirstName();
        string getLastName();
        string getEmailAddress();
        int getAge();
        int getDaysToComplete();
        DegreeProgram getDegreeProgram();

    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int[3] daysToComplete;
        DegreeProgram degreeProgram;
};

void Student::setStudentID(string newID){
    studentID = newID;
};

void Student::setFirstName(string newFirstName){
    firstName = newFirstName;
};

void Student::setLastName(string newLastName){
    lastName = newLastName;
};

void Student::setEmailAddress(string newEmail){
    emailAddress = newEmail;
};

void Student::setAge(int newAge){
    age = newAge;
};

void Student::setDaysToComplete(int newArr[3]){
    for (int i=0; i<3; i++) {
        daysToComplete[i] = newArr[i];
    }
};

void Student::setDegreeProgram(DegreeProgram newDegree){
    degreeProgram = newDegree;
};

string Student::getStudentID(){
    return studentID;
};

string Student::getFirstName(){
    return firstName;
};

string Student::getLastName(){
    return lastName;
};

string Student::getEmailAddress(){
    return emailAddress;
};

int Student::getAge(){
    return age;
};

int[3] Student::getDaysToComplete(){
    return daysToComplete;
};

DegreeProgram Student::getDegreeProgram(){
    return degreeProgram;
};