/*******************************************************************************
** Program Name: Lab 10 - Recursive and Iterative Functions: iteration.cpp
** Author: Katrine Chow
** Date: March 12, 2018
** Description:	This is the implementation of the Iteration class, which
**		contains an iterative function that calculates Fibonacci Numbers.
**		Code references "Fibonacci Recursive and Non Recursive C++" by
**		joseph.arul83@gmail.com, 18 Sept 2010,
**		www.codeproject.comtips/109443/fibonacci-recurseive-and-non-
**		recursive-c. (Referred by Professor Zhang in Lab 10 specs)
*******************************************************************************/

#include "iteration.hpp"
#include <iostream>

using std::cout;
using std::endl;

Iteration::Iteration()
{

}

Iteration::Iteration(const long long int &n):n_(&n)
{

}


Iteration::~Iteration()
{

}


long long int Iteration::Fibonacci(const long long int &n)
{
	long long int first = 0;
	long long int second = 1;
	long long int counter = 2;

	while(counter < n)
	{
		long long int temp = second;
		second = first + second;
		first = temp;
		++counter;
	}

	if(n == 0)
	{
		return 0;
	}
	else
	{
		return first + second;
	}
}


void Iteration::printIteration()
{
	const long long int result = Fibonacci(*n_);
	cout << *n_ << "th Fibonacci Number: " << result << endl;
}
