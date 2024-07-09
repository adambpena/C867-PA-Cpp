#include <iostream>
#include "student.h" 

int main(int argc, char const *argv[])
{
    const std::string studentData[] =
        {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
         "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
         "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
         "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
         "A5,Adam,Pena,apen166@wgu.edu,29,15,30,45,SOFTWARE" }; // Create an array of days to complete courses
    int days[3] = {30, 45, 60};

    // Create a Student object
    Student student("A123", "John", "Doe", "john.doe@example.com", 20, days, DegreeProgram::SOFTWARE);

    // Print the student's details
    student.print();
    return 0;
}