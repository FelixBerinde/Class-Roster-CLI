// Class_Roster_Project_Felix_Berinde.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
#include "roster.h"
using namespace std;

int main()
{
	//Print out course title, the programming language used, your WGU student ID and name.
	cout << "Scripting and Programming Applications - C867" << endl;
	cout << "Programming language used: C++" << endl;
	cout << "Student ID: #002333527" << endl;
	cout << "Created By: Felix Berinde" << endl;
	cout << endl;

	//Modify studentData table to include my personal infomation as the last item
	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	  "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Felix,Berinde,fberind@wgu.edu,27, 30, 45, 60,SOFTWARE"
	};

	Roster classRoster;
	for (int i = 0; i < 5; ++i) {
		classRoster.parse(studentData[i]);
	}

	cout << "Displaying all students: " << endl;

	classRoster.printAll();

	cout << endl;
	cout << "Displaying all invalid emails: " << endl;
	cout << endl;


	classRoster.printInvalidEmails();

	cout << endl;
	cout << "Displaying students average amount of days to complete three courses by studentID: " << endl;

	//loop through classRosterArray and for each element:
	for (int i = 0; i < 5; ++i) {
		classRoster.printAverageDaysInCourse(classRoster.getStudent(i)->getStudentID());
	}

	cout << endl;

	//Note: For the current_object's student id, use an accessor (i.e., getter) for the classRosterArray to access the student id.

	cout << "Displaying all students in degree program: SOFTWARE" << endl;
	cout << endl;

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;
	cout << "Attempting to remove student A3: " << endl;

	classRoster.remove("A3");

	cout << endl;

	cout << "Displaying all students: " << endl;

	classRoster.printAll();

	cout << endl;
	cout << "Attempting to remove student A3: " << endl;
	classRoster.remove("A3");
	cout << endl; //expected: the above line should print a message saying such a student with this ID was not found.
	
	cout << "Firing off destructors: " << endl;
	classRoster.~Roster();
}
