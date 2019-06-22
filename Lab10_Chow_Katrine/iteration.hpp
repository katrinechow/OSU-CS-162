/*******************************************************************************
** Program Name: Lab 10 - Recursive and Iterative Functions: iteration.hpp
** Author: Katrine Chow
** Date: March 12, 2018
** Description:	This is the header file for the Iteration class, which
**		contains an iterative function that calculates Fibonacci Numbers.
**		Code references "Fibonacci Recursive and Non Recursive C++" by
**		joseph.arul83@gmail.com, 18 Sept 2010,
**		www.codeproject.comtips/109443/fibonacci-recurseive-and-non-
**		recursive-c. (Referred by Professor Zhang in Lab 10 specs)
*******************************************************************************/

#ifndef ITERATION_HPP
#define ITERATION_HPP

class Iteration
{
	private:
		Iteration();
		long long int Fibonacci(const long long int &n);
		const long long int* n_;

	public:
		Iteration(const long long int &n);
		virtual ~Iteration();
		void printIteration();
};

#endif
