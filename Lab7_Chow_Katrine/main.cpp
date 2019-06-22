/*******************************************************************************
** Program Name: Lab 7 - Circular Linked List: main.cpp
** Author: Katrine Chow
** Date: February 22, 2018
** Description:	This is the client code of the Cicular Linked list. This controls
**		the flow of menus and function calls.
*******************************************************************************/
#include <iostream>

#include "node.hpp"
#include "queue.hpp"
#include "menu.hpp"

using namespace Menu;

using std::cout;
using std::cin;
using std::endl;

int main()
{
	const char MENU1MAX = '5';
	char ch = '0';

	//Declares Queue object
	Queue list;

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
				list.addBack(val);
				break;
			}
			case '2':
			{
				bool empty = list.isEmpty();
			
				if(empty == false)	
				{
					cout << "Front value is: " <<
						list.getFront() << endl;
					break;
				}
	
			}
			case '3':
			{
				list.removeFront();
				break;

			}
			case '4':
			{
				list.printQueue();
				break;

			}
			case '5':
			{
				return 0;
			}
		}

		cout << "\n";

	}while(ch == '0');

	return 0;
}
