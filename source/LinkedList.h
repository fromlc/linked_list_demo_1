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

public:
	LinkedList();

	void putItem(int);		//place new node at begining of list
	void deleteItem(int);
	int viewItem();			//return current position item

	bool isEmpty();
	Node* getPosition(int);
	void gotoHead();
	void insertItem(int);
	Node* gotoNext();
	void makeEmpty();

	~LinkedList();
};
#endif