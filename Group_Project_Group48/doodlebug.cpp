/*********************************************************************
** Program: Group Project - Predator Prey Game: doodlebug.cpp
** Author: Group 48
** Date: Feb 5, 2018
** Description: This is the implementation file for class Doodlebug,
**              which includes constructors, getters, setters, and
**              functions that control the Doodlebug's movement and
**              starve conditions.
*********************************************************************/
#include <cstdlib>
#include <iostream>
#include "critter.hpp"
#include "doodlebug.hpp"


/*********************************************************************
**                      Doodlebug::Doodlebug()
** Description: This is the default constructor of class Doodlebug.
**              It initializes symbol, timeSteps, and currentStep.
*********************************************************************/
Doodlebug::Doodlebug()
{
    symbol = 'X';
    movesMade = 0;
    foodless = 0;
}


/*********************************************************************
**                      Doodlebug::Doodlebug()
** Description: Constructor of class Doodlebug with parameter list that 
**              takes   in a location to initialize the member variable 
**              location of the base class.  It initializes symbol,  
**              and movesMade.
*********************************************************************/

Doodlebug::Doodlebug(Location location) : Critter(location)
{
    symbol = 'X'; 
    movesMade = 0;
    foodless = 0;
}



/*********************************************************************
**                      Doodlebug::move()
** Description: This function defines a Doodlebug's movement. The
**              default is to move to an empty, adjacent cell.
**              Doodlebug's unique rule is to first hop over to a cell
**              that contains an ant and eat it.
*********************************************************************/

void Doodlebug::move(Critter*** gridIn, int rowsIn, int colsIn)
{
    bool ateAnt = false;
    
    //Check up for ants
    
    if ((location.row > 0) && (gridIn[location.row - 1][location.col]->getSymbol() == 'o'))
    {
        Critter* ant = gridIn[location.row][location.col];
        //move the Critter(empty space holder) to the location doodle is leaving
        Critter* critter = new Critter(Location(location.row, location.col));
        gridIn[location.row][location.col] = critter;
        
        //doodle now should be were ant was
        gridIn[location.row - 1][location.col] = this;
        setSwapped(true);
        
        location.row--;
        movesMade++;
        
        foodless = 0;
        ateAnt = true;
        delete ant;
    }
    
    
    //Check down for ants
    else if((location.row < (rowsIn - 1)) &&
            (gridIn[location.row + 1][location.col]->getSymbol() == 'o'))
    {
        Critter* ant = gridIn[location.row][location.col];
        Critter* critter = new Critter(Location(location.row, location.col));
        gridIn[location.row][location.col] = critter;
        
        gridIn[location.row + 1][location.col] = this;
        setSwapped(true);
        
        location.row++;
        movesMade++;
        
        foodless = 0;
        ateAnt = true;
        delete ant;
    }
    
    //Check right for ants
    else if((location.col < colsIn - 1) &&
            (gridIn[location.row][location.col + 1]->getSymbol() == 'o'))
    {
        Critter* ant = gridIn[location.row][location.col];
        Critter*critter = new Critter(Location(location.row, location.col));
        gridIn[location.row][location.col] = critter;
        
        gridIn[location.row][location.col + 1] = this;
        
        location.col++;
        movesMade++;
        
        setSwapped(true);
        ateAnt = true;
        foodless = 0;
        delete ant;
    }
    
    //Check left for ants
    else if((location.col > 0) && (gridIn[location.row][location.col - 1]->getSymbol() == 'o'))
    {
        Critter* ant = gridIn[location.row][location.col];
        Critter* critter = new Critter(Location(location.row, location.col));
        gridIn[location.row][location.col] = critter;
        
        gridIn[location.row][location.col - 1] = this;
        
        location.col--;
        movesMade++;
        
        setSwapped(true);
        ateAnt = true;
        foodless = 0;
        delete ant;
    }
    
    //Otherwise move normally if no ants in adjacent cells
    if (!ateAnt)
    {
        foodless++;
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
        } else if(moveDir==2  && location.row < rowsIn - 1)  //If direction is down and we aren't at the bottom border
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
        } else if(moveDir==3 && location.col < colsIn - 2) //If direction is right and we aren't at the right-most border
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
        } else if(location.col > 0)  //If direction is left and we aren't at the left-mst border
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
    }
    
    starve(gridIn);
    //breed(gridIn, rowsIn, colsIn);
}

/*********************************************************************
**                      Doodlebug::starve()
** Description: This function defines a Doodlebug's starve condition.
**              If a Doodlebug has not eaten an ant in three steps, it
**              will die (removed from grid).
*********************************************************************/
void Doodlebug::starve(Critter*** gridIn)
{
    if (foodless >= 3)
    {
        //Critter* critter = new Critter(location.row, location.col);
        gridIn[location.row][location.col]->setSymbol(32);
    
    }
}



/*********************************************************************
**                      Doodlebug::breed()
** Description: This function defines how a doodlbug breeds. After 8 
** succcesful moves, the ant will breed creating 1 new doodlebug 
** object in an adjacent space if there is an open space.
*********************************************************************/
void Doodlebug::breed(Critter*** grid, int rowsIn, int colsIn)
{
      if(movesMade % 8 == 0)
      {
        
        //Create random direction
        int breedDir = rand() % 4 + 1;
    
        //If up
        if(breedDir==1 && location.row > 0)
        {
            //If there is an open space and we aren't at the row next to the top border
            if(grid[location.row - 1][location.col]->getSymbol() == ' ')
            {
                //create a new doodblebug here
                Doodlebug* babyDoodle = new Doodlebug(Location(location.row - 1, location.col));
                grid[location.row - 1][location.col] = babyDoodle;
            }
        }
        
        //If down
        else if(breedDir==2 && location.row < rowsIn - 1)
        {
            //If there is an open space and we aren't at the row next to the bottom border
            if(grid[location.row + 1][location.col]->getSymbol() == ' ') 
            {
                //Create a new doodlebug here
                Doodlebug* babyDoodle = new Doodlebug(Location(location.row + 1, location.col));
                grid[location.row + 1][location.col] = babyDoodle;
            }
        }
    
        //If right
        else if(breedDir==3 && location.col < colsIn - 1)
        {
            //If there is an open space and we aren't at the right-most column
            if(grid[location.row][location.col + 1]->getSymbol() == ' ') 
            {
                //Create a new doodlebug here
                Doodlebug* babyDoodle = new Doodlebug(Location(location.row, location.col + 1));
                grid[location.row][location.col + 1] = babyDoodle;
            }
        }
    
        //If left
        else if(location.col > 1)
        {
            //If there is an open space and we aren't at the left-most column
            if(grid[location.row][location.col - 1]->getSymbol() == ' ')
            {
                //Create a new doodlebug here
                Doodlebug* babyDoodle = new Doodlebug(Location(location.row, location.col -1));
                grid[location.row][location.col - 1] = babyDoodle;
            }
        }
      }
    
}

/*********************************************************************
 **                      Doodlebug::~Doodlebug()
 ** Description: This is the destructor of the Doodlebug object
 *********************************************************************/
/*
Doodlebug::~Doodlebug()
{
    
}*/

