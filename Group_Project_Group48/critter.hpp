/*********************************************************************
** Program: Group Project - Predator-Prey Game: critter.hpp
** Author: Group 48
** Date: Feb 5, 2018
** Description: This is the header file for class Critter, which is a
**              base class that has member variables and functions
**              that contains the basic attributes of critters: symbol
**              steps, as well as move and breed cycles.
*********************************************************************/
#ifndef PREDATOR_PREY_GAME_CRITTER_HPP
#define PREDATOR_PREY_GAME_CRITTER_HPP
#include "location.hpp"


class Critter 
{
    protected:
        char symbol;
        Location location;
        int movesMade;
        int swapped;
        
    public:
        Critter(); //Default constructor
        Critter(Location);
        Critter(int, int);
        void setSymbol(char);
        char getSymbol();
    
        void setLocation(Location);
    
        Location getLocation();
        void updateLocation(int, int);
        void printSymbol();
        //void printSymbol(char);
        virtual void move(Critter***, int, int);
        virtual void breed(Critter***, int, int);
    
    bool getSwapped();
    void setSwapped(bool);
    
        
        
};


#endif //PREY_PREDATOR_GAME_CRITTER_HPP
