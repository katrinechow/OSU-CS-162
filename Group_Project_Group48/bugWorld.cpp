/*********************************************************************
** Program: Predator prey game
** Author: Group 48
** Date: Feb 5, 2018
** Description: Bug world implementation
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include "bugWorld.hpp"
#include "ant.hpp"
#include "doodlebug.hpp"

using std::cout;
using std::endl;

BugWorld::BugWorld() : gameMenu()
{
   gameMenu.welcome();
   numRows = gameMenu.userRows();
   numCols = gameMenu.userCols();
   numAnts = gameMenu.userAnts();
   numDoodlebugs = gameMenu.userDBugs();
   timeSteps = 0;
   setCritterCount(); 
   // dynamic allocation of a pointer to a critter array
   setGrid();
   
}

BugWorld::~BugWorld()
{
   // deallocation of dynamic array
   

    for (int row= 0; row < numRows; row++)
    {   for (int col = 0; col < numCols; col++)
        {
            delete grid[row][col];
        }
    }
    
    for (int row = 0; row < numRows; row++)
    {
        delete [] grid[row];
    }
    
    delete [] grid;
}


/*********************************************************************
** Description: Setter for member variable grid. 
*********************************************************************/
void BugWorld::setGrid()
{
    Location location;
    
    grid = new Critter** [numRows];
    
    
    for(int i = 0; i < numRows; i++) {
        grid[i] = new Critter*[numCols];
    }
    
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            grid[row][col] = new Critter();
        }
    }
    
    //give locations to Critters within the grid.
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {   
            location.row = row;
            location.col = col;
            
            grid[row][col]->setLocation(location);
             
        }
    }
    
    //create ants
    for (int i = 0; i < numAnts; i++ )
    {
        //use random to get the location of each ant
        location.row = random(numRows-1);
        location.col = random(numCols-1);
        
        //check if the random location is available
        if (!isEmpty(location))
        {   
            //if location not available change to a nearby empty one
            getEmpty(&location);
        } 
        //we have location to pass in the ant constructor
        // add when the ant contructor is ready
        Ant * ant = new Ant(location);
        
        //assign the pointer of the new ant to the critter
        grid[location.row][location.col] = ant;
    }
    
    
    for (int i = 0; i < numDoodlebugs; i++)
    {
        // use random to get the location of doodles
        location.row = random(numRows-1);
        location.col = random(numCols-1);
        
         if (!isEmpty(location))
        {   
            getEmpty(&location);
        } 
        //we have location to pass in the doodleBug constructor
        // add when the doodleBug contructor is ready
        Doodlebug * doodleBug = new Doodlebug(location);
        
        //assigned the pointer of the new doodle to the critter
        grid[location.row][location.col] = doodleBug;

    }
     
}


/*********************************************************************
** Description: Setter for member variable critterCount, which is the
* size of the grid. 
*********************************************************************/
void BugWorld::setCritterCount()
{
    critterCount = numRows * numCols;
}


/*********************************************************************
** Description: function prints the grid as it is in the moment, this
* function should be called after ever time-step. Needs to adapt to
* the fact that the bugs in the array are not in the order they will 
* be printed.
*********************************************************************/


void BugWorld::printGrid()
{   
    sortGrid();
    cout << " ";
    for (int col = 0; col < numCols; col++)
    {
        cout << "____";
        
    }
    cout << endl;
    
    for(int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {   
            if (col == 0)
            {
                cout << "| ";
            }
        
            grid[row][col] -> printSymbol();
            cout << " | ";
        }
        cout << endl;
    }
    cout << " ";
    for (int col = 0; col < numCols; col++)
    {
        cout << "----";
        
    }
    cout << endl;
}


/*********************************************************************
** Description: sort function indexes in the array in the way they 
* need to be printed based on the location they occupy in the grid. 
*********************************************************************/

void BugWorld::sortGrid()
{
    int sorting;
    
    do {
        sorting = 0;
        for (int row = 0; row < numRows; row++)
        {   
            for (int col = 0; col < numCols; col++)
            {
                int sortedRow = grid[row][col]->getLocation().row;
                int sortedCol = grid[row][col]->getLocation().col;
                
                if (grid[row][col] != grid[sortedRow][sortedCol])
                {
                    Critter * temp = grid[sortedRow][sortedCol];
                    grid[sortedRow][sortedCol] = grid[row][col];
                    grid[row][col] = temp;
                    sorting++;
                }
            }
        }
        
    } while (sorting > 0);
}


/*********************************************************************
* Description: Function orchestrates the game
*********************************************************************/


