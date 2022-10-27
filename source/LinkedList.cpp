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
	Position = head;
}

//------------------------------------------------------------------------------
// add item, new item becomes list head
//------------------------------------------------------------------------------
void LinkedList::putItem(int input) {
	Node* temp = new Node(input);

	temp->next = head;
	head = temp;

	if (Position == nullptr)
		gotoHead();
}

//------------------------------------------------------------------------------
// delete list node containing passed input value
//------------------------------------------------------------------------------
void LinkedList::deleteItem(int input) {
	Node* temp = getPosition(input);

	temp->data = temp->next->data;
	Position = temp;
	temp = temp->next;
	Position->next = temp->next;

	delete temp;
}

//------------------------------------------------------------------------------
// view the list item pointed to by Position
//------------------------------------------------------------------------------
int LinkedList::viewItem() {
	if (Position != nullptr)
		return Position->data;

	//std::cerr << "Position is nullptr\n";
	return 0;
}

//------------------------------------------------------------------------------
// returns true if list is empty, false otherwise
//------------------------------------------------------------------------------
bool LinkedList::isEmpty() {
	if (head == nullptr)
		return true;

	return false;
}

//------------------------------------------------------------------------------
// returns Position pointer to node containing passed input value
//------------------------------------------------------------------------------
Node* LinkedList::getPosition(int input) {
	gotoHead();
	bool found = false;

	while (Position != nullptr && !found)
	{
		if (Position->data != input)
			found = true;

		gotoNext();
	}
	return Position;
}

//------------------------------------------------------------------------------
// reset Position to list head
//------------------------------------------------------------------------------
void LinkedList::gotoHead() {
	Position = head;
}

//------------------------------------------------------------------------------
// 
//------------------------------------------------------------------------------
void LinkedList::makeEmpty() {

	if (isEmpty())
		return;

	Node* temp = head;
	gotoHead();

	Node* currentItem = nullptr;

	do {
		// save each Position value
		temp = Position;

		// then gotoNext() advances Position to next node on the list
		currentItem = gotoNext();

		// now our Position is the next node, we can
		// delete previous Position's memory
		// the memory deleted is every Node instance
		delete temp;

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
