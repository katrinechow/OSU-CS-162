/*********************************************************************
** Program: Predator prey game
** Author: Group 48
** Date: Feb 5, 2018
** Description: Menu class implementation
*********************************************************************/
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
#include "menu.hpp"
using std::cout;
using std::cin;
using std::endl;

/*********************************************************************
 * Description: Empty constructor
 * ******************************************************************/
Menu::Menu() {
    
}

/*********************************************************************
 * Description: Welcomes the user to the game, informs them that we
 * did the extra credit.
 * ******************************************************************/

void Menu::welcome()
{
    cout << "**Please note, we did the extra credit.**" << endl;
    cout << "Welcome to the predator-prey game!" << endl;
    cout << "This is a battle of survival of two species." << endl;
    cout << "Good luck to both sides." << endl;
}

/*********************************************************************
 ** Description: Function prompts the user for input to configure the 
 * game. It has a parameter list which has the initial message. 
 *********************************************************************/

int Menu::userRows() {
    cout << "How many rows would you like the grid to have?" << endl;
    int startRows = validateInteger(1, 40);   
    return startRows;
}

int Menu::userCols() {
    cout << "How many columns would you like the grid to have?" << endl;
    int startCols = validateInteger(1, 40); 
    return startCols;
}

int Menu:: userAnts() {
    cout << "How many ants would you like the simulation to start with?" << endl;
    int startAnts = validateInteger(1, 500);
    return startAnts;
}

int Menu::userDBugs() {
    cout << "How many doodlebugs would you like the simulation to start with?" << endl;
    int startDoodlebugs = validateInteger(1, 25);
    return startDoodlebugs;
}

int Menu::continueGame() {
    cout << "Would you like to continue the game or exit the program?\n" << endl;
    cout << "1. Continue" << endl;
    cout << "2. Exit" << endl;
    
    int continueChoice = validateInteger(1, 2);
    if(continueChoice == 2) {
        return 2;
    }
    else if(continueChoice == 1) {
        //game continues through the while loop
        return 1;
    }
    return 0;
}

int Menu::userTimeSteps() {
    cout << "How many steps would you like the bugs to take?" << endl;
    int bugSteps = validateInteger(0, 1000);
    return bugSteps;
}


/******************************************************************************
* Description: ValidateInput  function takes two  int paramaters and verifies 
* the input given is between these values and not  a string or other unwanted 
* data.
******************************************************************************/


int Menu::validateInteger(int low, int high)
{
	int input;

	while (!(cin >> input) || (input < low) || (input > high) || cin.peek() != '\n')
	{
		cout << "Please enter an integer between " << low << " and " << high << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	return input;
}






/*********************************************************************
 ** Description: Function validates that the input of the
 * user is a whole number. If user entered an int, it returns the int,
 * otherwise it returns a flag. The flag can be setup to be specific
 * on what the user entered. For example getting the details, whether
 * they entered a string or a float. The function uses built in string
 * function stod (string to digit) it is safely handled by  putting
 * it inside a try/catch clause. Also, using a mod to check that it is
 * not a float/double.
 *********************************************************************/

/*
int Menu::validate(string input)
{
    double choice, intPart, decimalPart;

    //stod implementation from cplusplus.com
    string::size_type sz;

    // validate it is a number using build in method (string to digit)
    try {
        choice = std::stod (input,&sz);
    } catch (...) {
        return -1;
    }

    //check it is int and not a float. Found modf in cplusplus.com
    decimalPart = modf(choice, &intPart);
    if (decimalPart != 0.0)
    {
        return -1;
    }
    
    //returning as int
    return static_cast<int>(intPart);
}*/
