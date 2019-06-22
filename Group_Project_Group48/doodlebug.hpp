/*********************************************************************
** Program: Group Project - Predator Prey Game: doodlebug.hpp
** Author: Group 48
** Date: Feb 5, 2018
** Description: This is the header file for derived class Doodlebug,
**              which inherits its attribute variables from class
**              Critter. Doodlbug has its own move() and starve()
**              behavior; it will try to move to a cell with an ant
**              and eat it, and it will die if no ant eaten in 3 steps.
*********************************************************************/
#ifndef PREDATOR_PREY_GAME_DOODLEBUG_HPP
#define PREDATOR_PREY_GAME_DOODLEBUG_HPP
#include "critter.hpp"

class Doodlebug : public Critter
{
    private:
        //tracks if it has eaten ants every 3 steps. If not, then starve();
        int foodless; 
        
    public:
        Doodlebug(); //Default constructor
        Doodlebug(Location);
        void setEaten(bool);
        bool getEaten();
        void move(Critter***, int, int);
        void starve(Critter***);
        void breed(Critter*** grid, int rowsIn, int colsIn);
       // ~Doodlebug();
        
};


#endif //PREDATOR_PREY_GAME_DOODLEBUG_HPP
