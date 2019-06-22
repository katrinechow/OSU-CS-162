/*******************************************************************************
** Program Name: Project 4 - Fantasy Combat Tournament: menu.cpp
** Author: Katrine Chow
** Date: March 4, 2018
** Description:	This is the implementation file for namespace menu, which builds
**		a menu interface for the combat program.
*******************************************************************************/

#include "menu.hpp"
#include "character.hpp"
#include "die.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include "harrypotter.hpp"
#include "lineup.hpp"
#include "loser.hpp"

#include <iostream>
#include <string>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;

using namespace Menu;

/*******************************************************************************
**				Menu::displayMenu1()
** Description:	This function displays a user interface with choices.
*******************************************************************************/

void Menu::displayMenu1()
{
	cout << "***********************" << endl;
	cout << "*    KO Tournament    *" << endl;
	cout << "* Fight to the Death! *" << endl;
	cout << "***********************" << endl;
	cout << "1) Play" << endl;
	cout << "2) Exit" << endl;
}


/*******************************************************************************
**			Menu::displayMenu2(Lineup, Lineup)
** Description:	This function collects user input at beginning of game.
*******************************************************************************/
void Menu::displayMenu2(Lineup& teamA, Lineup& teamB)
{
	const char MENU3MAX = '5';
	int s;
	string str;
	
	str = "Enter the Number of Fighters for Team A: ";
	s = intValidation(str);

	teamA.setSize(s);
	cout << endl;

	cout << "Select your Characters!" << endl;
	displayMenu3();
	cout << endl;


	for(int i = 0; i < (teamA.getSize()); i++)
	{

		string n;
		cout << "Choose Fighter #" << i+1 << ": " << endl;

		char choice = getChoice(MENU3MAX);
		//get choice and store in Team A node
		
		cout << endl;

		switch(choice)
		{
			case '1':
			{
				Character* nptr = new Vampire;
				cout << "Name this Vampire: " << endl;
				cin >> n;
				nptr->setName(n);
				teamA.enqueue(nptr);
				cout << endl;
				break;
			}
			case '2':
			{
				Character* nptr = new Barbarian;
				cout << "Name this Barbarian: " << endl;
				cin >> n;
				nptr->setName(n);
				teamA.enqueue(nptr);
				cout << endl;
				break;
			}
			case '3':
			{
				Character* nptr = new BlueMen;
				cout << "Name this BlueMen: " << endl;
				cin >> n;
				nptr->setName(n);
				teamA.enqueue(nptr);
				cout << endl;
				break;
			}
			case '4':
			{
				Character* nptr = new Medusa;
				cout << "Name this Medusa: " << endl;
				cin >> n;
				nptr->setName(n);
				teamA.enqueue(nptr);
				cout << endl;
				break;
			}
			case '5':
			{
				Character* nptr = new HarryPotter;
				cout << "Name this HarryPotter: " << endl;
				cin >> n;
				nptr->setName(n);
				teamA.enqueue(nptr);
				cout << endl;
				break;
			}
			cout << endl;
		}
		cin.ignore();
	}


	str = "Enter the Number of Fighters for Team B: ";
	s = intValidation(str);

	teamB.setSize(s);
	cout << endl;

	cout << "Select your Characters!" << endl;
	displayMenu3();
	cout << endl;

	for(int j = 0; j < (teamB.getSize()); j++)
	{
		string a;

		//get choice and store in Team B node
		cout << "Choose Fighter #" << j+1 << ": " << endl;

		char choice2 = getChoice(MENU3MAX);

		cout << endl;

		switch(choice2)
		{
			case '1':
			{
				Character* nptr = new Vampire;
				cout << "Name this Vampire: " << endl;
				cin >> a;
				nptr->setName(a);
				teamB.enqueue(nptr);
				cout << endl;
				break;
			}
			case '2':
			{
				Character* nptr = new Barbarian;
				cout << "Name this Barbarian: " << endl;
				cin >> a;
				nptr->setName(a);
				teamB.enqueue(nptr);
				cout << endl;
				break;
			}
			case '3':
			{
				Character* nptr = new BlueMen;
				cout << "Name this BlueMen: " << endl;
				cin >> a;
				nptr->setName(a);
				teamB.enqueue(nptr);
				cout << endl;
				break;
			}
			case '4':
			{
				Character* nptr = new Medusa;
				cout << "Name this Medusa: " << endl;
				cin >> a;
				nptr->setName(a);
				teamB.enqueue(nptr);
				cout << endl;
				break;
			}
			case '5':
			{
				Character* nptr = new HarryPotter;
				cout << "Name this HarryPotter: " << endl;
				cin >> a;
				nptr->setName(a);
				teamB.enqueue(nptr);
				cout << endl;
				break;
			}
			cout << endl;
		}
	cin.ignore();
	}
}



