/*******************************************************************************
** Program Name: Lab 8 - Searching and Sorting
** Author: Katrine Chow
** Date: March 2, 2018
** Description:	This is the header file for Class Sort, which
**		contains search and sort functions that main.cpp will call.
*******************************************************************************/
#include <string>
#include <vector>

using std::string;
using std::vector;

#ifndef SORT_HPP
#define SORT_HPP

class Sort
{
	public:
		string fname1 = "origin.txt";
		string fname2 = "head.txt";
		string fname3 = "middle.txt";
		string fname4 = "end.txt";

		int size1;
		int size2;
		int size3;
		int size4;

		vector<int> f1;
		vector<int> f2;
		vector<int> f3;
		vector<int> f4;

		int intValidation(string);
		void readValues();
		void simpleSearch(vector<int>, int, int, string);
		void sorting(vector<int> &, int, int);
		void binarySearch(vector<int>, int, int);
		void displaySort(vector<int>, int);
};

#endif
