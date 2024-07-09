#include <iostream>
#include "student.h"

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; ++i) {
        this->daysToComplete[i] = daysToComplete[i];
    }
    this->degreeProgram = degreeProgram;
}

void Student::setStudentID(std::string newID) {
    studentID = newID;
}

void Student::setFirstName(std::string newFirstName) {
    firstName = newFirstName;
}

void Student::setLastName(std::string newLastName) {
    lastName = newLastName;
}

void Student::setEmailAddress(std::string newEmail) {
    emailAddress = newEmail;
}

void Student::setAge(int newAge) {
    age = newAge;
}

void Student::setDaysToComplete(int newArr[3]) {
    for (int i = 0; i < 3; i++) {
        daysToComplete[i] = newArr[i];
    }
}

void Student::setDegreeProgram(DegreeProgram newDegree) {
    degreeProgram = newDegree;
}

std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

const int* Student::getDaysToComplete() const {
    return daysToComplete;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

void Student::print() const {
    std::cout << studentID << "\t"
              << "First Name: " << firstName << "\t"
              << "Last Name: " << lastName << "\t"
              << "Age: " << age << "\t"
              << "daysInCourse: {";
    for (int i = 0; i < 3; i++) {
        std::cout << daysToComplete[i];
        if (i < 2) {
            std::cout << ", ";
        }
    }
    std::cout << "} "
              << "Degree Program: " << degreeProgram << "\n";
}