/*******************************************************************************
** Program Name: Lab 6 - Doubly-Linked List: m ain.cpp
** Author: Katrine CHow
** Date: February 12, 2018
** Description:	This is the client code of our Doubly-Linked list. This controls
**		the flow of menus and function calls.
*******************************************************************************/
#include <iostream>

#include "node.hpp"
#include "doublylinked.hpp"
#include "menu.hpp"

using namespace Menu;

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const char MENU1MAX = '8';
	char ch = '0';

	//Declares DoublyLinked
	DoublyLinked list;

	do{
		//Display first menu
		Menu::displayMenu1();
		char choice = Menu::getChoice(MENU1MAX);

		//Redirecting various menu choices
		switch (choice)
		{
			case '1':
			{
				int val = Menu::userInput();
				list.addNodeHead(val);
				break;
			}
			case '2':
			{
				int val = Menu::userInput();
				list.addNodeTail(val);
				break;
	
			}
			case '3':
			{
				list.removeNodeHead();
				break;

			}
			case '4':
			{
				list.removeNodeTail();
				break;

			}
			case '5':
			{
				list.reverseList();
				break;
			}
			case '6':
			{
				list.printHValue();
				break;
			}
			case '7':
			{
				list.printTValue();
				break;
			}
			case '8':
				return 0;
		}

		cout << "\n";

	}while(ch == '0');

	return 0;
}
