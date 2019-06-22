/*********************************************************************
** Program: 
** Author: Group 48
** Date: Feb 5, 2018
** Description: 
*********************************************************************/

#ifndef PREDATOR_PREY_GAME_MENU_HPP
#define PREDATOR_PREY_GAME_MENU_HPP

class Menu 
{
public:
    Menu();
    void welcome();
    int userRows();
    int userCols();
    int userAnts();
    int userDBugs();
    int continueGame();
    int validateInteger(int, int);
    int userTimeSteps();
};

#endif