void BugWorld::play()
{
    do {
        timeSteps = gameMenu.userTimeSteps();
        cout << "intial grid ..." << endl;
        printGrid();
        for (int i = 0; i < timeSteps; i++)
        {
            moveBugs('X');
            moveBugs('o');
            cout << "grid after time step " << (i +1) << endl;
            printGrid();
        }
        
        //continue or end game
    } while(gameMenu.continueGame() != 2);
}

/*********************************************************************
* Description: Function moves all critter of whichever symbol passed in
* as a parameter that are in the grid. 
*********************************************************************/

void BugWorld::moveBugs(char symbol)
{   // setSwap
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (grid[row][col]->getSymbol() == symbol)
            {

                grid[row][col]->setSwapped(false);
            }
        }
    }
    
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if (grid[row][col]->getSymbol() == symbol && !grid[row][col]->getSwapped())
            {
                grid[row][col]->move(grid, numRows, numCols);
            }
        }
    }
}


/*********************************************************************
* Description: Function returns a random int from 0 to max
*********************************************************************/

int BugWorld::random(int max)
{
    return rand() % max;
}

/*********************************************************************
* Description: Function checks that the random location passed in
* the parameter list is empty. Iterate over the grid returns a bool
* after checking whether the location is occupied or not.
*********************************************************************/

bool BugWorld::isEmpty(Location location)
{   bool empty = true;
    
    for (int row = 0; row < numRows; row++)
    {
        for (int col = 0; col < numCols; col++)
        {
            if ((grid[row][col]->getLocation() == location))
            {
                //who is in that space? 32 is Ascii for space
                empty = grid[row][col]->getSymbol() == 32;
                //if the TA allows break, break otherwise it doesn't matter
            }
        }
    }
    
    return empty;   
}



/*********************************************************************
* Description:  This helper function, checks that the location is
 inBounds, before calling isEmpty to check if that inbound position
 is empty. The location passed in is a temporary location, holding the
 values of a potential empty location, which already has applied a
 step, since check is being done north, east, south, west, in circles,
 and with a step size, if none of those positions where available then
 it would go on the same coordinates but a step away.
*********************************************************************/

bool BugWorld::checkLocation(Location* empty)
{
    bool emptyFound = false;
    // check position is in bound
    if ((empty->row < numRows && empty -> row >= 0))
    {
        if (empty->col < numCols && empty->col >= 0)
        {
           emptyFound = isEmpty(*empty);
        }
    }

    return emptyFound;    
}

/*********************************************************************
* Description: Function returns an empty location near the passed
* location, this function is called when the isEmpty location returned
* false, since the original location is random, simply finding a nearby
* empty location is random enough to finalize the bugs position
*********************************************************************/

void BugWorld::getEmpty(Location* location)
{
    int step = 1;
    int numCardinal = 4;
    bool emptyFound = false;
    bool fullBoard = false;
    Location emptyLocation(-1, -1);
    
     while (!emptyFound && !fullBoard)
    {
        if (step > numCols && step > numCols )
        {
            fullBoard = true;
            //break; ask TA if it is ok to use break here, else check
            //is being done below
        }
        
        //looping the enum to check all coordinates
        for (int dir = 0; dir < numCardinal; dir++)
        {   if (!emptyFound && !fullBoard)
            {
                Direction point = static_cast<Direction>(dir);
                emptyLocation = temp(point, *location, step);
                if (checkLocation(&emptyLocation))
                {
                    location->row = emptyLocation.row;
                    location ->col = emptyLocation.col;
                    emptyFound = true;
                }
            }
        }
        
        step++;
    }
     if (!emptyFound)
    {   
        //done do nothing value has been already ammended to the pointer
        // but still need to handle a full board.
        //fullBoard, no more spaces available, end game?
    }
    
}


/*********************************************************************
* Description: Function returns a temporary location that is either
* north, east, south or west, based on the cardinal point passed in 
* in the parameter list, from the location also passed in in the 
* parameter list
*********************************************************************/

Location BugWorld::temp(Direction direction, Location location, int step)
{   Location empty;
    switch(direction)
    { 
        case north: 
            empty.row = location.row - step;
            empty.col = location.col;
            break;
        case east:
            empty.row = location.row;
            empty.col = location.col + step;
            break;
        case south:
            empty.row = location.row + step;
            empty.col = location.col;
            break;
        case west: 
            empty.row = location.row;
            empty.col = location.col - step;
            break;
    }
    return empty;
}





/*********************************************************************
* Description: Getter for grid.
*********************************************************************/

Critter*** BugWorld::getGrid()
{
    return grid;
}

/*********************************************************************
* Description: Getter for timeSteps.
*********************************************************************/
int BugWorld::getTimeSteps() 
{
    return timeSteps;    
}





