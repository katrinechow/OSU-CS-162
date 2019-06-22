/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: zoo.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for class Zoo, which contains
**		dynamically allocated arrays to keep track of the Tigers,
**		Penguins, and Turtles the player current owns.
*******************************************************************************/

#include <iostream>

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "zoo.hpp"

using std::cin;
using std::cout;
using std::endl;

/*******************************************************************************
**				Zoo::Zoo()
** Description:	This is the default constructor of class Zoo. It initializes
**		the three arrays for the three animal types.
*******************************************************************************/
Zoo::Zoo()
{
	//Allocate Tiger Array
	tArray = new Animal*[10];
	
	//Allocate Penguin Array
	pArray = new Animal*[10];
	
	//Allocate Turtle Array
	ttArray = new Animal*[10];
}



/********************************************************************************
**				Zoo::setLastt(int)
** Description:	This function updates the lastt variable, which keeps track of
**		the last Tiger index position.
*******************************************************************************/
void Zoo::setLastt(int update)
{
	lastt = lastt + update;
}


/*******************************************************************************
**				Zoo::setLastp(int)
** Description:	This function updates the lastp variable, which keeps track of
**		the last Penguin index position.
*******************************************************************************/
void Zoo::setLastp(int update)
{
	lastp = lastp + update;
}


/*******************************************************************************
**				Zoo::setLasttt(int)
** Description:	This function updates the lasttt variable, which keeps track of
**		the last Turtle index position.
*******************************************************************************/
void Zoo::setLasttt(int update)
{
	lasttt = lasttt + update;
}


/*******************************************************************************
**				Zoo::increaseAge()
** Description:	This function increases all animals' age by 1.
*******************************************************************************/
void Zoo::increaseAge()
{
	for (int i = 0; i < lastt; i++)
	{
		tArray[i]->setAge(1);
	}

	for (int i = 0; i < lastp; i++)
	{
		pArray[i]->setAge(1);
	}

	for (int i = 0; i < lasttt; i++)
	{
		ttArray[i]->setAge(1);
	}
}



/*******************************************************************************
**				Zoo::feedAnimals()
** Description:	This function feeds all animals and returns the cost.
*******************************************************************************/
double Zoo::feedAnimals()
{
	double ttotal = lastt * 50;
	double ptotal = lastp * 10;
	double tttotal = lasttt * 5;
	
	double sum = ttotal + ptotal + tttotal;
	
	return sum;
}
	


/*******************************************************************************
**			Zoo::purchaseAnimal(int, int)
** Description:	This adds animal to array and calculates and return the cost
**		to be withdrawn from the bank.
*******************************************************************************/
double Zoo::purchaseAnimal(int type, int quantity)
{
	if (type == 1)
	{
		//Make sure array has enough space to add more
		int ttemp = lastt + quantity;
		int tindex = lastt;

		if (ttemp > tsize)
		{
			resizeArray(tArray, tsize, lastt, 1);
		}

		double money = 0.0;

		for (int i = tindex; i < ttemp; i++)
		{
			tArray[i] =  new Tiger;
		}
			lastt = ttemp;
		
		money = money + (quantity * 10000);
	
		return money;

	}

	else if (type == 2)
	{
		//Make sure pArray has enough space to add more
		int ptemp = lastp + quantity;
		int pindex = lastp;

		if (ptemp > psize)
		{
			resizeArray(pArray, psize, lastp, 1);
		}

		double money = 0.0;

		for (int i = pindex; i < ptemp; i++)
		{
			pArray[i] = new Penguin;
		}
			lastp = ptemp;
		
		
		money = money + (quantity * 1000);

		return money;
	}

	else if (type == 3)
	{
		//Make sure ttArray has enough space to add more
		int tttemp = lasttt + quantity;
		int ttindex = lasttt;

		if (tttemp > ttsize)
		{
			resizeArray(ttArray, ttsize, lasttt, 1);
		}

		double money = 0.0;

		for (int i = ttindex; i < tttemp; i++)
		{
			ttArray[i] = new Turtle;
		}
			lasttt = tttemp;
		
		
		money = money + (quantity * 100);

		return money;
	}
}


	
/*******************************************************************************
**			Zoo::purchaseAdult(int, int)
** Description:	This function adds an adult animal to the menagerie and returns
**		the total cost to player.
*******************************************************************************/
double Zoo::purchaseAdult(int type, int quantity)
{
	if (type == 1)
	{
		//Make sure tArray has enough space to add
		int ttemp = lastt + quantity;
		int tindex = lastt;
		
		if (ttemp > tsize)
		{
			resizeArray(tArray, tsize, lastt, 1);
		}

		double money = 0.0;

		for (int i = tindex; i < ttemp; i++)
		{
			tArray[i] = new Tiger;
			tArray[i]->setAge(2); //since default age is 1
		}
			lastt = ttemp;
	
		money = money + (quantity * 10000);

		return money;
	}

	if (type == 2)
	{
		//Make sure pArray has enough space to add
		int ptemp = lastp + quantity;
		int pindex = lastp;

		if (ptemp > psize)
		{
			resizeArray(pArray, psize, lastp, 1);
		}

		double money = 0.0;

		for (int i = pindex; i < ptemp; i++)
		{
			pArray[i] = new Penguin;
			pArray[i]->setAge(2);
		}
			lastp = ptemp;
		
		
		money = money + (quantity * 1000);
	
		return money;	
	}

	if (type == 3)
	{
		//Make sure ttArray has enough space to add
		int tttemp = lasttt + quantity;
		int ttindex = lasttt;

		if (tttemp > ttsize)
		{
			resizeArray(ttArray, ttsize, lasttt, 1);
		}

		double money = 0.0;

		for (int i = ttindex; i < tttemp; i++)
		{
			ttArray[i] = new Turtle;
			ttArray[i]->setAge(2);
		}
			lasttt = tttemp;
		

		money = money + (quantity * 100);

		return money;
	}

}