/*******************************************************************************
**			Menu::displayMenu3()
** Description:	This function displays a list of Characters to choose from
*******************************************************************************/

void Menu::displayMenu3()
{
	cout << "1) Vampire" << endl;
	cout << "2) Barbarian" << endl;
	cout << "3) Blue Men" << endl;
	cout << "4) Medusa" << endl;
	cout << "5) Harry Potter" << endl;
}


/*******************************************************************************
**			Menu::displayMenu4()
** Description:	This function displays a Play Again option at end of a round.
*******************************************************************************/

void Menu::displayMenu4()
{
	cout << "*****************" << endl;
	cout << "*   Game Over   *" << endl;
	cout << "*****************" << endl;
	cout << endl;
	cout << "1) Play Again" << endl;
	cout << "2) Exit" << endl;
}


/*******************************************************************************
**			Menu::displayMenu5()
** Description:	This function displays a menu for user to decide if they'd like
**		to view the Loser Pile.
*******************************************************************************/
void Menu::displayMenu5()
{
	cout << "Would you like to view the Loser Pile?" << endl;
	cout << "1) Yes" << endl;
	cout << "2) No" << endl;
}



/*******************************************************************************
**			char Menu:getChoice(char)
** Description:	This function collects user's choice.
*******************************************************************************/

char Menu::getChoice(char max)
{
	char choice = cin.get();
	cin.ignore();

	while (choice < '1' || choice > max)
	{
		cout << "Please enter a valid number from 1 to " << max << endl;
		choice = cin.get();
		//cin.ignore();
		cin.clear();
	}

	return choice;
}


/*******************************************************************************
**			int Menu::intValidation(string)
** Description:	This function serves as input validation for integers. I
**		referenced SkyeShatter's YouTube video at:
**		https://youtube.com/watch?v=S3_jCTb3fm0 , as well as @86 on
**		Piazza.
*******************************************************************************/

int Menu::intValidation(string s)
{
	string str;
	int valid;
	bool flag = false;

	while (flag == false)
	{
		cout << s << endl;
		getline(cin, str);
		stringstream ss(str);
	
		if (ss >> valid && !(ss >> str))
		{
			flag = true;
		}
		else
		{
			cout << ">>> Please enter an integer only <<< " << endl;
			cout << endl;
		}
	}
		
	return valid;
}



