#include "roster.h"
#include <regex>
using namespace std;



/* loop for crawling data*/
void Roster::parse(string studentData) {
    DegreeProgram sDegree = UNKNOWN;
    if (studentData.at(1) == '1') sDegree = SECURITY;
    else if (studentData.at(1) == '2') sDegree = NETWORK;
    else if (studentData.at(1) == '3') sDegree = SOFTWARE;
    else if (studentData.at(1) == '4') sDegree = SECURITY;
    else if (studentData.at(1) == '5') sDegree = SOFTWARE;

    int delimR = studentData.find(",");
    string sSID = studentData.substr(0, delimR);

    int delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    string sFname = studentData.substr(delimL, delimR - delimL);

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    string sLname = studentData.substr(delimL, delimR - delimL);

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    string sEmail = studentData.substr(delimL, delimR - delimL);

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    int sAge = stoi(studentData.substr(delimL, delimR - delimL));

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    int sDaysic1 = stoi(studentData.substr(delimL, delimR - delimL));

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    int sDaysic2 = stoi(studentData.substr(delimL, delimR - delimL));

    delimL = delimR + 1;
    delimR = studentData.find(",", delimL);
    int sDaysic3 = stoi(studentData.substr(delimL, delimR - delimL));

    add(sSID, sFname, sLname, sEmail, sAge, sDaysic1, sDaysic2, sDaysic3, sDegree); /*for roster array*/
}

/* object creation */
void Roster::add(string sSID, string sFname, string sLname, string sEmail, int sAge, int sDaysic1, int sDaysic2, int sDaysic3, DegreeProgram sDegree)
{
    int sDaysicarr[3] = { sDaysic1,sDaysic2,sDaysic3 };
    studentRosterArray[++lastIndex] = new Student(sSID, sFname, sLname, sEmail, sAge, sDaysicarr, sDegree);
}


void Roster::printAll() {
    Student::printStuHeader();
    for (int i = 0; i <= Roster::lastIndex; i++)
    {
       (Roster::studentRosterArray)[i]->print();
    }
}

void Roster::printByDegreeProgram(DegreeProgram sDegree) {
    Student::printStuHeader();
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::studentRosterArray[i]->getDegree() == sDegree) studentRosterArray[i]->print();
    }
    cout << std::endl;
}


bool Check_email(string email) {
    const regex p("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, p);
}

void Roster::printInvalidEmails() {
    bool any = false;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = (studentRosterArray[i]->getEmail());
        if (!Check_email(email)) {
            any = true;
            cout << email << " is an invalid email." << std::endl;
        }
        if (!any) cout << "NONE FOUND" << std::endl;
    }
}

void Roster::printAverageDaysic(string sid) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (studentRosterArray[i]->getSID() == sid) {
            cout << sid << ": ";
            cout << (studentRosterArray[i]->getDaysic()[0]
                + studentRosterArray[i]->getDaysic()[1]
                + studentRosterArray[i]->getDaysic()[2]) / 3.0 << std::endl;
        }
    }
    cout << std::endl;
}

bool Roster::removeStudentByID(string sid) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (studentRosterArray[i]->getSID() == sid) {
            if (i < numStudents - 1) {
                Student* temp = studentRosterArray[i];
                studentRosterArray[i] = studentRosterArray[numStudents - 1];
                studentRosterArray[numStudents - 1] = temp;
            }
            cout << sid << " removed from the roster." << std::endl << std::endl;
            Roster::lastIndex--;
            return true;
        }
    }
    cout << sid << " not found." << std::endl << std::endl;
    return false;
}

Roster::~Roster() {
   /* cout << "Cleaning list.." << std::endl << std::endl;*/
    for (int i = 0; i < numStudents; i++) {
       /* cout << "Removing student ID #" << i + 1 << std::endl;*/
        delete studentRosterArray[i];
        studentRosterArray[i] = nullptr;
    }
};