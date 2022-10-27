#include "MyList.h"

int main()
{
	MyList list;

	list.viewList();

	list.putItem(10);
	list.putItem(11);
	list.putItem(55);
	list.putItem(7);
	list.putItem(60);
	list.putItem(1002);
	list.viewList();
	std::cout << std::endl;
	list.deleteItem(11);
	list.viewList();

	return 0;
}