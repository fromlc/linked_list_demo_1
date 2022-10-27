#include <iostream>

using namespace std;

int main()
{
	int x = 1023;

	int z[10] = { 1,2,3,4,5,6,7,8,9,0 };

	cout << z << endl;

	cout << *z << endl;

	cout << &z[2] << endl;

	cout << *(z + 2) << endl;

	int *ptrY = new int();

	*ptrY = 52;

	delete ptrY;

	ptrY = new int();

	cout << "address of x: " << &x << endl;

	int *ptrX = &x;

	cout << "ptrX: " << ptrX << endl;


	cout << "address of ptrX: " << &ptrX << endl;

	cout << "dereference ptrX: " << *ptrX;
	return 0;

}