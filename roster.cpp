#include "roster.h"
#include <string>

//Create Roster Constructor
Roster::Roster() {}

//Create Roster Destructor
Roster::~Roster() {
	for (int i = 0; i <= last; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
	cout << "Destructors deleted. " << endl;
}

//Create a getstudent function
Student* Roster::getStudent(int i) {
	return classRosterArray[i];
}

//Create parse function
void Roster::parse(string row) {
	DegreeProgram degree = DegreeProgram::NETWORK; //default and check to see if degree ends with y or e for the degreeprogram
	if (row.back() == 'Y') degree = DegreeProgram::SECURITY;
	else  if (row.back() == 'E') degree = DegreeProgram::SOFTWARE;
	string parsed[9];
	int rhs = 0;
	int lhs = 0;
	for (int i = 0; i < 9; ++i) {
		rhs = row.find(",", lhs);
		parsed[i] = row.substr(lhs, rhs - lhs);
		lhs = rhs + 1;
	}
	add(parsed[0], parsed[1], parsed[2], parsed[3], stod(parsed[4]), stod(parsed[5]), stod(parsed[6]), stod(parsed[7]), degree);
}
//Create add function
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	int daysArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++last] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
}

//Create remove function
//Check to see if studentID exists print student not found if it doesnt
void Roster::remove(string studentID) {
	bool removed = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[last--];
			removed = true;
			cout << "Successfully removed student ID: " << studentID << endl;
		}
	}
	if (removed == false) {
		cout << "The following student ID was not found or already removed: " << studentID << endl;
	}
}

//Create printAll function
void Roster::printAll() {
	//Student::printStudent();
	for (int i = 0; i <= Roster::last; ++i) Roster::classRosterArray[i]->print();
}

//Create a print average days in course function where the student is identified by the student id parameter
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::last; ++i) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << studentID << ":";
			cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] + classRosterArray[i]->getDays()[2]) 
				/ 3.0 << endl;
		}
	}
}

//Create a print invalid emails function that checks to see if the students email has an '@' char or a '.' char and does not include spaces
void Roster::printInvalidEmails() {
	for (int i = 0; i <= Roster::last; ++i) {
		string email = classRosterArray[i]->getEmail();
		if (email.find(' ') != string::npos || email.find('@') == string::npos || email.find('.') == string::npos) {
			cout << email << " is invalid!" << endl;
		}
	}
}

//Create a print by degree program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	//Student::printStudent();
	for (int i = 0; i <= Roster::last; ++i) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
	}
}
