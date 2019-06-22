/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: main.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This program simulates a Zoo Tycoon game. Users are able to 
**		purchase animals for their zoo, buy feed for them, and earn
**		money based on the number and type of animals they have. Players
**		may encounter random events that boost their earnings or kill
**		off an animal. The game ends when player chooses to or when
**		player's bank empties.
*******************************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "menu.hpp"
#include "zoo.hpp"
#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include "bank.hpp"

using namespace Menu;
using std::cout;
using std::cin;
using std::endl;

int main()
{
	const char MENU1MAX = '2';
	const char MENU2MAX = '2';
	char ch2 = '1';

	//Seeding randomizer
	srand(time(0));

	//Display initial menu
	Menu::displayMenu1();
	char choice = Menu::getChoice(MENU1MAX);

	//Choice 2 to quit the program
	switch (choice)
	{
		case '1':
			break;
		case '2':
			return 0;
	}
	

	//Initializes day variable
	int day = 0;

	Zoo myZoo; //Creates Zoo

	Bank myBank; //Creates Bank

	if (day == 0)
	{
		cout << ">>>>>>>>>> ";
		cout << "Today is day: " << day;
		cout << " <<<<<<<<<<" << endl;
		cout << endl;
		cout << "You have: $" << myBank.getTotal() << 
			" in the bank" << endl;
		cout << endl;

		//Purchase starting animals
		cout << "####################" << endl;
		cout << "#                  #" << endl;
		cout << "#      Zoo 101     #" << endl;
		cout << "#                  #" << endl;
		cout << "####################" << endl;
		cout << endl;
		cout << "Let's start you off with three types"
			<< " of animals!" << endl << endl;
		cout << "You may purchase up to 2 of each type." << endl;
		cout << endl;
		cout << "Rememeber to watch your Bank Account. The game"
			<< " ends when you hit $0." << endl;
		cout << endl;
	

		char anum = 0;
		double withdraw = 0.0;

		//Buy Tigers
		cout << "How many Tigers? " << endl;
		cin >> anum;

		while (anum < '1' || anum > '2')
		{
			cout << "Please purchase only 1 or 2: " << endl;
			cin >> anum;
		}
		
		int aint = (static_cast<int>(anum) - 48);
		
		withdraw = withdraw + myZoo.purchaseAnimal(1, aint);

	
		//Buy Penguins
		anum = 0;

		cout << "How many Penguins? " << endl;
		cin >> anum;

		while (anum < '1' || anum > '2')
		{
			cout << "Please purchase only 1 or 2: " << endl;
			cin >> anum;
		}

		aint = (static_cast<int>(anum) - 48);

		withdraw = withdraw + myZoo.purchaseAnimal(2, aint);


		//Buy Turtles
		anum = 0;

		cout << "How many Turtles? " << endl;
		cin >> anum;

		while (anum < '1' || anum > '2')
		{
			cout << "Please purchase only 1 or 2: " << endl;
			cin >> anum;
		}

		aint = (static_cast<int>(anum) - 48);

		withdraw = withdraw + myZoo.purchaseAnimal(3, aint);


		//Make withdrawal from Bank
		myBank.makeWithdrawal(withdraw);
	
		cout << endl;	
		cout << "Thank you! You now have $" 
			<< myBank.getTotal() << " in the bank." << endl;
		cout << endl;
		cout << endl;

		day++;

	} //End of Day 0 Tasks

	do
	{
		if (myBank.getTotal() > 0)
		{	
			//Daily Tasks starting at Day 1
			cout << "####################" << endl;
			cout << "#                  #" << endl;
			cout << "#   Good Morning!  #" << endl;
			cout << "#                  #" << endl;
			cout << "####################" << endl;
			cout << endl;
			cout << "Welcome to Day " << day << " !" << endl;
			cout << endl;
			cout << "You have $" << myBank.getTotal() << " in the"
				<< " bank" << endl << endl;

			//Increase all animals' age by 1
			myZoo.increaseAge();
			cout << "Whoohoo! All animals are 1 day older!" << endl;
			cout << endl;
			cout << endl;

			//Feed all animals.
			double feed = myZoo.feedAnimals();
			myBank.makeWithdrawal(feed);
			cout << "Yum yum! Thank you for being a responsible"
				<< " owner!" << endl;
			cout << "Today's feed cost you: $" << feed << endl;
			cout << endl;
			cout << "You now have $" << myBank.getTotal() << " in the"
				<< " bank" << endl;
			cout << endl;
			cout << endl;

			//Random Event
			int randomevent = rand()% 4 + 1;
			double bonus = 0.0;

			if (randomevent == 1)
			{
				cout << "Oh no! One of your animals has"
					<< " dysentery!" << endl;
				myZoo.random1();
			}	

			else if (randomevent == 2)
			{
				bonus = myZoo.random2();
				cout << "Golly! It is National Love Your Tiger"
					<< " Day! You made $" << bonus << endl; 
				myBank.makeDeposit(bonus);
				
			}

			else if (randomevent == 3)
			{
				cout << "A stork flew over your lands!" << endl;
				myZoo.random3();
			}
	
			else
			{
				cout << "No random event today" << endl;
			}

			cout << endl;

	
			//Sum up daily payoff and total
			cout << "Your day " << day << " profit is: $"
				<< bonus + myZoo.getPayoff() << endl;
			cout << endl;
			cout << "You now have $" << myBank.getTotal() << " in"
				<< " your bank" << endl << endl;
				

			//Ask player if they'd like to purchase an adult animal
			char buy;

			cout << "Would you like to purchase an adult animal?" <<
				endl;
			cout << "Type 1 for Yes or 2 for No" << endl;
			cin >> buy;

			while (buy < '1' || buy > '2')
			{
				cout << "Please enter only 1 for Yes or 2 for"
					<< " No" << endl;
				cin >> buy;
			}

			cout << endl;

			if (buy == '1')
			{
				char buytype;

				cout << "Which type of animal would you like to"
					<< " buy?" << endl;
				cout << "1) Tiger" << endl;
				cout << "2) Penguin" << endl;
				cout << "3) Turtle" << endl;		

				cin >> buytype;

				while (buytype < '1' || buytype > '3')
				{
					cout << "Please enter 1, 2, or 3" << endl;
					cin >> buytype;
				}

				if (buytype == '1')
				{
					double adultcost;
					adultcost = myZoo.purchaseAdult(1, 1);
					cout << "Thank you! Please pay $" 
						<< adultcost << endl << endl;
					myBank.makeWithdrawal(adultcost);
				}

				else if (buytype == '2')
				{
					double adultcost;
					adultcost = myZoo.purchaseAdult(2, 1);
					cout << "Thank you! Please pay $" 
						<< adultcost << endl << endl;
					myBank.makeWithdrawal(adultcost);
				}

				else if (buytype == '3')
				{
					double adultcost;
					adultcost = myZoo.purchaseAdult(3, 1);
					cout << "Thank you! Please pay $" 
						<< adultcost << endl << endl;
					myBank.makeWithdrawal(adultcost);
				}

			}

			cout << "####################" << endl;
			cout << "#                  #" << endl;
			cout << "#     Day " << day << "        #" << endl;
			cout << "#    Complete!     #" << endl;
			cout << "#                  #" << endl;
			cout << "####################" << endl;
			cout << "Day " << day << " has ended" << endl;
			cout << endl;
			cout << "You have $" << myBank.getTotal() << 
				" in the bank" << endl << endl;

			//Increment day
			day++;

		} //End of if bank <= 0 if

		else
		{
			cout << "####################" << endl;
			cout << "#                  #" << endl;
			cout << "#    Game Over     #" << endl;
			cout << "#                  #" << endl;
			cout << "####################" << endl << endl;
			cout << "Your animals have run away to greener pastures"
				 << endl;

			myZoo.deleteArray();
			return 0;
		}	



		//After day completed, ask user to continue or quit
		Menu::displayMenu2();
		cin.ignore(); //Flush out the last \n in the buffer

		char ch2 = Menu::getChoice(MENU2MAX);
		cout << endl;

		//If 2, then quit the game
		if (ch2 == '2')
		{
			cout << "####################" << endl;
			cout << "#                  #" << endl;
			cout << "#   See You Soon!  #" << endl;
			cout << "#                  #" << endl;
			cout << "####################" << endl;
			cout << endl;
			cout << "Thank you for playing!" << endl;
			cout << endl;
			cout << "2018 Katrine Chow" << endl;
			cout << endl;

			myZoo.deleteArray();
			return 0;
		}


	}while(ch2 == '1');

	//Deallocate all arrays
	myZoo.deleteArray();

	return 0;
}
