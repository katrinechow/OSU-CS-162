/*******************************************************************************
** Program name: Lab 1 Matrix Calculator - main.cpp
** Author: Katrine Chow
** Date: January 10, 2018
** Description: This is the main function file/client code of the program to
**              build a 2x2 or 3x3 matrix, asks user to input all the values in
**              the matrix, calculate and return the matrix and its determinant.
*******************************************************************************/

#include <iostream>
#include "matrix.hpp"
#include "determinant.hpp"

using std::cin;
using std::cout;
using std::endl;

using namespace matrix;
using namespace determinant;

int main()
{
	char sizeinput = '0';
	int msize = 0;

	//Input Validation by reading as a char
	while (sizeinput != '2' && sizeinput != '3')
	{
		cout << "Please enter size of matrix. '2' for 2x2,"
			" '3' for 3x3: " << endl;
	
		//To limit to single char, sets cin.igore to ignore rest of
		//input until enter/newline.
		//This technique courtesy of:
		//www.cplusplus.com/reference/istream/istream/ignore
		sizeinput = cin.get();
		cin.ignore(256, '\n');
	}

	// 48 is the ASCII code for '0'. Below converts value back to int
	// This technique came from www.cplusplus.com/forum/beginner/68260
	msize = sizeinput - 48;

	//Dynamically allocate 2D array
	int** mptr = new int*[msize];
	for (int i = 0; i < msize; i++)
	{
		mptr[i] = new int[msize];
	}

	//Creates matrix
	readMatrix(mptr, msize);
	
	//Calculates determinant
	int dmnt = determinant::determinant(mptr, msize);

	//Print the matrix
	for (int i = 0; i < msize; i++)
	{
		for (int j = 0; j < msize; j++)
		{
			cout << mptr[i][j];
		}
		cout << endl;
	}

	//Print the determinant
	cout << "Determinant is: " << dmnt << endl;

	//Free the dynamic memory
	for(int i = 0; i < msize; i++)
	{
		delete [] mptr[i];
	}

	delete [] mptr;
	mptr = nullptr;

return 0;
}
