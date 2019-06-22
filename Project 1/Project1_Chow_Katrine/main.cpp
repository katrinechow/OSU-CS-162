/*******************************************************************************
** Program Name: Project 1: Langton's Ant - main.cpp
** Author: Katrine Chow
** Date: January 15, 2018
** Description: This program simulates Langton's Ant on a user-specified board.
**              The rules stipulate that 1) If ant is on a white space, turn
**              right 90 degrees and change space to black, 2) if ant is on a
**              black space, turn left 90 degrees and change space to white.
**              This program will create the board, keep track of ant's location
**              and orientation, keep track of the color of each tile, and move
**              the ant and change tile colors based on the rules.
*******************************************************************************/

#include "board.hpp"
#include "ant.hpp"
#include "menu.hpp"

#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;

using namespace Menu;

int main()
{
	//Constant menu choice maximum. Easy to change for other programs.
	const char MENU1MAX = '3';
	const char MENU2MAX = '2';
	bool random = false;	
	char ch2 = '1';

	do
	{

		//Display initial menu
		Menu::displayMenu1();
		char choice = Menu::getChoice(MENU1MAX);

		
		//Choice 3 is to quit the program
		switch (choice)
		{
			case '1':
				break;
			case '2': random = true;
				break;
			case '3':
				return 0;
		}


		//Ask user for size of board and create board
		char** boardptr = nullptr;
		int bcol = 0;
		int brow = 0;

		//Board should be at least a 3x3 to allow ant movement
		while(bcol < 3)
		{
			cout << "Please enter number of columns: " << endl;
			cin >> bcol;
		}

		while(brow < 3)
		{
		cout << "Please enter number of rows: " << endl;
		cin >> brow;

		}

		//Create new board to user's specs
		Board newboard(bcol, brow);

		//Sets up a pointer to the new board
		boardptr = newboard.getPointer();

		//Prints the board
		newboard.printBoard(boardptr);

		int acol = 0;
		int arow = 0;

		if (random)
		{
		//Generate random starting location
		acol = rand() % bcol + 1;
		arow = rand() % brow + 1;
		random = false;
		}

		else
		{
			//Ask user for starting location of the ant	
			while(acol < 3 || acol > bcol)
			{
				cout << "Please enter starting column: " << endl;
				cin >> acol;
			}

			while(arow < 3 || arow > brow)
			{
				cout << "Please enter starting row: " << endl;
				cin >> arow;
			}
		}
		
		//Create Ant based on starting location
		Ant ant(acol, arow, boardptr, bcol, brow);
	

		//Initialize starting orientation
		ant.setOrientation(0);

		newboard.printBoard(boardptr);


		//Ask User for number of steps ant should take
		int steps = 0;

		cout << "Please enter number of steps: " << endl;
		cin >> steps;


		//Moving ant according to rules
		int start = 0;

		while (start < steps)
		{
			ant.moveAnt();

			//Prints board after each step
			newboard.printBoard(boardptr);
			
			//Keep moving ant until all steps are exhausted
			start++;
		}

		//Deallocate board
		newboard.deleteBoard(boardptr);

		//Deallocate color array from Ant
		ant.deleteBoard();

		//After the game, ask user continue or quit
		Menu::displayMenu2();
		cin.ignore(); //Flush out the last \n in the buffer

		char ch2 = Menu::getChoice(MENU2MAX);
		
		//2 is to quit
		if (ch2 == '2')
		{
			return 0;
		}

	}while(ch2 == '1');

	
	return 0;
}
