
/*********************************************************************
** Program: Group Project - Predator Prey Game: critter.cpp
** Author: Group 48
** Date: Feb 5 2018
** Description: This is the implementation file for class Critter,
**              which initializes attribute values and defines move,
**              and breed behaviors.
*********************************************************************/

#include <iostream>
#include "critter.hpp"
#include "location.hpp"
#include <cstdlib>

using std::cout;

/*********************************************************************
**                      Critter::Critter()
** Description: This is the default constructor of class Critter.
**              It initializes symbol, timeSteps, and currentStep.
*********************************************************************/
Critter::Critter() : location(Location(-1, -1))
{
    symbol = ' '; //Empty spaces on the grid
    movesMade = 0;
    swapped = false;
    
}


/*********************************************************************
**                      Critter::Critter(Location)
**  Description: This constructor takes a Location parameter and sets
**               Critter object's location with that info.
*********************************************************************/
Critter::Critter(Location locationIn) : location(locationIn)
{
    movesMade = 0;
    symbol = ' ';
}


Critter::Critter(int row, int col) : location(Location(row, col))
{
    
}


/*********************************************************************
**                      Critter::setSymbol(char)
** Description: This sets default symbol for Critter.
*********************************************************************/
void Critter::setSymbol(char s)
{
    symbol = s;
}


/*********************************************************************
**                      Critter::getSymbol
** Description: This gets the Critter's symbol: o for ants, X for
**              doodlebugs.
*********************************************************************/
char Critter::getSymbol()
{
    return symbol;
}



/*********************************************************************
**                      Critter::printSymbol
** Description: This prints the Critter's symbol: o for ants, X for
**              doodlebugs.
*********************************************************************/
void Critter::printSymbol()
{
    cout << symbol;
}

/*********************************************************************
**                      Critter::setLocation(Location)
**  Description: This function sets the Critter's location.
*********************************************************************/
void Critter::setLocation(Location locationIn)
{
    location.row = locationIn.row;
    location.col = locationIn.col;
}


/*********************************************************************
**                      Critter::getLocation()
**  Description: This function returns Critter's location.
*********************************************************************/
Location Critter::getLocation()
{
    return location;
}


/*********************************************************************
**                      Critter::move()
**  Description: Definition of virtual function.
*********************************************************************/

void Critter::move(Critter***, int, int)
{
    cout << "Critter moved\n";
}

/*********************************************************************
**                      Critter::updateLocation(Location)
** Description: This function changes the location of the Critter, to 
* the values passes in the location passed in parameter list.
*********************************************************************/

void Critter::updateLocation(int row, int col)
{
    location.row = row;
    location.col = col;
}


void Critter::breed(Critter***, int, int)
{
    
}

bool Critter::getSwapped()
{
    return swapped;
}


void Critter::setSwapped(bool didSwap)
{
    swapped = didSwap;
}
