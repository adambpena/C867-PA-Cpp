#include <iostream>
#include <string>
#include "degree.h"  // Ensure this file is available and correctly defined

using namespace std;

class Student {
public:
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram);
    void setStudentID(string newID);
    void setFirstName(string newFirstName);
    void setLastName(string newLastName);
    void setEmailAddress(string newEmail);
    void setAge(int newAge);
    void setDaysToComplete(int newArr[3]);
    void setDegreeProgram(DegreeProgram newDegree);

    string getStudentID() const;
    string getFirstName() const;
    string getLastName() const;
    string getEmailAddress() const;
    int getAge() const;
    const int* getDaysToComplete() const;
    DegreeProgram getDegreeProgram() const;
    void print() const;

private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysToComplete[3];
    DegreeProgram degreeProgram;
};

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysToComplete[3], DegreeProgram degreeProgram) {
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

void Student::setStudentID(string newID) {
    studentID = newID;
}

void Student::setFirstName(string newFirstName) {
    firstName = newFirstName;
}

void Student::setLastName(string newLastName) {
    lastName = newLastName;
}

void Student::setEmailAddress(string newEmail) {
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

string Student::getStudentID() const {
    return studentID;
}

string Student::getFirstName() const {
    return firstName;
}

string Student::getLastName() const {
    return lastName;
}

string Student::getEmailAddress() const {
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

void Student::print() const{
    std::cout << "Student ID: " << studentID << "\n"
    << "First Name: " << firstName << "\n"
    << "Last Name: " << lastName << "\n"
    << "Email Address: " << emailAddress << "\n"
    << "Age: " << age << "\n"
    << "Days to Complete Courses: {";
    for(int i = 0; i < 3; i++){
        std::cout << daysToComplete[i];
        if(i < 2){
            std::cout << ", ";
        }
    }
    std::cout << "}\n"
    << "Degree Program: " <<  degreeProgram;
}

int main(int argc, char const *argv[])
{
    // Create an array of days to complete courses
    int days[3] = {30, 45, 60};
    
    // Create a Student object
    Student student("A123", "John", "Doe", "john.doe@example.com", 20, days, DegreeProgram::SOFTWARE);
    
    // Print the student's details
    student.print();
    return 0;
}