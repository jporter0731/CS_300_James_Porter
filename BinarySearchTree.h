#pragma once
#include <string>
#include <vector>
#include "Course.h"

//This class provides the baseline for the Binary Search Tree
#ifndef BINARYSEARCHTREE_H
#define BINSARYSEARCHTREE_H

class BinarySearchTree
{
	//Structure for the node info
	struct Node {
		Course course;
		Node* rightLeaf;
		Node* leftLeaf;

		//Default constructor
		Node() {
			rightLeaf = nullptr;
			leftLeaf = nullptr;
		}

		//Initialize with a course
		Node(Course courseToAdd) {
			course = courseToAdd;
			rightLeaf = nullptr;
			leftLeaf = nullptr;
		}
	};

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();
	void Delete(Node* node);
	void InOrder();
	void Insert(Course course);
	Course Search(string courseID);
	string toLower(string courseID);
private:
	Node* root;
	
	void addNode(Node* node, Course course);
	void inOrder(Node* node);
};

#endif