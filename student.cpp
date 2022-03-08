#include "student.h"
//Create Student Constructors 
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	for (int i = 0; i < daysInCourse; ++i) {
		this->days[i] = 0;
	}
	this->degree = DegreeProgram::SECURITY;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[daysInCourse], DegreeProgram degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	this->degree = degree;
	for (int i = 0; i < daysInCourse; ++i) {
		this->days[i] = days[i];
	}
}
//Create Student Destructor
Student::~Student() {}

//Create getters
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this->email;
}
int Student::getAge() {
	return this->age;
}
const int* Student::getDays() {
	return this->days;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degree;
}

//Create setters
void Student::setStudentID(string ID) {
	this->studentID = ID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDays(const int days[]) {
	for (int i = 0; i < daysInCourse; ++i) {
		this->days[i] = days[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degree) {
	this->degree = degree;
}
//void Student::printStudent() {
//	cout << "Student ID:\t";
//	cout << "First Name:\t";
//	cout << "Last Name:\t";
//	cout << "Email:\t";
//	cout << "Age:\t";
//	cout << "Course I:\t";
//	cout << "Course II:\t";
//	cout << "Course III:\t";
//	cout << "Degree Program:\t";
//	cout << endl;
//}

void Student::print() {
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->email << '\t';
	cout << this->age << '\t';
	cout << this->days[0] << '\t';
	cout << this->days[1] << '\t';
	cout << this->days[2] << '\t';
	cout << stringForDegreeProgram[(int)this->degree];
	cout << endl;
}
