//------------------------------------------------------------------------------
// LinkedList class declaration, Node class declaration and definition
//------------------------------------------------------------------------------
#pragma once

#include <iostream>

//------------------------------------------------------------------------------
// Node
//------------------------------------------------------------------------------
class Node {
public:
	int data;
	Node* next;

	// constructors
	Node() : Node(0) {}

	Node(int input) {
		data = input;
		next = nullptr;
	}
};

//------------------------------------------------------------------------------
// LinkedList
//------------------------------------------------------------------------------
class LinkedList {
	Node* head;
	Node* Position;

public:
	LinkedList();

	void putItem(int);		//place new node at begining of list
	void DeleteItem(int);
	int ViewItem();			//return current position item

	bool isEmpty();
	Node* getlocation(int);
	void restart();
	void insert(int);
	bool iterate();
	void MakeEmpty();

	~LinkedList();
};

