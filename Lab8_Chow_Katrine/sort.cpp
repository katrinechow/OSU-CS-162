/*******************************************************************************
** Program Name: Lab 8 - Searching and Sorting
** Author: Katrine Chow
** Date: March 2, 2018
** Description:	This is the implementation file for Namespace Sort, which
**		contains search and sort functions that main.cpp will call.
*******************************************************************************/
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "sort.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::ifstream;
using std::ofstream;


/*******************************************************************************
**			Sort::intValidation(string)
** Description:	This function serves as input validation for integers. I
**		referenced SkyeShatter's YouTube video at:
**		https://youtube.com/watch?v=S3_jCTb3fm0 , as well as @86 on
**		Piazza.
*******************************************************************************/

int Sort::intValidation(string s)
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
			cout << ">>> Please enter an integer only <<<" << endl;
			cout << endl;
		}
	}

	return valid;
}



/*******************************************************************************
** 			Sort::readValues()
** Description:	This function reads values from a txt file and put them into
**		an integer array.
*******************************************************************************/

void Sort::readValues()
{
	int num;
	ifstream inputFile;

	//Process first file
	inputFile.open("origin.txt");

	while(!inputFile.eof() && inputFile>>num)
	{
		//Read each integer into the array
		f1.push_back(num);
	}

	size1 = f1.size();
	
	inputFile.close();


	//Process second file
	inputFile.open("head.txt");

	while(!inputFile.eof() && inputFile>>num)
	{
		//Read each integer into the array
		f2.push_back(num);
	}

	size2 = f2.size();

	inputFile.close();


	//Process third file
	inputFile.open("middle.txt");

	while(!inputFile.eof() && inputFile>>num)
	{
		//Read each integer into the array
		f3.push_back(num);
	}

	size3 = f3.size();

	inputFile.close();


	//Process fourth file
	inputFile.open("end.txt");

	while(!inputFile.eof() && inputFile>>num)
	{
		//Read each intger into the array
		f4.push_back(num);
	}

	size4 = f4.size();

	inputFile.close();

}


/*******************************************************************************
**			Sort::simpleSearch(vector<int>, int, int, string)
** Description:	This function performs a simple search of the target value.
*******************************************************************************/
void Sort::simpleSearch(vector<int> file, int size, int target, string name)
{
	bool flag = false;
	int i = 0;

	//Search file
	while(i < size && flag == false)
	{
		if(file[i] == target)
		{
			flag = true;
		}

		i++;
	}

	if(flag == true)
	{
		cout << name << ": target value found" << endl;
	}
	else
	{
		cout << name << ": target value not found" << endl;
	}

}


/*******************************************************************************
**			Sort::sorting(vector<int>, int, int)
** Description:	This function applies a sorting algorithm to sort all 4 arrays.
**		Sorting algorithm references pp 625 of textbook "Starting Out 
**		with C++: Early Objects Ninth Edition" by Tony Gaddis et al.
*******************************************************************************/

void Sort::sorting(vector<int> &file, int size, int num)
{
	string filename;

	cout << "Please enter an output filename:" << endl;
	cin >> filename;

	ofstream outputFile;
	outputFile.open(filename);

	//Display unsorted vector
	cout << "Unsorted values for file " << num << " are: " << endl;
	displaySort(file, size);

	//Vector sorting algorithm based on Gaddis Text pp 625
	//Sorting file
	int temp;
	bool swap;

	do{
		swap = false;

		for(unsigned count = 0; count < size - 1; count++)
		{
			if(file[count] > file[count + 1])
			{
				temp = file[count];
				file[count] = file[count + 1];
				file[count + 1] = temp;
				swap = true;
			}
		}
	}while (swap);

	cout << "Sorted values for file " << num << " are: " << endl;
	displaySort(file, size);

	//Output to file
	for(int i = 0; i < size; i++)
	{
		outputFile << file[i] << " ";
	}

	outputFile.close();

}



/*******************************************************************************
**			Sort::binarySearch(vector<int>, int, int)
** Description:	This function searches for target value via the Binary Search
**		method. This will be applied to the sorted vectors from prior
**		steps. The Binary Search algorithm references pp 609 of textbook
**		"Starting Out with C++: Early Objects Ninth Edition" by Tony
**		Gaddis et al. Also referenced the use of unsigned int per
**		article "Extra, Extra - Read All About It: Nearly All Binary
**		Searches and Mergesorts are Broken" by Joshua Bloch, June 2,
**		2006, at https://research.googleblog.com/2006/06/extra-extra-
**		read-all-about-it-nearly.html".
*******************************************************************************/
void Sort::binarySearch(vector<int> file, int size, int target)
{
	int start = 0;
	int last = size - 1;
	int middle;
	int position = -1;

	bool found = false;

	while(!found && start <= last)
	{
		//Per Joshua Bloch's post, use unsigned int to prevent
		//negative overflow
		middle = ((unsigned int)start + (unsigned int)last) / 2;
		
		if(file[middle] == target)
		{
			found = true;
			position = middle;
		}
		else if (file[middle] > target)
		{
			last = middle - 1;
		}
		else
		{
			start = middle + 1;
		}
	}
	

	if(position == -1)
	{
		cout << "Target value does not exist" << endl;
	}
	else if (start == last)
	{
		cout << "Target value " << target << " was found in position "
			<< "0 of the file" << endl;
	}
	else
	{
		cout << "Target Value " << target << " was found in position "
			<< position << " of the file" << endl;
	}
}
	
/*******************************************************************************
**			Sort::displaySort(vector<int>, int)
** Description:	This function displays the sorted lists.
*******************************************************************************/
void Sort::displaySort(vector<int> file, int size)
{
	for(int i = 0; i < size; i++)
	{
		cout << file[i] << " ";
	}

	cout << endl;
}
