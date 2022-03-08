#pragma once
#include <string>
#include <iostream>
#include "degree.h"

#ifndef STUDENTH
#define STUDENTH
using namespace std;
//Create the class Student which includes the variables student ID, first name, last name, email address, age, an array of number of days to complete each course and the degree program.
class Student
{
public:
	const static int daysInCourse = 3;
	//Create constructors using all the input parameters provided in the table
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int days[daysInCourse], DegreeProgram degree);
	~Student();
private:
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	int days[daysInCourse];
	DegreeProgram degree;
public:
	//Create accessors (getters)
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	const int* getDays();
	DegreeProgram getDegreeProgram();
	//Create mutators (setters)
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setDays(const int days[daysInCourse]);
	void setDegreeProgram(DegreeProgram degree);
//Create a print function to print specific student data
	static void printStudent();
	void print();
};
#endif