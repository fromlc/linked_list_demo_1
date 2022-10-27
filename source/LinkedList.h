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

	void addItem(int);		//place new node at begining of list
	bool deleteItem(int);
	void insertItem(int);
	int viewItem();			//return current position item

	Node* getDataPosition(int data);
	void gotoHead();
	Node* gotoNext();

	bool isEmpty();
	void makeEmpty();

	~LinkedList();
};
#endif