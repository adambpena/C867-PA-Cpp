#include <iostream>
#include "student.h"
#include "roster.h"

int main(int argc, char const *argv[])
{
    std::cout << "C867-Scripting & Programming: Applications\nLanguage: C++\nStudent ID: 011408119\nName: Adam Pena";

    const std::string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Adam,Pena,apen166@wgu.edu,29,15,30,45,SOFTWARE"}; // Create an array of days to complete courses

    Roster classRoster;

    for(size_t i = 0; i < sizeof(studentData) / sizeof(studentData[0]); i++){
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for(size_t i = 0; i < 5; i++){
        std::string currStudentId = classRoster.classRosterArray[i]->getStudentID();
        classRoster.printAverageDaysInCourse(currStudentId);
    }
    classRoster.printByDegreeProgram(SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    return 0;
}