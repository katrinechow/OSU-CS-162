/*******************************************************************************
** Program Name: Lab 5 - Recursive Functions: recursion.cpp
** Author: Katrine Chow
** Date: February 6, 2018
** Description:	This is the implementation file which defines the three
**		recursive functions users may call.
*******************************************************************************/
#include <iostream>
#include <string>

#include "recursion.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

/*******************************************************************************
**			Recursion::runFunction1(string)
** Description:	This function accepts a string and its length, and prints the
**		string back to the user in reverse order.
*******************************************************************************/

void Recursion::runFunction1(string input)
{
	int start = 0;

	//Base case
	if(start == input.length())
	{
		cout << input[start] << endl;
	}

	else
	{
		cout << input[input.length() - 1];
		//Per @309 on Piazza, we can use resize
		input.resize(input.length() - 1);

		runFunction1(input);
	}
}


/*******************************************************************************
**			Recursion::runFunction2(int*, int)
** Description:	This function calculates the sum of an array of integers.
*******************************************************************************/

int Recursion::runFunction2(int* iarray, int elements)
{
	int sum;

	//Base Case
	if (elements == 1)
	{
		sum = iarray[0];
	}

	else if (elements > 1)
	{
		sum = iarray[elements - 1];
		sum = sum + runFunction2(iarray, elements - 1);
	}
	

	return sum;
}


/*******************************************************************************
**			Recursion::runFunction3(int)
** Description:	This function returns the triangular number of user-specified
**		integer.
*******************************************************************************/

int Recursion::runFunction3(int N)
{
	int num;

	if (N == 0)
	{
		num = 0;
	}

	else if (N == 1)
	{
		num = 1;
	}

	else if (N > 1 && N <= 1000)
	{
		num = N + runFunction3(N-1);
	}

	return num;
}
