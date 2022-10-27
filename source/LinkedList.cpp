//------------------------------------------------------------------------------
// LinkedList.cpp : class definition
// 
// Author: unknown book example, unknown author
// 
// This code is intended as an example for students in my classes.
//------------------------------------------------------------------------------
#include "LinkedList.h"

//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
LinkedList::LinkedList() {

	head = nullptr;
	gotoHead();
}

//------------------------------------------------------------------------------
// reset Position to list head
//------------------------------------------------------------------------------
void LinkedList::gotoHead() {
	Position = head;
	prevPosition = nullptr;
}

//------------------------------------------------------------------------------
// new item becomes list head
//------------------------------------------------------------------------------
void LinkedList::addNode(int data) {
	Node* pNode = new Node(data);

	pNode->next = head;
	head = pNode;

	// before first item Position will be nullptr
	if (Position == nullptr)
		gotoHead();
}

//------------------------------------------------------------------------------
// insert list node containing passed data value
// 
// #TODO
//------------------------------------------------------------------------------
void LinkedList::insertNode(int data) {}

//------------------------------------------------------------------------------
// delete list node containing passed data value
//------------------------------------------------------------------------------
bool LinkedList::deleteNode(int data) {

	Node* pNode = getDataPosition(data);

	// data not found
	if (pNode == nullptr)
		return false;

	// data at list end
	if (pNode->next == nullptr) {
		prevPosition->next = nullptr;
		Position = prevPosition;
	}
	// nodes before and after data
	else if (prevPosition != nullptr) {
		prevPosition->next = pNode->next;
		Position = prevPosition->next;
	}
	// data at list head
	else {
		head = pNode->next;
		gotoHead();
	}

	// release node memory
	delete pNode;

	return true;
}

//------------------------------------------------------------------------------
// returns Position pointer to node containing passed data value
//------------------------------------------------------------------------------
Node* LinkedList::getDataPosition(int data) {

	gotoHead();
	bool found = false;

	while (Position != nullptr && !found) {

		if (Position->data == data) {
			found = true;
			break;
		}

		// keep previous position for easy deleteNode
		prevPosition = Position;

		// advance Position to next node on the list
		gotoNext();
	}
	return Position;
}

//------------------------------------------------------------------------------
// view the list item pointed to by Position
//------------------------------------------------------------------------------
int LinkedList::getCurrentNodeData() {

	if (Position != nullptr)
		return Position->data;

	//std::cerr << "Position is nullptr\n";
	return 0;
}

//------------------------------------------------------------------------------
// returns true if list is empty, false otherwise
//------------------------------------------------------------------------------
bool LinkedList::isEmpty() {

	return (head == nullptr) ? true : false;
}

//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
void LinkedList::makeEmpty() {

	if (isEmpty())
		return;

	gotoHead();
	// if there is a non-zero currentItem, list end has not been reached
	Node* currentItem = nullptr;

	do {
		// save each Position value
		Node* pNode = Position;

		// then gotoNext() advances Position to next node on the list
		currentItem = gotoNext();

		// now our Position is the next node, we can
		// delete previous Position's memory
		// the memory deleted is every Node instance
		delete pNode;

	} while (currentItem != nullptr);

	head = nullptr;
	Position = nullptr;
}

//------------------------------------------------------------------------------
// advances Position pointer to the next node on the list, if possible
// 
// returns 
//		- new Position, when Position did in fact advance
//		- nullptr, when Position is at list end and cannot advance
//------------------------------------------------------------------------------
Node* LinkedList::gotoNext() {

	if (Position != nullptr) {

		Position = Position->next;
		return Position;
	}

	// there is no next: Position points to 0, we are at end of list
	return nullptr;
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
LinkedList::~LinkedList() { makeEmpty(); }
