#include "Course.h"
#include <iostream>

//Default course constructor
Course::Course() {
	courseID = "AAA###";
	courseName = "No course";
}

//Override course constructor
Course::Course(string id, string name) {
	courseID = id;
	courseName = name;
}

//Set the course name to the value passed to the function
void Course::setCourseID(string id) {
	courseID = id;
}

//Return the course ID
string Course::getCourseID() {
	return courseID;
}

//Set the course name to the value passed to the function
void Course::setCourseName(string name) {
	courseName = name;
}

//Return the course name
string Course::getCourseName() {
	return courseName;
}

//Add a new prerequisite to the prerequisite list
void Course::addPrerequisite(string prerequisite) {
	prerequisites.push_back(prerequisite);
}

//Retrun a string containing a list of the course prerequisites 
string Course::getPrerequisites() {
	string printString;
	//increment through the list of prerequisites and add them to the string to print
	for (unsigned int i = 0; i < prerequisites.size(); ++i) {
		printString += prerequisites.at(i);
		if (i + 1 != prerequisites.size()) {
			printString += ", ";
		}
	}
	return printString;
}

//This function prints out the details of each course
void Course::printCourse() {
	if (prerequisites.size() == 0) {
		cout << courseID << ", " << courseName << endl;
	}
	else {
		cout << courseID << ", " << courseName << ", " << this->getPrerequisites() << endl;
	}
}