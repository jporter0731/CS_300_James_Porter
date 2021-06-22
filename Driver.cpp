#include "BinarySearchTree.h"
#include "Course.h"
#include <iostream>
#include <conio.h>
#include <fstream>

void LoadData() {
	

	
}

//Driver class to run the program and get information
int main() {
	//Instance variable used to run the program and functions below
	BinarySearchTree searchTree;
	int choice = 0;
	string searchChoice;
	Course tempCourse;

	//Instance variables needed to read data from file
	ifstream courseList;
	Course courseToAdd;
	string tempLine;
	string tempCourseID;
	string tempCourseName;
	string tempPrerequisites;
	int delimiterLocation;

	//While the user doesn't choose option 4 (the exit option) do the following
	while (choice != 4) {
		try {
			//Pint out the main menu
			cout << "Welcome to the course planner." << endl << endl;
			cout << "1: Load Data" << endl;
			cout << "2: Print Course List" << endl;
			cout << "3: Find Course" << endl;
			cout << "4: Exit" << endl << endl;
			cout << "What would you like to do?" << endl;
			cin >> choice;

			//Switch section to determine what code to run
			switch (choice)
			{
			//Case 1 loads the data passed from a file (For testing courses.txt) to a binary search tree
			case 1:
				cout << "Loading Data..." << endl;
				//Loads data using the function below
				//Open file
				courseList.open("Courses.txt");

				//Check that file is able to open
				if (!courseList.is_open()) {
					//This section clears the input stream so we don't have excessive loops
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					//This throws an error
					throw runtime_error("Unable to open file.");
				}
				//If the file is open read the data from the file
				else {
					//While there is still another line in the file do the following
					do {
						//Get the line 
						getline(courseList, tempLine);
						//Get the course ID from the line
						delimiterLocation = tempLine.find_first_of(',');
						tempCourseID = tempLine.substr(0, delimiterLocation);
						tempLine = tempLine.substr(delimiterLocation + 1, tempLine.size() - delimiterLocation);
						//Get the course name from the remainder of the line
						delimiterLocation = tempLine.find_first_of(',');
						//If there are no prerequisites (i.e. the location of the next delimiter is -1) do the following
						if (delimiterLocation == -1) {
							tempCourseName = tempLine;
						}
						//Otherwise reduce the size of the string remaining again
						else {
							tempCourseName = tempLine.substr(0, delimiterLocation);
							tempLine = tempLine.substr(delimiterLocation + 1, tempLine.size() - delimiterLocation);
						}
						//Create a course using the data read from the file
						courseToAdd = Course(tempCourseID, tempCourseName);
						//While there is still data to be read add that information as prerequisites
						while (delimiterLocation != -1) {
							delimiterLocation = tempLine.find_first_of(',');
							tempPrerequisites = tempLine.substr(0, delimiterLocation);
							courseToAdd.addPrerequisite(tempPrerequisites);
							tempLine = tempLine.substr(delimiterLocation + 1, tempLine.size() - delimiterLocation);
						}
						searchTree.Insert(courseToAdd);
					} while (!courseList.eof());
				}
				cout << "Finished loading data!" << endl;
				//Waits for the user to hit a button on the keyboard to continue
				cout << "Press any button to continue..." << endl;
				while (!_kbhit()) {

				}
				//Clears the output screen
				system("CLS");
			//Case 2 prints the entire list of courses in alphanumeric order from the search tree
			case 2:
				cout << "Here is a sample schedule:" << endl;
				//Prints the data from the search tree in alphanumeric order
				searchTree.InOrder();
				//Waits tell a user presses a button on the keyboard to continue
				cout << "Press any button to continue..." << endl;
				while (!_kbhit()) {

				}
				//Clear the output screen of data
				system("CLS");
				break;
			//Case 3 has the user search for a course and prints that course information out
			case 3:
				//Prompts the user to enter the course that they are looking for and saves that course in a string file
				cout << "What course do you want to know about?" << endl;
				cin >> searchChoice;
				//Searches for the course saved from the user in the search tree
				tempCourse = searchTree.Search(searchChoice);
				//Checks if valid course (not AAA###) and prints only valid courses
				if (tempCourse.getCourseID() != "AAA###") {
					cout << tempCourse.getCourseID() << ", " << tempCourse.getCourseName() << endl;
					if (tempCourse.getPrerequisites() == "") {
						cout << "Prerequisites: " << "NONE" << endl;
					}
					else {
						cout << "Prerequisites: " << tempCourse.getPrerequisites() << endl;
					}
				}
				//Waits for the user to press a button on the keyboard to continue
				cout << "Press any button to continue..." << endl;
				while (!_kbhit()) {

				}
				//Clears the output screen
				system("CLS");
				break;
			//Course 4 exits the program when entered
			case 4:
				cout << "Thank you for using the course planner!" << endl;
				break;
			//The default case throws any errors to the catch block when typing in input
			default:
				//This section clears the input stream so we don't have excessive loops
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				//This throws the error
				throw runtime_error("Invalid selection! \nPlease try again.");
				break;
			}
		}
		//Catch block catches all errors and prints a prompt warning the user that they have entered invalid data
		catch (runtime_error& excep1) {
			//Clears the screen
			system("CLS");
			//Prints the error found
			cout << excep1.what() << endl << "Press any button to continue." << endl;
			//Does not continue until the user hits some button on the keyboard
			while (!_kbhit()) {

			}
			//Clears the output screen
			system("CLS");
		}
	}
}