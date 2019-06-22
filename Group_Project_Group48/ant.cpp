
/*********************************************************************
** Program: Group Project - Predator Prey Game: ant.cpp
** Author: Group 48
** Date: Feb 5, 2018
** Description: This is the implementation file for class Ant, which
**              includes constructors, getters, setters, and functions
**              that control an Ant's movement.
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "critter.hpp"
#include "ant.hpp"
#include "bugWorld.hpp"


/*********************************************************************
**                      Ant::Ant()
** Description: This is the default constructor of class Ant.
**              It initializes symbol, timeSteps, and currentStep.
*********************************************************************/
Ant::Ant()
{
    symbol = 'o'; //small o to make ants look like tiny prey
    movesMade = 0;
}


/*********************************************************************
**                      Ant::Ant(Location)
** Description: Constructor of class Ant with parameter list that takes
**              in a location to initialize the member variable location
**              of the base class.  It initializes symbol 
**              and movesMade.
*********************************************************************/

Ant::Ant(Location locationIn) : Critter(locationIn)
{
    symbol = 'o'; 
    movesMade = 0;
}


/*********************************************************************
**                      Ant::move()
** Description: This function defines a Ant's movement. The
**              default is to move to an empty, adjacent cell.
*********************************************************************/
void Ant::move(Critter*** gridIn, int rowsIn, int colsIn)
{
    //Create random direction
    int moveDir = rand() % 4 + 1;
    
    //If direction is up and we aren't at top border
    if(moveDir==1 && location.row > 0)
    {
        //If there is an open space, move ant
        if(gridIn[location.row - 1][location.col]->getSymbol() == ' ')
        {
            //change values of row and col for space
            gridIn[location.row -1][location.col]-> updateLocation(getLocation().row, getLocation().col);
            
            //Set ant's current location to point to empty critter location (moved critter to where ant was)
            gridIn[location.row][location.col] = gridIn[location.row -1][location.col];
            
            //Move ant to where critter was
            gridIn[location.row-1][location.col] = this;
            
            //Update location of ant to 1 row up
            location.row--;
            setSwapped(true);
            movesMade++;
            
        }
    }
    
    //If direction is down and we aren't at the bottom border
    else if(moveDir==2  && location.row < (rowsIn - 1))
    {
        //If there is an open space, move ant
        if(gridIn[location.row + 1][location.col]->getSymbol() == ' ')
        {
            //change values of space
            gridIn[location.row +1][location.col] -> updateLocation(getLocation().row, getLocation().col);
            //Set ant's current location to point to empty critter location (moved critter to where ant was)
            gridIn[location.row][location.col] = gridIn[location.row +1][location.col];
            
            //Move ant to where critter was
            gridIn[location.row+1][location.col] = this;
            
            //Update location of ant to 1 row up
            location.row++;
            setSwapped(true);
            
            movesMade++;
            
        }
    }
    
    //If direction is right and we aren't at the right-most border
    else if(moveDir==3 && location.col < colsIn - 1)
    {
        //If there is an open space, move ant
        if(gridIn[location.row][location.col + 1]->getSymbol() == ' ')
        {
            gridIn[location.row][location.col+1]->updateLocation(getLocation().row, getLocation().col);
            //Set ant's current location to point to empty critter location (moved critter to where ant was)
            gridIn[location.row][location.col] = gridIn[location.row][location.col+1];
            
            //Move ant to where critter was
            gridIn[location.row][location.col+1] = this;
            
            //Update location of ant to 1 row up
            location.col++;
            setSwapped(true);
            
            movesMade++;
        }
    }
    
    //If direction is left and we aren't at the left-mst border
    else if(location.col > 0)
    {
        //If there is an open space, move ant
        if(gridIn[location.row][location.col - 1]->getSymbol() == ' ')
        {
            gridIn[location.row][location.col - 1]->updateLocation(getLocation().row, getLocation().col);
            //Set ant's current location to point to empty critter location (moved critter to where ant was)
            gridIn[location.row][location.col] = gridIn[location.row][location.col - 1];
            
            //Update location of critter to 1 col right
            gridIn[location.row][location.col]->updateLocation(location.row, location.col);
            
            //Move ant to where critter was
            gridIn[location.row][location.col - 1] = this;
            
            //Update location of ant to 1 col left
            location.col--;
            setSwapped(true);
            movesMade++;
            
            
        }
    }
    //call breed;
    breed(gridIn, rowsIn, colsIn);
}


/*********************************************************************
**                      Ant::breed()
** Description: This function defines how an Ant breeds. After 3 
** succcesful moves, the ant will breed creating 1 new ant object
** in an adjacent space if there is an open space.
*********************************************************************/
void Ant::breed(Critter*** grid, int rowsIn, int colsIn)
{
      if(movesMade % 3 == 0)
      {
          
        //Create random direction
        int breedDir = rand() % 4 + 1;
    
        //If up
        if(breedDir==1 && location.row > 0)
        {
            //If there is an open space and we aren't at the row next to the top border
            if(grid[location.row - 1][location.col]->getSymbol() == ' ')
            {
                //Create a new ant here
                Ant* babyAnt = new Ant(Location(location.row - 1, location.col));
                grid[location.row - 1][location.col] = babyAnt;
            }
        }
    
        //If down
        else if(breedDir==2 && location.row < rowsIn - 1)
        {
            //If there is an open space and we aren't at the row next to the bottom border
            if(grid[location.row + 1][location.col]->getSymbol() == ' ') 
            {
                //Create a new ant here
                Ant* babyAnt = new Ant(Location(location.row + 1, location.col));
                grid[location.row + 1][location.col] = babyAnt;
            }
        }
    
        //If right
        else if(breedDir==3 && location.col < colsIn - 1)
        {
            //If there is an open space and we aren't at the right-most column
            if(grid[location.row][location.col + 1]->getSymbol() == ' ') 
            {
                //Create a new ant here
                Ant* babyAnt = new Ant(Location(location.row, location.col + 1));
                grid[location.row][location.col + 1] = babyAnt;
            }
        }
    
        //If left
        else if(location.col > 0)
        {
            //If there is an open space and we aren't at the left-most column
            if(grid[location.row][location.col - 1]->getSymbol() == ' ')
            {
                //Create a new ant here
                Ant* babyAnt = new Ant(Location(location.row, location.col - 1));
                grid[location.row][location.col - 1] = babyAnt;
            }
        }
      }
    
}

/********************************************************************
**                      Ant::~Ant()
** Description: This is the destructor of the Ant object
********************************************************************/
/*
Ant::~Ant()
{
    
    
}*/
