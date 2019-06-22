/*******************************************************************************
** Program Name: Lab 9 - Stack and Queue STL Containers: main.cpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the main driver code for the stl program. Users can
**		select from 2 options. Start a buffer simulation which will run
**		through STL Queue container functions. Create a palindrome
**		will use a STL stack container to output palindrome of string
**		back to screen.
*******************************************************************************/
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>

#include "menu.hpp"
#include "buffer.hpp"
#include "palindrome.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

using namespace Menu;

int main()
{
	const char MENU1MAX = '3';
	char ch = '1';

	//Seeding randomizer
	srand(time(0));

	//Display initial menu
	Menu::displayMenu1();
	char choice = Menu::getChoice(MENU1MAX);

	switch(choice)
	{
		case '1':
		{
			//Start Buffer Simulation
			Buffer b;
			b.setRound();
			int r = b.getRound();

			for (int i = 0; i < r; i++)
			{
				cout << endl;
				cout << "Round " << i+1 << ": " << endl;
				cout << endl;
				b.setN();
				b.setAppend();
				b.setRemove();
				b.avgLength(i+1);
				b.printBuffer();
			}
			break;
		}
		case '2':
		{
			//Start Palindrome Function
			Palindrome p;
			//Specs asked to return string
			string output = p.printString();
		
			break;
		}
		case '3':
		{
			return 0;
		}
	}


	return 0;
}
