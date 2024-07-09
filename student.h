#pragma once
#include <string>
#include "degree.h"

class Student {
public:
    Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram);

    void setStudentID(std::string newID);
    void setFirstName(std::string newFirstName);
    void setLastName(std::string newLastName);
    void setEmailAddress(std::string newEmail);
    void setAge(int newAge);
    void setDaysToComplete(int newArr[3]);
    void setDegreeProgram(DegreeProgram newDegree);

    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysToComplete() const; // Return a const pointer to an array
    DegreeProgram getDegreeProgram() const;
    void print() const;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;
};