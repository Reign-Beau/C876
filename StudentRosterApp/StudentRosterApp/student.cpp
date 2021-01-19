#include "student.h"

Student::Student() /*paramless, constructor*/
{
    this->sid = "";
    this->fname = "";
    this->lname = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < daysicArraySize; i++) this->daysic[i] = 0;
    this->degree = DegreeProgram::UNKNOWN;
};

Student::Student(string sid, string fname, string lname, string email, int age, int daysic[], DegreeProgram degree)
{
    this->sid = sid;
    this->fname = fname;
    this->lname = lname;
    this->email = email;
    this->age = age;
    for (int i = 0; i < daysicArraySize; i++) this->daysic[i] = daysic[i];
    this->degree = degree;
}

/*accessors*/
string Student::getSID() { return this->sid; }
string Student::getFname() { return this->fname; }
string Student::getLname() { return this->lname; }
string Student::getEmail() { return this->email; }
int Student::getAge() { return this->age; }
int* Student::getDaysic() { return this->daysic; }
DegreeProgram Student::getDegree() { return this->degree; }

// /*mutators*/
void Student::setSID(string SID) { this->sid = SID; }
void Student::setFname(string fname) { this->fname = fname; }
void Student::setLname(string lname) { this->lname = lname; }
void Student::setEmail(string email) { this->email = email; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysic(int daysic[]) {
    for (int i = 0; i < daysicArraySize; i++) this->daysic[i] = daysic[i];
}
void Student::setDegree(DegreeProgram degree) { this->degree = degree; }

void Student::printStuHeader() {
    cout << "ID |   First   |   Last   |        Email       | Age |Days in course: 1 | 2 | 3 | Degree Program\n";
}

void Student::print() {
    cout << this->getSID() << '\t';
    cout << this->getFname() << '\t';
    cout << this->getLname() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDaysic()[0] << '\t';
    cout << this->getDaysic()[1] << '\t';
    cout << this->getDaysic()[2] << '\t';
    cout << degreeProgramAsString[this->getDegree()] << '\n';
}