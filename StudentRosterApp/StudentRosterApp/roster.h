#pragma once
#include "student.h"
#ifndef ROSTER_H 
/* your original code */
#else
#define ROSTER_H
#endif

class Roster {
public:
    int lastIndex = -1;
    const static int numStudents = 5;
    Student* studentRosterArray[numStudents];

public:
    void parse(string row);
    void add(string sSID,
        string sFname,
        string sLname,
        string sEmail,
        int sAge,
        int sDaysic1,
        int sDaysic2,
        int sDaysic3,
        DegreeProgram sDegree);
    void printAll();
    void printByDegreeProgram(DegreeProgram sDegree);
    void printInvalidEmails();
    void printAverageDaysic(string sid);
    bool removeStudentByID(string sid);
    ~Roster();
};