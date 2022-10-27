//------------------------------------------------------------------------------
// LinkedList class declaration, Node class declaration and definition
//------------------------------------------------------------------------------
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

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
private:
	Node* head;
	Node* Position;
	Node* prevPosition;

public:
	LinkedList();

	void addNode(int);				// add new node at head of list
	bool deleteNode(int);
	void insertNode(int);
	int getCurrentNodeData();		// return current Position item

	Node* getDataPosition(int data);
	void gotoHead();
	Node* gotoNext();

	bool isEmpty();
	void makeEmpty();

	~LinkedList();
};
#endif