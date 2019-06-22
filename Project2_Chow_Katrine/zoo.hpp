/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: zoo.hpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the header file for class Zoo, which keeps track of the
**		animals in dynamic arrays.
*******************************************************************************/
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

class Zoo
{
	private:
		Animal** tArray = nullptr;		
		Animal** pArray = nullptr;
		Animal** ttArray = nullptr;
		int tsize = 10;
		int psize = 10;
		int ttsize = 10;
		int lastt = 0;
		int lastp = 0;
		int lasttt = 0;

	public:
		Zoo(); //Default constructor
		void setLastt(int);
		void setLastp(int);
		void setLasttt(int);
		void increaseAge();
		double feedAnimals();
		double purchaseAnimal(int, int);
		double purchaseAdult(int, int);
		void resizeArray(Animal**, int&, int, int);
		void random1();
		double random2();
		void random3();
		double getPayoff();
		void deleteArray();
		~Zoo();
};

#endif
