/*********************************************************************
** Program: Project Predator Prey Game
** Author: Group 48
** Date: Feb 5, 2018
** Description: A simple struct that holds two variables, row and col
* treating the program in OOD, by representing the Critter has-a 
* location.
*********************************************************************/

#ifndef PREDATOR_PREY_LOCATION_HPP
#define PREDATOR_PREY_LOCATION_HPP


struct Location 
{
    int row;
    int col;
    
    Location() : row(-1), col(-1) {}
    Location(int r, int c) : row(r), col(c) {}
    
    
    //Overloading operator == compares members with members of another Location
    bool operator== (const Location& rhsLocation)
    {
        return (row == rhsLocation.row) && (col == rhsLocation.col);
    
    }
};


#endif //PREDATOR_PREY_USER_LOCATION_HPP
