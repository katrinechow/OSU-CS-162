#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

#include "university.hpp"
#include "building.hpp"
#include "person.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "menu.hpp"

using namespace Menu;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::setprecision;
using std::fixed;

int main()
{
	//Seeding randomizer
	srand(time(0));
	
	//Tracking menu1 and menu2 choices
	char choice;
	char choice2;
	
	//Creating vector of pointers to Person objects
	vector <Person*> pVector;
	pVector.push_back(new Person);

	//Creating vector to Building objects
	vector <Building> bVector;

	//Instantiate default Student, Instructor
	pVector.push_back(new Student("Harry Potter", 20, 3.9));
	pVector.push_back(new Instructor("Albus Dumbledore", 70, 5.0));

	//Instantiate default Building
	bVector.push_back(Building("Memorial Union Building", 141600,
		"2501 SW JEFFERSON WAY, CORVALLIS, OR 97331"));	

	bVector.push_back(Building("Covell Hall", 30270, 
		"1691 SW CAMPUS WAY, CORVALLIS, OR 97330"));
	
	//Captures vector sizes	
	int pvsize = pVector.size();
	int bvsize = bVector.size();

	char psize = static_cast<char>(pvsize);

	//Declare University object
	University osu(bvsize, pvsize);

	//Display Main Menu
	Menu::displayMenu1();
	choice = Menu::getChoice('4');
	

	switch(choice)
	{
		case '1': 
			{
				osu.printBuilding(bVector);
				break;
			}

		case '2':
			{
				cout << "**********************************" <<
					" ******" << endl;
				for (int i = 1; i < psize; i++)
				{
					osu.printPerson(psize, i, pVector[i]);
				}
					break;
			}

		case '3':
			{
				Menu::displayMenu2(pVector);
				break;
			}

		case '4':
			{
				for (int i = 0; i < psize; i++)
				{
					delete pVector[i];
				} 
				return 0;
			}
	}				  
		
	//Deallocate
	for (int i = 0; i < psize; i++)
	{
		delete pVector[i];
	}
	//delete[] pVector;

	return 0;
}
