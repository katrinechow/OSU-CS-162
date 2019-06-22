/*******************************************************************************
** Program Name: Lab 9 - Stack and Queue STL Containers: palindrome.cpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the implementation of the palindrome stack, which creates
**		a palindrome of user-entered string.
*******************************************************************************/
#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
#include "palindrome.hpp"

using std::reverse;
using std::string;
using std::stack;
using std::cout;
using std::cin;
using std::endl;
using std::getline;

/*******************************************************************************
**			Palindrome::Palindrome()
** Description:	This is the default constructor of class Palindrome, which
**		initializes data members.
*******************************************************************************/
Palindrome::Palindrome()
{
	slength = 0;
	plength = 0;
}


/*******************************************************************************
**			Palindrome::printString();
** Description:	This function asks user to input a string for processing.
*******************************************************************************/
string Palindrome::printString()
{
	cout << "Enter a string: " << endl;
	getline(cin, userinput);

	slength = userinput.length();

	while(slength == 0)
	{
		cout << "Please enter a string to proceed:" << endl;
		getline(cin, userinput);
		slength = userinput.length();
	}

	//Add chars to palindrome stack
	for (int i = 0; i < slength; i++)
	{
		pstack.push(userinput.at(i));
	}

	//Reverse the string to bypass having to traverse stack
	for (int n = slength - 1; n >= 0; n--)
	{
		reversed = reversed + userinput.at(n);
	}
	//Copy chars to original stack
	for (int i = 0; i < slength; i++)
	{
		ogstack.push(reversed.at(i));
	}

	//double slength since palindrome will have double size as word
	plength = slength * 2;

	//Create palindrome string
	for(int k = 0; k < slength; k++)
	{
		palindrome = palindrome + ogstack.top();
		ogstack.pop();
	}

	for(int k = 0; k < slength; k++)
	{
		palindrome = palindrome + pstack.top();
		pstack.pop();
	}


	//Print Palindrome
	cout << endl;
	cout << "Palindrome is: " << endl;
	cout << palindrome << endl;
	cout << endl;

	return palindrome;
}

