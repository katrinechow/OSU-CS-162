/*********************************************************************
* Program: Predator Prey Game
* Author: Group 48
* Date: Feb 5, 2018
* Description: This is the class that handles the game, had a grid, 
* where the bugs move and interact. The grid is a dynamic array of 
* pointers to Critter. Also has an instance of the Menu and 
* member functions to set the grid according to the settings entered
* by the user. 
*********************************************************************/

#ifndef PREDATOR_PREY_GAME_BUGWORLD_HPP
#define PREDATOR_PREY_GAME_BUGWORLD_HPP

#include "critter.hpp"
#include "menu.hpp"

enum Direction {north, east, west, south}; 

class BugWorld 
{
    private:
        Menu gameMenu;
        Critter*** grid;
        int critterCount;
        
        int timeSteps;
        int numRows;
        int numCols;
        int numAnts;
        int numDoodlebugs;
        //Cardinal point;
        void moveBugs(char);
        void sortGrid();
        void printGrid();
        int random(int);
        bool isEmpty(Location);
        void getEmptyLocation(Location*);
        Location temp(Direction, Location, int);
        void getEmpty(Location* location);
        bool checkLocation(Location*);
        

        
    public:
        BugWorld();
        Critter*** getGrid();
        void play();
        int getTimeSteps();
        void setCritterCount();
        void incrementCritterCount();
        void decrementCritterCount();
            
        void setGrid();
        ~BugWorld();
        
        //moveCritters() to handle info passed from move() in Ant and DB?
        
};


#endif //PREDATOR_PREY_GAME_BUGWORLD_HPP
