/*******************************************************************************
** Program Name: Lab 2: File I/O - letters.cpp
** Author: Katrine Chow
** Date: January 19, 2018
** Description:	The implementation file for namespace Letters. It defines
**		member functions which counts letter frequencies and output
**		them to a user-specified file.
*******************************************************************************/

#include "letters.hpp"
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace Letters;

/*******************************************************************************
**			Letters::count_letters(ifstream&, int*)
** Description:	This function reads paragraphs from input file, counts the
**		frequencies of each alphabet (regardless of upper/lower case).
*******************************************************************************/

void Letters::count_letters(ifstream& input, int* numarray)
{
	string str;
	int strlen = 0;

	//Read input until newline/paragraph
	getline(input, str, '\n');

	//Get length of string
	strlen = str.length();

	//Scan string to count frequencies
	for (int i = 0; i < strlen; i++)
	{
		//Removes whitespace and newline from count
		if(str[i] == ' ' || str[i] == '\n')
		{
			char ws = str[i];
		}

		else
		{
			char c = str[i];

			//Lower case letters
			if (c > 91)
			{
				numarray[c - 97]++;
			}

			//Upper case letters
			else if (c >= 65 && c <= 90)
			{
				numarray[c - 65]++;
			}

		}
	}
}


/*******************************************************************************
**			Letters::output_letters(ofstream&, int*)
** Description:	This function outputs array of frequencies to user-specified
**		output text file.
*******************************************************************************/

void Letters::output_letters(ofstream& output, int* numarray)
{
	string outfile;

	cout << "Enter output filename: " << endl;
	cin >> outfile;
	
	output.open(outfile);

	
	//Prints frequencies to output file
	for (int i = 0; i < 26; i++)
	{
		char c = i+97;

		output << c << ": " << numarray[i] << endl;
	} 

	
	//Closing output file
	output.close();

}
