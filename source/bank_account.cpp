#include "Account.h"
#include <iostream>

using namespace std;

int menu();
void clearScreen();
void pauseScreen();


int main()
{
	int input = 0;
	Account acct(100.00); //create instance of account

	do
	{
		input = menu();

		switch (input)
		{
		case 1: cout << acct.getBalance();
			pauseScreen();
			break;
		case 2: //ToDo
			break;
		case 3: //ToDo
			break;
		case 4: //ToDo
			break;
		case 5: //ToDo
			break;
		case 6: //ToDo
			cout << "Goodbye";
			pauseScreen();
		}

		clearScreen();
	} while (input != 6);

}

int menu()
{
	int input;
	cout << "Enter the number for th eoperation you wish to perform from the menu." << endl
		<< "1. Check Balance" << endl
		<< "2. Check Current Rate" << endl
		<< "3. Deposit to Account" << endl
		<< "4. Withdraw from Account" << endl
		<< "5. Accrue Interest" << endl
		<< "6. Exit program" << endl << endl;

	cout << "Enter Choice: ";
	cin >> input;

	while (input < 1 or input > 6)
	{
		cout << "Enter a valid Choice from the menu: ";
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		cin >> input;
	}

	return input;
}

void clearScreen()
{
	system("CLS");
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	}
}

void pauseScreen()
{	

	std::cin.clear();
	std::cin.ignore(1000, '\n');
	std::cout << "\n---Enter to Continue!---\n";

	std::cin.get();
}