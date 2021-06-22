#include "BinarySearchTree.h"
#include <iostream>
#include <string>
#include <algorithm>

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    root = NULL;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    //Use the delete fruntion to recursively delete every node
    Delete(root);
}

/*
* Delete node function to recursively move through the binary search tree and delete it
*/
void BinarySearchTree::Delete(Node* node) {
    //If the node passed is not null check the next leaves
    if (node != NULL) {
        //If the left node is not null recursively call the Delete function on the left leaf
        if (node->leftLeaf != NULL) {
            Delete(node->leftLeaf);
        }
        //If the left node is not null recursively call the Delete function on the right leaf
        if (node->rightLeaf != NULL) {
            Delete(node->rightLeaf);
        }
        //If the node has no roots delete that node
        delete node;
    }
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    //call the inOrder function on the root
    inOrder(root);
}

//Insert a course into a search tree
void BinarySearchTree::Insert(Course course) {
    //If the root node is null set the course passed to be the root node
    if (root == NULL) {
        Node* newNode = new Node(course);
        root = newNode;
    }
    //Otherwise call the addNode function using the root node
    else {
        addNode(root, course);
    }
}

//Search for a course in the tree
Course BinarySearchTree::Search(string courseID) {
    Node* current = root;
    Course courseToReturn = Course();
    string currentCourse;

    //While the current node is nor null
    while (current != NULL) {
        currentCourse = current->course.getCourseID();
        //If the two course IDs match (ignoring case) return the course found
        if (toLower(currentCourse).compare(toLower(courseID)) == 0) {
            courseToReturn = current->course;
            return courseToReturn;
        }
        //If the current nodes course compared to the course ID passed is greater than 0
        //(If the current course string is greater than the passed string)
        //Move to the next left string
        else if (toLower(currentCourse).compare(toLower(courseID)) > 0) {
            current = current->leftLeaf;
        }
        //If nither of the above is true move to the next right leaf
        else {
            current = current->rightLeaf;
        }
    }
    cout << "Unable to find course " << courseID << "." << endl;
    return courseToReturn;
}

//Add a node to a search tree
void BinarySearchTree::addNode(Node* node, Course course) {
    //If the passed course's ID is less than the node's course ID
    if (node->course.getCourseID() > course.getCourseID()) {
        //If the nodes left leaf is a null pointer add the node
        if (node->leftLeaf == NULL) {
            Node* newNode = new Node(course);
            node->leftLeaf = newNode;
        }
        //Else recursively call the addNode function on the left leaf of the tree
        else {
            addNode(node->leftLeaf, course);
        }
    }

    //If the passed course's ID is greater than the node's course ID
    else {
        //If the nodes right leaf is a null pointer add the node
        if (node->rightLeaf == NULL) {
            Node* newNode = new Node(course);
            node->rightLeaf = newNode;
        }
        //Else recursively call the addNode function on the right leaf of the tree
        else {
            addNode(node->rightLeaf, course);
        }
    }
}

//In order traverse the search tree and print out data
void BinarySearchTree::inOrder(Node* node) {
    //If the node is null return
    if (node == NULL) {
        return;
    }
    //Recurse down the left leaf
    inOrder(node->leftLeaf);
    //Print out data from the node
    node->course.printCourse();
    //Recurse down the right leaf
    inOrder(node->rightLeaf);
}

string BinarySearchTree::toLower(string courseID) {
    //The following 4 lines were pulled from https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/ (June 20, 2021)
    // convert string to back to lower case
    std::for_each(courseID.begin(), courseID.end(), [](char& c) {
        c = ::tolower(c);
     });

    return courseID;
}