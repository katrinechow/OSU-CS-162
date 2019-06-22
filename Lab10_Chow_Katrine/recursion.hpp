/*******************************************************************************
** Program Name: Lab 10 - Recursive and Iterative Functions: recursion.hpp
** Author: Katrine Chow
** Date: March 12, 2018
** Description:	This is the header file for the Recursion class, which
**		contains an recursive function that calculates Fibonacci Numbers.
**		Code references "Fibonacci Recursive and Non Recursive C++" by
**		joseph.arul83@gmail.com, 18 Sept 2010,
**		www.codeproject.comtips/109443/fibonacci-recurseive-and-non-
**		recursive-c. (Referred by Professor Zhang in Lab 10 specs)
*******************************************************************************/

#ifndef RECURSION_HPP
#define RECURSION_HPP

class Recursion
{
	private:
		Recursion();
		long long int Fibonacci(const long long int &n);
		const long long int *n_;

	public:
		Recursion(const long long int &n);
		virtual ~Recursion();
		void printRecursion();
};

#endif