/*******************************************************************************
** 			Zoo::resizeArray(Animal**, int, int, int)
** Description:	This expands the animal arrays by 10.
*******************************************************************************/
void Zoo::resizeArray(Animal** oldarray, int &oldsize, int index, int flag)
{
	int newsize;

	//Determine which type of resize based on flag parameter
	if (flag == 1) //Out of space, double array
	{
		newsize = oldsize * 2;
	}

	else if (flag == 3) //Purchased an animal
	{
		newsize = oldsize + 1;
	}


	//Create new array
	Animal** newptr = new Animal*[newsize];

	if (index == lastt)
	{
		for (int i = 0; i < newsize; i++)
		{
			newptr[i] = new Tiger;
		}
	}

	else if (index == lastp)
	{
		for (int i = 0; i < newsize; i++)
		{
			newptr[i] = new Penguin;
		}
	}

	else if (index == lasttt)
	{
		for (int i = 0; i < newsize; i++)
		{
			newptr[i] = new Turtle;
		}
	}


	// Copy old array contents over
	for (int i = 0; i < index - 1; i++) //copy till last size
	{

		newptr[i] = oldarray[i];
	}	


	//Delete old array
	for (int i = 0; i < oldsize; i++)
	{
		delete oldarray[i];
	}


	delete[] oldarray;
	oldarray = nullptr;
	oldarray = newptr;

	//Update array size
	oldsize = newsize;
}


/*******************************************************************************
**				Zoo::random1()
** Description:	This function defines random event 1.
*******************************************************************************/
void Zoo::random1()
{
		//Decides which animal type must die :(
		int randani = rand()% 3 + 1;
		
		if (randani == 1)
		{
			cout << "Your poor Tiger has crossed the rainbow"
				" bridge" << endl;
			//Sends a Tiger off to die (Animal cruelty)
			tArray[lastt] = NULL;
			lastt = lastt - 1;
		}

		else if (randani == 2)
		{
			cout << "Your poor Penguin has crossed the rainbow"
				" bridge" << endl;
			//Sends a Penguin off to die (noooo!)
			pArray[lastp] = NULL;
			lastp = lastp - 1;
		}
	
		else if (randani == 3)
		{
			cout << "Your poor Turtle has crossed the rainbow"
				" bridge" << endl;
			//Sends a Turtle off to die (#JusticeForMichaelangelo)
			ttArray[lasttt] = NULL;
			lasttt = lasttt - 1;
		}

}


/*******************************************************************************
**				Zoo::random2()
** Description:	This function defines random event 2. Returns the bonus for
**		population boom.
*******************************************************************************/
double Zoo::random2()
{
	//Bonus randomizer
	double x = (rand() % 500 + 250);
	double bonus = x * lastt;

	return bonus;
}



