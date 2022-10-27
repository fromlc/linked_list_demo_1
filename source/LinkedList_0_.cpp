#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
	Position = head;
}

void LinkedList::putItem(int input)
{

	Node *temp = new Node(input);

	temp->tail = head;
	head = temp;

	if (Position == nullptr)
		restart();

}

void LinkedList::DeleteItem(int input)
{
	Node *temp = getlocation(input);
	
	temp->data = temp->tail->data;
	Position = temp;
	temp = temp->tail;
	Position->tail = temp->tail;

	delete temp;
}


int LinkedList::ViewItem()
{
	if(Position!=nullptr)
		return Position->data;

	std::cerr << "Position is nullptr" << std::endl;
	return 0;
}

bool LinkedList::isEmpty()
{
	if (head == nullptr)
		return true;

	return false;
}

Node * LinkedList::getlocation(int input)
{
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

void LinkedList::restart()
{
	Position = head;
}

void LinkedList::iterate()
{
	Position = Position->tail;
}

LinkedList::~LinkedList()
{
}
