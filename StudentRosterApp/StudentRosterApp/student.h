#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
#ifndef STUDENT_H 
/* your original code */
#else
#define STUDENT_H
#endif

using std::string;
using std::cout;
using std::endl;

class Student {
public:
    const static int daysicArraySize = 3; /*eliminates destructor need*/
private:
    string sid;
    string fname;
    string lname;
    string email;
    int age;
    int daysic[daysicArraySize];
    DegreeProgram degree;
public:
        /*paramless, constructor, destructor*/
    Student();
    Student(string sid, string fname, string lname, string email, int age, int daysic[], DegreeProgram degree);
    // ~Student(); //

    /*accessors*/
    string getSID();
    string getFname();
    string getLname();
    string getEmail();
    int getAge();
    int* getDaysic();
    DegreeProgram getDegree();

    /*mutators*/
    void setSID(string SID);
    void setFname(string fname);
    void setLname(string lname);
    void setEmail(string email);
    void setAge(int age);
    void setDaysic(int daysic[]);
    void setDegree(DegreeProgram degree);

    static void printStuHeader();
    void print();


};