/*******************************************************************************
**				Zoo::random3()
** Description:	This function defines random event 3.
*******************************************************************************/
void Zoo::random3()
{
	//Decides which animal type will have a baby
	int randani = rand()% 3 + 1;

	if (randani == 1)
	{
		if (lastt > 0)
		{
			int age;
			bool adult = false;

			//Check if any Tigers are adults
			for (int i = 0; i < lastt; i ++)
			{
				age = tArray[i]->getAgeType();
			
				if (age == 97)
				{
					adult = true;
					
					//Make sure tArray has space to add
					int ttemp = lastt + 1;

					if (ttemp >= tsize)
					{
						resizeArray(tArray, tsize, lastt, 1);
					}

					cout << "One baby Tiger greets you!"
						<< " They're Grrrreat!" << endl;
					for (int j = lastt; j < ttemp; j++)
					{
						tArray[j] = new Tiger;
						tArray[j]->setAge(0);
					}
			
					lastt++;
			
					break;
				}
			}

			if (adult == false)
			{
				cout << "Your tigers are too young to have"
					<< " babies." << endl;
			}
		}

		else
		{
			cout << "You don't have any tigers!" << endl;
		}
		
	}

	else if (randani == 2)
	{
		//Check if there are penguins
		if (lastp > 0)
		{
			int age;
			bool adult = false;
	
			//Check if any Penguins are adults
			for (int i = 0; i < lastp; i++)
			{
				age = pArray[i]->getAgeType();

				if (age == 97)
				{
					adult = true;

					//Make sure pArray has space to add
					int ptemp = lastp + 5;

					if (ptemp >= psize)
					{
						resizeArray(pArray, psize, lastp, 1);
					}

					cout << "Five baby penguins slide"
						<< " towards you!" << endl;
					for (int j = lastp; j < ptemp; j++)
					{
						pArray[j] = new Penguin;
						pArray[j]->setAge(0);
					}

					lastp = lastp + 5;
				
					break;
				}
			}

			if (adult == false)
			{
				cout << "Your penguins are too young to have"
					<< " babies." << endl;
			}
		}
		else
		{
			cout << "You don't have any penguins!" << endl;
		}
			
	}

	else if (randani == 3)
	{
		//Check if there are any Turtles
		if (lasttt > 0)
		{
			int age;
			bool adult = false;

			//Check if any Turtles are adults
			for (int i = 0; i < lasttt; i++)
			{
				age = ttArray[i]->getAgeType();
			
				if (age == 97)
				{
					adult = true;
				
					//Make sure ttArray has space to add
					int tttemp = lasttt + 10;

					if (tttemp >= ttsize)
					{
						resizeArray(ttArray, ttsize, lasttt, 1);
					}

					cout << "Ten baby turtles try to flip"
						" over! Cowabunga!" << endl;
					for (int j = lasttt; j < tttemp; j++)
					{
						ttArray[j] = new Turtle;
						ttArray[j]->setAge(0);
					}
			
					lasttt = lasttt + 10;
			
					break;
				}
			}

			if (adult == false)
			{
				cout << "Your turtles are too young to have"
					<< " babies." << endl;
			}
		}

		else
		{
			cout << "You have no turtles!" << endl;
		}
	}
	
}	


/*******************************************************************************
**				Zoo::getPayoff()
** Description:	This function returns the daily payoff from the animals.
*******************************************************************************/
double Zoo::getPayoff()
{
	double tpay = lastt * 2000;
	double ppay = lastp * 100;
	double ttpay = lasttt * 5;

	return tpay + ppay + ttpay;
}



/*******************************************************************************
**				Zoo::deleteArray()
** Description:	This function deallocates the Animal arrays to prevent memory
**		leaks.
*******************************************************************************/
void Zoo::deleteArray()
{
	//Deallocate Tigers
	for (int i = 0; i < tsize; i++)
	{
		delete[] tArray[i];
	}

	delete[] tArray;
	tArray = nullptr;

	//Deallocate Penguins
	for (int i = 0; i < psize; i++)
	{
		delete[] pArray[i];
	}

	delete[] pArray;
	pArray = nullptr;


	//Deallocate Turtles
	for (int i = 0; i < ttsize; i++)
	{
		delete[] ttArray[i];
	}

	delete[] ttArray;
	ttArray = nullptr;
}	



/*******************************************************************************
**				Zoo::~Zoo()
** Description:	This is the destructor of class Zoo.
*******************************************************************************/
Zoo::~Zoo()
{
	//Delete Tiger Array
	delete[] tArray;
	tArray = nullptr;

	//Delete Penguin Array
	delete[] pArray;
	pArray = nullptr;

	//Delete Turtle Array
	delete[] ttArray;
	ttArray = nullptr;
}
