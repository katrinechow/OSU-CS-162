/*********************************************************************
** Program: Predator prey game
** Author: Group 48
** Date: Feb 5, 2018
** Description: Menu class implementation
*********************************************************************/

#include <iostream>
#include <cstdlib>
#include "bugWorld.hpp"

using std::cout;

int main() 
{
     srand(time(NULL));
     
     BugWorld bugWorld;
     
     bugWorld.play();
     
     
     return 0;
    
}