/*******************************************************************************
** Program Name: Lab 8 - Searching and Sorting
** Author: Katrine Chow
** Date: March 2, 2018
** Description: This program will read from an input file and perform search
**		and sort operations on the data values.
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

#include "sort.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	Sort s;

	//Read values from 4 files
	cout << "**************************************" << endl;
	cout << "*Reading values from 4 existing files*" << endl;
	cout << "**************************************" << endl;
	cout << endl;

	s.readValues();



	//Perform Simple Search
	cout << "**************************" << endl;
	cout << "*Performing Simple Search*" << endl;
	cout << "**************************" << endl;
	cout << endl;

	int num;
	string n = "What is the target value?";

	num = s.intValidation(n);

	cout << "Searching file 1" << endl;
	s.simpleSearch(s.f1, s.size1, num, s.fname1);
	cout << endl;

	cout << "Searching file 2" << endl;
	s.simpleSearch(s.f2, s.size2, num, s.fname2);
	cout << endl;

	cout << "Searching file 3" << endl;
	s.simpleSearch(s.f3, s.size3, num, s.fname3);
	cout << endl;

	cout << "Searching file 4" << endl;
	s.simpleSearch(s.f4, s.size4, num, s.fname4);
	cout << endl;



	//Perform Sort
	cout << "*****************" << endl;
	cout << "*Performing Sort*" << endl;
	cout << "*****************" << endl;
	cout << endl;
	
	cout << "Sorting file 1" << endl;
	s.sorting(s.f1, s.size1, 1);
	cout << endl;
	
	cout << "Sorting file 2" << endl;
	s.sorting(s.f2, s.size2, 2);
	cout << endl;

	cout << "Sorting file 3" << endl;
	s.sorting(s.f3, s.size3, 3);
	cout << endl;

	cout << "Sorting file 4" << endl;
	s.sorting(s.f4, s.size4, 4);
	cout << endl;

	cin.ignore();

	//Perform Binary Search
	cout << "**************************" << endl;
	cout << "*Performing Binary Search*" << endl;
	cout << "**************************" << endl;
	cout << endl;
	
	int found;
	int tnum;
	string p = "What is the target value?";

	tnum = s.intValidation(p);

	cout << "Binary Searching file 1" << endl;
	s.binarySearch(s.f1, s.size1, tnum);
	cout << endl;

	cout << "Binary Searching file 2" << endl;
	s.binarySearch(s.f2, s.size2, tnum);
	cout << endl;

	cout << "Binary Searching file 3" << endl;
	s.binarySearch(s.f3, s.size3, tnum);
	cout << endl;

	cout << "Binary Saerching file 4" << endl;
	s.binarySearch(s.f4, s.size4, tnum);
	cout << endl;


	return 0;
}	
