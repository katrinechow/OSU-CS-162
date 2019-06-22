/*******************************************************************************
** Program Name: Lab 10 - Recursive and Iterative Functions: recursion.cpp
** Author: Katrine Chow
** Date: March 12, 2018
** Description:	This is the implementation of the Recursion class, which
**		contains an recurive function that calculates Fibonacci Numbers.
**		Code references "Fibonacci Recursive and Non Recursive C++" by
**		joseph.arul83@gmail.com, 18 Sept 2010,
**		www.codeproject.comtips/109443/fibonacci-recurseive-and-non-
**		recursive-c. (Referred by Professor Zhang in Lab 10 specs)
*******************************************************************************/

#include "recursion.hpp"
#include <iostream>

using std::cout;
using std::endl;

Recursion::Recursion()
{

}


Recursion::Recursion(const long long int &n):n_(&n)
{

}

Recursion::~Recursion()
{

}


long long int Recursion::Fibonacci(const long long int &n)
{
	if(n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	
	return Fibonacci(n-1) + Fibonacci(n-2);
}


void Recursion::printRecursion()
{
	long long int FibonacciNum = Fibonacci(*n_);
	cout << *n_ << "th Fibonacci Number: " << FibonacciNum << endl;
}

