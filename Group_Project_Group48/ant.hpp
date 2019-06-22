/*********************************************************************
** Program: Group Project - Predator Prey Game: ant.hpp
** Author: Group 48
** Date: Feb 5, 2018
** Description: This is the header file for class Ant, which stores
**              an Ant object's attribute and functions that defines
**              its behavior.
*********************************************************************/
#ifndef PREDATOR_PREY_GAME_ANT_HPP
#define PREDATOR_PREY_GAME_ANT_HPP

#include "critter.hpp"


class Ant : public Critter
{
    public:
        Ant();
        Ant(Location);
        void move(Critter***, int, int);
        void breed(Critter***, int, int);
       // ~Ant();
};


#endif //PREDATOR_PREY_GAME_ANT_HPP
