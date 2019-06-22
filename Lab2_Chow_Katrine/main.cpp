/*******************************************************************************
** Program Name: Lab 2: File I/O - main.cpp
** Author: Katrine Chow
** Date: January 19, 2018
** Description:	This program, File I/O, reads from a user-specified text file.
**		Its function parses the contents of the file into paragraphs,
**		then scans the strings to count frequency of each alphabet.
**		The frequencies are then output to a separate file.
*******************************************************************************/

#include "letters.hpp"

#include <iostream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ifstream;
using std::ofstream;
using namespace Letters;


int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string filename;

	//Allocate array to hold frequencies. Initialize each cell to 0
	int charArray[26];
	for (int i = 0; i <= 26; i++)
	{
		charArray[i] = 0;
	}

	//Ask user for input stream file
	cout << "Enter the file to read from: " << endl;
	cin >> filename;

	inputFile.open(filename);

	
	//Filename input validation
	while(inputFile.fail())
	{
		cout << "Invalid file. Please enter the correct filename." 
			<< endl;
		
		cin >> filename;
		
		inputFile.open(filename);
	}


	//Call count function for each paragraph
	while(!inputFile.eof())
	{
		//Count frequency of letters in each paragraph
		Letters::count_letters(inputFile, charArray);
	
		//Outputs results to user-specified file
		Letters::output_letters(outputFile, charArray);
	
	}

	//Close input file
	inputFile.close();

	return 0;
}
