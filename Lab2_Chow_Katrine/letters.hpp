/*******************************************************************************
** Program Name: Lab 2: File I/O - letters.hpp
** Author: Katrine Chow
** Date: January 19, 2018
** Description:	This is the header file for the namespace Letters and its
**		members and functions.
*******************************************************************************/

#ifndef LETTERS_HPP
#define LETTERS_HPP

#include <fstream>

using std::ifstream;
using std::ofstream;

namespace Letters
{
	void count_letters(ifstream&, int*);
	void output_letters(ofstream&, int*);
}
#endif
