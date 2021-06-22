#pragma once
#include <string>
#include <vector>
#include <cstring>

#ifndef COURSE_H
#define COURSE_H

using namespace std;

class Course
{
public:
	Course();
	Course(string id, string name);
	void setCourseID(string id);
	string getCourseID();
	void setCourseName(string name);
	string getCourseName();
	void addPrerequisite(string prerequisite);
	string getPrerequisites();
	void printCourse();
private:
	string courseID;
	string courseName;
	vector<string> prerequisites;
};

#endif