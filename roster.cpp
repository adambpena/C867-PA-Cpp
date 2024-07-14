#include <iostream>
#include <regex>
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

Roster::Roster() {
    // Initialize classRosterArray with nullptrs to keep track of empty spots
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
        classRosterArray[i] = nullptr;
    }
}

Roster::~Roster() {
    for (int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
        if(classRosterArray[i] != nullptr){
            delete classRosterArray[i];
            classRosterArray[i] = nullptr;
        }
    }
}

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
    // cout << studentId << firstName << lastName << emailAddress << age << daysInCourse1 << daysInCourse2 << daysInCourse3 << degreeProgram;
    int daysToComplete[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    Student *studentToAdd = new Student(studentId, firstName, lastName, emailAddress, age, daysToComplete, degreeProgram);
    int addAt = -1;
    for(int i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        if(classRosterArray[i] == nullptr){
            addAt = i;
            break;
        };
    }

    if(addAt > -1){
        classRosterArray[addAt] = studentToAdd;
    }
};

void Roster::remove(std::string studentId){
    bool studentFound = false;
    for(size_t i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        if(classRosterArray[i] != nullptr){
            std::string foundId = classRosterArray[i]->getStudentID();
            if(foundId == studentId){
                delete classRosterArray[i];
                classRosterArray[i] = nullptr;
                studentFound = true;
                break;
            }
        }
    }

    if(!studentFound){
        std::cout << "Student with the ID " << studentId << " was not found for removal.\n";
    }
}

void Roster::printAll(){
    for(size_t i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        if(classRosterArray[i] != nullptr){
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAverageDaysInCourse(std::string studentId){
    double sum = 0.0;
    for(size_t i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        std::string foundId = classRosterArray[i]->getStudentID();
        if(foundId == studentId){
            const int *daysArr = classRosterArray[i]->getDaysToComplete();
            for(size_t j = 0; j < sizeof(daysArr) / sizeof(daysArr[0]); j++){
                sum += static_cast<double>(daysArr[j]);
            }
        }
    }
    double avg = sum / 3.0;
    std::cout << "Student ID: " << studentId << ", average days in course is: " << static_cast<int>(avg) << "\n";
}

void Roster::printInvalidEmails(){ // Traverse through class roster and use Regex validation to validate. Return invalid emails
    const std::regex emailPattern(R"(^[\w.%+-]+@[a-zA-Z\d.-]+\.[a-zA-Z]{2,}$)"); // Regex to match email style string with no space, an @ symbol, and a .
    for(size_t i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        std::string studentEmail = classRosterArray[i]->getEmailAddress();
        if(!std::regex_match(studentEmail, emailPattern)){
            std::cout << studentEmail << "\n";
        }
    }

}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram){ // Call print method of students in roster w/ matching degree program
    bool studentFound = false;
    for(size_t i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); i++){
        DegreeProgram studentDegree = classRosterArray[i]->getDegreeProgram();
        if(studentDegree == degreeProgram){
            classRosterArray[i]->print();
            studentFound = true;
        }
    }
    
    if(!studentFound){
        std::cout << "No student with this degree is on the roster";
    }

}