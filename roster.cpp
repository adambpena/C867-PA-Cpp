#include <iostream>
#include "roster.h"
using namespace std;

// class Roster
// {
//     public:
//         Student *classRosterArray[5];

//         void parse(std::string studentData); // Populates classRosterArray (calls Add to create Student objects and add them)
//         void add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram); // Called within parse
//         void remove(std::string studentId); // Destroy memory of student if found w/ "delete", if not report error "The student with the ID: {id}" was not found.
//         void printAll(); // Call each student's print message
//         void printAverageDaysInCourse(std::string studentId) // Find student w/ matching id and return averaged num of days in 3 courses
//         void printInvalidEmails() // Traverse through class roster and use Regex validation to validate. Return invalid emails
//         void printByDegreeProgram(DegreeProgram degreeProgram) // Call print method of students in roster w/ matching degree program
// }

std::string degreeProgramStrings[] = { "SECURITY", "NETWORK", "SOFTWARE" };

void Roster::parse(std::string studentData){
    size_t rhs = studentData.find(",");
    std::string studentID = studentData.substr(0, rhs);

    size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string firstName = studentData.substr(lhs, rhs-lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string lastName = studentData.substr(lhs, rhs-lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string emailAddress = studentData.substr(lhs, rhs-lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs-lhs));

     lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs-lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    std::string degree = studentData.substr(lhs, rhs-lhs);
    DegreeProgram degreeProgram = DegreeProgram::SECURITY; 

    if (degree == "SECURITY") {
        degreeProgram = DegreeProgram::SECURITY;
    } else if (degree == "NETWORK") {
        degreeProgram = DegreeProgram::NETWORK;
    } else if (degree == "SOFTWARE") {
        degreeProgram = DegreeProgram::SOFTWARE;
    }
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

};

void Roster::add(std::string studentId, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    cout << studentId << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << degreeProgram;
};