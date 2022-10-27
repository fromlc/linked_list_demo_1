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
// LinkedList : contains Node as composition
//------------------------------------------------------------------------------
class LinkedList {
private:
	Node* head;
	Node* Position;
	Node* _prevPosition;	// internal use: simplifies node delete

public:
	LinkedList();
	~LinkedList();

	// manage nodes
	void addNode(int data);							// add new node at head of list
	void insertNode(int data);
	bool deleteNode(int matchData);

	// manage Position pointer to current node
	void gotoHead();
	Node* gotoNext();
	bool getCurrentNodeData(int& fillWithData);		// return data at current Position
	Node* getDataPosition(int matchData);

	// manage list 
	bool isEmpty();
	void makeEmpty();	// release each Node's memory
};
#endif