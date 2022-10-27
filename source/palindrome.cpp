#include "MyStack.h"
#include <string.h>
#include <stdio.h>

int main()
{
	MyStack m;
	MyStackLL n;

	const char test[] = "racecar";


	for (char value : test)
		n.push(value);

	
	n.pop();//remove null character

	bool isPalindrome = true;

	for (char value : test)
		if (value != n.pop())
			isPalindrome = false;

	if (isPalindrome)
	{
		std::cout << "is palindrome" << std::endl;
	}
	else
	{
		std::cout << "is not palindrome" << std::endl;
	}

	std::cout << n.top() << std::endl;


	return 0;
}