/*******************************************************************************
**			Menu::play()
** Description:	This function collects info from the menus and manages gameflow.
*******************************************************************************/
void Menu::play()
{
	Lineup teamA;
	Lineup teamB;
	Loser pile;

	displayMenu2(teamA, teamB);

	
	int round = 1;
	
	Character* p1 = teamA.getFront();
	Character* p2 = teamB.getFront();
	

	while(teamA.isEmpty() == false && teamB.isEmpty() == false)
	{
		if(p1->getSP() >= 0 && p2->getSP() >= 0)
		{

			cout << "Round " << round << " - Fight!" << endl;
			cout << endl;

			cout << "Team A is represented by: " << p1->getType() 
				<< " named" << " " << p1->getName() << endl;
			cout << "Team B is represented by: " << p2->getType() 
				<< " named" << " " << p2->getName() << endl;
			cout << endl;

			//Attack begins- Player 1 attacks first
			cout << "Team A fighter Attacks!" << endl;
			int atk1 = p1->Attack(p2);
			p2->Defense(p1, atk1);
			cout << endl;
			
			displayStats(p1, p2);
			
			cout << endl;

			//Check on status
			if(p1->getSP() <= 0)
			{	
				cout << "Team A fighter " << p1->getName() 
					<< " K.O." << endl;
				cout << endl;
				//Moves KOed p1 to loser pile
				pile.push(p1);

				//Removes KOed p1 from Team A
				teamA.dequeue();

				teamA.setScore(-50);

				//Moves winner p2 to back of teamB
				cout << "Team B fighter " << p2->getName() 
					<< " wins " << "this round!" << endl;
				p2->recover();
				teamB.enqueue(p2);
				teamB.dequeue();

				//Add score to winning team
				teamB.setScore(50);

				p1 = teamA.getFront();
				p2 = teamB.getFront();


			}
			else if (p2->getSP() <= 0)
			{
				cout << "Team B fighter " << p2->getName() 
					<< " K.O." << endl;
				cout << endl;
				
				//Moves KOed p2 to loser pile
				pile.push(p2);
				//Removes KOed p2 from Team B
				teamB.dequeue();

				teamB.setScore(-50);

				//Moves winner p1 to back of teamA
				cout << "Team A fighter " << p1->getName() 
					<< " wins " << "this round!" << endl;
				p1->recover();
				teamA.enqueue(p1);
				teamA.dequeue();
				
				//Add score to winning team
				teamA.setScore(50);

				p1 = teamA.getFront();
				p2 = teamB.getFront();


			}
		} // End first if

		if(teamA.isEmpty() == false && teamB.isEmpty() == false)
		{
			//Attack by player 2
			cout << "Team B fighter Attacks!" << endl;
			int atk2 = p2->Attack(p1);
			p1->Defense(p2, atk2);
			cout << endl;

			displayStats(p2, p1);

			cout << endl;

			//Check on status
			if(p1->getSP() <= 0)
			{
				cout << "Team A fighter " << p1->getName() 
					<< " K.O." << endl;
				cout << endl;
				pile.push(p1);

				teamA.dequeue();

				teamA.setScore(-50);

				cout << "Team B fighter " << p2->getName() 
					<< " wins " << "this round!" << endl;
				p2->recover();

				teamB.enqueue(p2);
				teamB.dequeue();
				teamB.setScore(50);

				p1 = teamA.getFront();
				p2 = teamB.getFront();
	
			}
			else if (p2->getSP() <= 0)
			{
				cout << "Team B fighter " << p2->getName() 
					<< " K.O." << endl;
				cout << endl;
				pile.push(p2);

				teamB.dequeue();

				teamB.setScore(-50);
				cout << "Team A fighter " << p1->getName() 
					<< " wins " << "this round!" << endl;
				p1->recover();
				teamA.enqueue(p1);
				teamA.dequeue();
				teamA.setScore(50);
			
				p1 = teamA.getFront();
				p2 = teamB.getFront();

			}
		} //End second if

		cout << endl;

		round++;

	} //End of While


	cout << "********************" << endl;
	cout << "* Tournament Ends! *" << endl;
	cout << "********************" << endl;
	cout << endl;

	if(teamB.getScore() > teamA.getScore())
	{
		cout << "Team B	wins the tournament!" << endl;
		cout << "Team B Score: " << teamB.getScore() << endl;
		cout << endl;
		cout << "Team A loses!" << endl;
		cout << "Team A Score: " << teamA.getScore() << endl;
		cout << endl;
	}
	else if (teamA.getScore() > teamB.getScore())
	{
		cout << "Team A wins the tournament!" << endl;
		cout << "Team A Score: " << teamA.getScore() << endl;
		cout << endl;
		cout << "Team B loses!" << endl;
		cout << "Team B Score: " << teamB.getScore() << endl;
		cout << endl;
	}
	else
	{
		cout << "It's a tie!" << endl;
		cout << endl;
		cout << "Team A Score: " << teamA.getScore() << endl;
		cout << "Team B Score: " << teamB.getScore() << endl;
		cout << endl;
	}

	const char MENU5MAX = '2';

	displayMenu5();

	char choice3 = getChoice(MENU5MAX);

	switch(choice3)
	{
		case '1':
		{
			cout << "Parade of the Losers: " << endl;
			pile.printPile();

		}
		case '2':
		{
			break;
		}
	}


}
/*******************************************************************************
**			Menu::displayStats()
** Description:	This function displays Attacker and Defender's stats after a
**		round.
*******************************************************************************/
void Menu::displayStats(Character* atk, Character* def)
{
	cout << "Attacker Type: " << atk->getType() << endl;
	cout << "Defender Type: " << def->getType() << endl;
	cout << "Defender Armor: " << def->getArmor() << endl;
	cout << "Defender Strength Point: " << def->getOldSP() << endl;
	cout << "Attacker's Dice Roll: " << atk->getRoll() << endl;
	cout << "Defender's Dice roll: " << def->getRoll() << endl;
	cout << "Total Damage: " << def->getDamage() << endl;
	cout << "Defender's Strength Point: " << def->getSP() << endl;

}
