/*******************************************************************************
** Program Name - Stack and Queue STL Containers: palindrome.hpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the header file for class Palindrome, which contains a
**		STL Stack container that will create a palindrome based on user
**		input.
*******************************************************************************/
#ifndef PALINDROME_HPP
#define PALINDROME_HPP

#include <stack>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::stack;

class Palindrome
{
	private:
		stack< char > pstack;
		stack< char > ogstack;
		string userinput;
		string reversed;
		string palindrome;
		int slength;
		int plength;

	public:
		Palindrome();
		string printString();

};
#endif
