/*******************************************************************************
** Program Name - Stack and Queue STL Containers: buffer.hpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the header file for class Buffer, which contains a
**		STL Queue container that will simulate a buffer and display its
**		contents.
*******************************************************************************/
#ifndef BUFFER_HPP
#define BUFFER_HPP

#include <queue>
#include <string>

using std::string;
using std::queue;

class Buffer
{
	private:
		queue<int> buffersim;
		queue<int> tempbuffer;
		int round;
		int N;
		int append;
		int remove;
		double avglen;

	public:
		Buffer();
		int intValidation(string);
		void setRound();
		int getRound();
		void setN();
		int getN();
		void setAppend();				
		void setRemove();
		void avgLength(int);
		void printBuffer();

};
#endif
