/*******************************************************************************
** Program Name: Lab 10 - Recursive and Iterative Functions: main.cpp
** Author: Katrine Chow
** Date: March 12, 2018
** Description:	This is the main driver code for the measure program. This
**		program measures and compares the running time of recursive
**		and iterative functions.
*******************************************************************************/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <string>
#include <sstream>

#include "iteration.hpp"
#include "recursion.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::setprecision;
using std::clock_t;
using std::clock;
using std::getline;
using std::stringstream;
using std::string;

int main()
{
	//Usage of long long int to store n courtesy of @477 on Piazza
	long long int n;
	bool flag = false;
	string str;

	while (flag == false)
	{
		//Limiting input range per @477 on Piazza
		//Larger n takes longer to run, so capping at 50
		cout << "Enter which Fibonacci Number to calculate"
		<< " (Integer from 0 through 50 only)" << endl;
		getline(cin, str);
		stringstream ss(str);

		if (ss >> n && !(ss >> str) && n >= 0 && n < 51)
		{
			flag = true;
		}
		else
		{
			cout << "Please enter a number from 0 through 50 only"
				<< endl;
			cout << endl;
		}
	}
	
	cout << "Finding " << n << "th " << "Fibonacci Number" << endl;
	
	//std::clock_t and std::clock() usage referenced the std::clock article
	//at http://en.cppreference.com/w/cpp/chrono/c/clock
	cout << endl;
	cout << "Calling Iterative Fibonacci function" << endl;
	clock_t istart = clock();
	Iteration it(n);
	it.printIteration();
	clock_t iend = clock();
	cout << endl;

	cout << fixed << setprecision(5) << "CPU time used: "
		<< 1000 * (iend - istart) / CLOCKS_PER_SEC << " ms" << endl;

	cout << endl;
	cout << "*************************************" << endl;
	cout << endl;
	cout << "Calling Recursive Fibonacci function" << endl;

	//std::clock_t and std::clock() usage referenced the std::clock article
	//at http://en.cppreference.com/w/cpp/chrono/c/clock
	clock_t rstart = clock();
	Recursion rf(n);
	rf.printRecursion();
	clock_t rend = clock();
	cout << endl;

	cout << fixed << setprecision(5) << "CPU time used: "
		<< 1000 * (rend - rstart) / CLOCKS_PER_SEC << " ms" << endl;

	cout << endl;

	return 0;
}
