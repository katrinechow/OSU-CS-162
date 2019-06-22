/*******************************************************************************
** Program name: Lab 1 Matrix Calculator - determinant.cpp
** Author: Katrine Chow
** Date: January 10, 2018
** Description: This is the implementation of determinant function, which
**              returns the determinant of a matrix.
*******************************************************************************/

#include "determinant.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

namespace determinant
{

/*******************************************************************************
** Description:                  determinant::determinant() 
**             This function calculates the determinant of the user-specified
**             matrix. It then returns the integer result.
*******************************************************************************/

	int determinant(int** iptr, int size)
	{
		int d = 0; //int d to hold the determinant

		if (size == 2)
		{
			d = (iptr[0][0] * iptr[1][1]) - 
				(iptr[0][1] * iptr[1][0]);
		}

		else if (size == 3)
		{
			//calculating each of the 3 components separately for
			//readability
			int a = iptr[0][0] * ((iptr[1][1] * iptr[2][2]) -
				(iptr[1][2] * iptr[2][1]));

			int b = iptr[0][1] * ((iptr[1][0] * iptr[2][2]) -
				(iptr[1][2] * iptr[2][0]));

			int c = iptr[0][2] * ((iptr[1][0] * iptr[2][1]) -
				(iptr[1][1] * iptr[2][0]));

			//All together now
			d = a - b + c;
		}

		return d;

	}

}
