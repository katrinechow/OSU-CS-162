/*******************************************************************************
** Program Name: Final Project - Text-based Game: game.cpp
** Author: Katrine Chow
** Date: March 15, 2018
** Description:	This is the implementation file for class Game. It
**		defines the various functions that control the flow of the game
**		std::find from Algorithm - usage from StackOverflow:
**		https://stackoverflow.com/questions/571394/how-to-find-out-if-
**		an-item-is0present-in-a-stdvector
*******************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "game.hpp"
#include "space.hpp"
#include "player.hpp"
#include "mainhall.hpp"
#include "kitchen.hpp"
#include "gym.hpp"
#include "pond.hpp"
#include "study.hpp"
#include "attic.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;


/*******************************************************************************
**				Game::Game
** Description:	This is the default constructor.
*******************************************************************************/
Game::Game()
{

}

/*******************************************************************************
**				Game::~Game()
** Description:	This is the destructor of class Game.
*******************************************************************************/
Game::~Game()
{

}


/*******************************************************************************
**				Game::playGame()
** Description:	This starts the game play.
*******************************************************************************/
int Game::playGame()
{
	Player bob;

	//Linking Main Hall
	Space* mainptr = new Mainhall;
	Space* temp = new Pond;
	mainptr->setTop(temp);
	temp = nullptr;
	temp = new Kitchen;
	mainptr->setLeft(temp);
	temp = nullptr;
	temp = new Gym;
	mainptr->setRight(temp);
	temp = nullptr;
	temp = new Study;
	mainptr->setUp(temp);

	//Linking Pond
	Space* pptr = mainptr->getTop();
	pptr->setDown(mainptr);

	//Linking Kitchen
	Space* kptr = mainptr->getLeft();
	kptr->setRight(mainptr);

	//Linking Gym
	Space* gptr = mainptr->getRight();
	gptr->setLeft(mainptr);

	//Linking Attic
	Space* aptr = new Attic;
	aptr->setDown(mainptr->getUp());

	//Linking Study
	Space* sptr = mainptr->getUp();
	sptr->setUp(aptr);
	sptr->setDown(mainptr);



	//Starts at Main Hall
	bob.setLocation(1);

	string menuChoice;
	menuChoice = mainptr->Scenario1(bob.getBag());

//	do{
	if(menuChoice == "exit")
	{
		return 7;
	}
	else
	{
		if(menuChoice == "east")
		{
			//Set player location to Kitchen
			bob.setLocation(2);

			//Run Kitchen Scenario.
			string kmenu = kptr->Scenario1(bob.getBag());

			if (kmenu == "home")
			{
				//Update player body temp
				bob.setTemp(kptr->updateTemp());
				//Update Current Room to Main Hall
				bob.setLocation(1);
				mainptr->Scenario1(bob.getBag());
			}
		}
		

		else if(menuChoice == "north")
		{
			//Set player location to Pond
			bob.setLocation(4);
			//Set currentRoom to Pond

			//Check for key item Axe
			bool keyAxe;
			if( std::find(bob.getBag().begin(), bob.getBag().end(), 207) != bob.getBag().end())
			{
				keyAxe = true;
			}
			else
			{
				keyAxe = false;
			}
  
			bool keyHammer;
			if(std::find(bob.getBag().begin(), bob.getBag().end(), 205) != bob.getBag().end())
			{
				keyHammer = true;
			}
			else
			{
				keyHammer = false;
			}

			bool keyTape;
			if(std::find(bob.getBag().begin(), bob.getBag().end(), 206) != bob.getBag().end())
			{
				keyTape = true;
			}
			else
			{
				keyTape = false;
			}


			//Run Pond Scenario
			string pmenu = pptr->Scenario1(bob.getBag(), keyAxe, keyHammer, keyTape);

			if (pmenu == "home")
			{
				//Update player body temp
				bob.setTemp(pptr->updateTemp());
				//Update Current Room to Main Hall
				bob.setLocation(1);
				mainptr->Scenario1(bob.getBag());
			}
		}
		else if (menuChoice == "west")
		{
			//Set player location to Gym
			bob.setLocation(3);
			//Run Gym Scenario
			string gmenu = gptr->Scenario1(bob.getBag());

			if (gmenu == "home")
			{
				//Update player body temp
				bob.setTemp(gptr->updateTemp());
				//Update Current Room to Main Hall
				bob.setLocation(1);
				mainptr->Scenario1(bob.getBag());
			}
		}
		else if (menuChoice == "up")
		{
			//Set player location to Study
			bob.setLocation(5);
			//Run Study Scenario
			string smenu = sptr->Scenario1(bob.getBag());

			if (smenu == "home")
			{
				//Update player body temp
				bob.setTemp(sptr->updateTemp());
				//Update Current Room to Main Hall
				bob.setLocation(1);
				mainptr->Scenario1(bob.getBag());
			}
			else if (smenu == "attic")
			{
				//Update player body temp
				bob.setTemp(sptr->updateTemp());
				bob.setLocation(6);
				
				string amenu = aptr->Scenario1();

				if(amenu == "home")
				{
					//Update player body temp
					bob.setTemp(aptr->updateTemp());
					bob.setLocation(1);
					mainptr->Scenario1(bob.getBag());
				}
			}
		}
	}
//	}while(menuChoice != "home");	


	delete mainptr;
	delete temp;
	delete kptr;
	delete gptr;
	delete pptr;
	delete sptr;
	delete aptr;

}

