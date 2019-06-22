/*******************************************************************************
** Program name: Lab 1 Matrix Calculator - matrix.cpp
** Author: Katrine Chow
** Date: January 10, 2018
** Description: Matrix class implementation that defines readMatrix()
*******************************************************************************/

#include "matrix.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace matrix
{

/*******************************************************************************
** Description:                 matrix::readMatrix(int**, int)
**             This function asks users to input values of each spot in the
**             matrix. Dynamically allocates memory as user may create a 2x2 or
**             3x3 matrix.
*******************************************************************************/

void readMatrix(int** iptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << "Enter a number: " << endl;
			cin >> iptr[i][j];
		}
	}
}



} //end of namespace
