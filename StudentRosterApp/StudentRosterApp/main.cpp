#include <iostream>
#include "roster.h"

int main() {
    const string studentData[] =
    { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Justin,Hall,jha1203@wgu.edu,29,4,9,2,SOFTWARE"
    };

    const int numStudents = 5;
    Roster roster;

    cout << "Course: C187 Scripting and Programming Applications" << std::endl << "Programming Language: C++" << std::endl << "Student ID: jha1203" << std::endl << "Name: Justin Hall" << std::endl << std::endl;

    for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);

    cout << "Showing all students: " << std::endl;
    roster.printAll();

    for (int i = 0; i < 3; i++) {
        cout << "Displaying student by degree program: " << degreeProgramAsString[i] << std::endl;
        roster.printByDegreeProgram((DegreeProgram)i);
    }

    cout << "Displaying invalid emails: " << std::endl;
    roster.printInvalidEmails();
    cout << endl;

    cout << "Displaying average days in class: " << std::endl;
    for (int i = 0; i < numStudents; i++) {
        roster.printAverageDaysic(roster.studentRosterArray[i]->getSID());
    }

    cout << "Removing student with SID A3:" << std::endl; 
    roster.removeStudentByID("A3");
    cout << std::endl;
    roster.printAll();

    system("pause");
    return 0;
}