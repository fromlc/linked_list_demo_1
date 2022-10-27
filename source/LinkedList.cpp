//------------------------------------------------------------------------------
// LinkedList.cpp : class definition
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
  	Node *temp = new Node(input);

	temp->next = head;
	head = temp;

	if (Position == nullptr)
		restart();
}

//------------------------------------------------------------------------------
// delete list node containing passed input value
//------------------------------------------------------------------------------
void LinkedList::DeleteItem(int input) {
	Node *temp = getlocation(input);
	
	temp->data = temp->next->data;
	Position = temp;
	temp = temp->next;
	Position->next = temp->next;

	delete temp;
}

//------------------------------------------------------------------------------
// view the list item pointed to by Position
//------------------------------------------------------------------------------
int LinkedList::ViewItem() {
	if(Position!=nullptr)
		return Position->data;

	std::cerr << "Position is nullptr" << std::endl;
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
// returns pointer to node containing passed input value
//------------------------------------------------------------------------------
Node* LinkedList::getlocation(int input) {
	restart();
	bool found = false;

	while (Position != nullptr && found == false)
	{
		if (Position->data != input)
			found = true;

		iterate();
	}

	return Position;
}

//------------------------------------------------------------------------------
// reset Position to list head
//------------------------------------------------------------------------------
void LinkedList::restart() {
	Position = head;
}

//------------------------------------------------------------------------------
// LinkedList.h class declaration and definition
//------------------------------------------------------------------------------
void LinkedList::MakeEmpty() {

	if (!isEmpty()) {
		Node* temp = head;
		restart();
		bool endOfList = true;

		while (endOfList) {
			temp = Position;
			endOfList = iterate();
			delete temp;
		} 

		head = nullptr;
	}

}

//------------------------------------------------------------------------------
// advance Position pointer one node
//------------------------------------------------------------------------------
bool LinkedList::iterate() {
	if (Position != nullptr) {
		Position = Position->next;
		return true;
	}
	//means I could not iterate
	return false;
}

//------------------------------------------------------------------------------
// destructor
//------------------------------------------------------------------------------
LinkedList::~LinkedList() { MakeEmpty(); }
