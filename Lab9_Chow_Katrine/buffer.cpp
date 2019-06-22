/*******************************************************************************
** Program Name: Lab 9 - Stack and Queue STL Containers: buffer.cpp
** Author: Katrine Chow
** Date: March 9, 2018
** Description:	This is the implementation of the buffer queue, which adds or
**		removes random integers based on a user-selected percentage.
*******************************************************************************/
#include <queue>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "buffer.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::showpoint;
using std::fixed;
using std::queue;
using std::setprecision;

/*******************************************************************************
**			Buffer::Buffer()
** Description:	This is the default constructor of class Buffer. It initializes
**		the integer variables.
*******************************************************************************/
Buffer::Buffer()
{
	round = 0;
	N = 0;
	append = 0;
	remove = 0;
	avglen = 0.0;
}


/*******************************************************************************
**			Buffer::intValidation(string)
** Description: This function validates user-input integers. This references
**		SkyeShatter's YouTube video at:
**		https://youtube.com/watch?v=S3_jCTb3fm0 as well as @86 on
**		Piazza.
*******************************************************************************/
int Buffer::intValidation(string a)
{
	string str;
	int valid;
	bool flag = false;

	while(flag == false)
	{
		cout << a << endl;
		getline(cin, str);
		stringstream ss(str);

		if(ss >> valid && !(ss >> str))
		{
			flag = true;
		}
		else
		{
			cout << ">>> Please enter an integer only <<<" << endl;
			cout << endl;
		}
	}

	return valid;
}


/*******************************************************************************
**			Buffer::setRound()
** Description:	This function sets the number of rounds the simulation will run.
*******************************************************************************/
void Buffer::setRound()
{
	string a = "Enter the number of rounds (Maximum 10)";
	int num = intValidation(a);

	while(num > 10 || num <=0)
	{
		string x = "Please choose a number 1 and 10";
		num = intValidation(x);
	}

	round = num;
}


/*******************************************************************************
**			Buffer::getRound()
** Description:	This function returns the rounds value.
*******************************************************************************/
int Buffer::getRound()
{
	return round;
}


/*******************************************************************************
**			Buffer::setN()
** Description:	This function generates a random number from 1 to 1000.
*******************************************************************************/
void Buffer::setN()
{
	N = rand() % 1000 + 1;
	cout << "N is: " << N << endl;
}


/*******************************************************************************
**			Buffer::getN()
** Description:	This function returns the value of N.
*******************************************************************************/
int Buffer::getN()
{
	return N;
}


/*******************************************************************************
**			Buffer::setAppend()
** Description:	This function generates random number from 1 to 100
*******************************************************************************/
void Buffer::setAppend()
{
	cout << endl;
	string b = "Enter percentage chance of appending N: ";
	int num2 = intValidation(b);

	append = rand() % 100 + 1;
	if(append <= num2)
	{
		buffersim.push(getN());
	}
}


/*******************************************************************************
**			Buffer::setRemove()
** Description:	This function generates random number from 1 to 100
*******************************************************************************/
void Buffer::setRemove()
{
	cout << endl;
	string c = "Enter percentage chance of removing N: ";
	int num3 = intValidation(c);

	remove = rand() % 100 + 1;
	if(remove <= num3)
	{
		buffersim.pop();
	}
}


/*******************************************************************************
**			Buffer::avgLength(int)
** Description:	This function calculates the average length for current loop.
*******************************************************************************/
void Buffer::avgLength(int index)
{
	if(buffersim.size() == 1)
	{
		avglen = (avglen * (index - 1.0) + 1.0) / index;
	}
	else
	{
		avglen = (avglen * (index - 1.0) + buffersim.size()) / index;
	}

}


/*******************************************************************************
**			Buffer::printBuffer();
** Description:	This function prints the current buffer.
*******************************************************************************/
void Buffer::printBuffer()
{
	if(buffersim.empty())
	{
		cout << endl;
		cout << "Buffer is empty" << endl;
	}
	else
	{
		if(buffersim.empty())
		{
			cout << "Buffer is empty" << endl;
		}
		else
		{
			cout << endl;
			cout << "The current buffer contains: " << endl;

			int size = buffersim.size();
		
			//Print contents of buffer
			//Queue copy referenced Stack Overflow
			//stackoverflow.com/questions/22280318/how-do-i-print-
			//a-queue
			for (int i = 0; i < size; i++)
			{
				cout << buffersim.front() << " ";
				tempbuffer.push(buffersim.front());
				buffersim.pop();
				buffersim.push(tempbuffer.back());
			}

			//Output length of buffer
			cout << endl;
			cout << endl;
			cout << "Buffer size is: " << size << endl;
			cout << endl;

			//Output Average length of buffer
			cout << "Average length of buffer is: ";
			cout << fixed << showpoint;
			cout << setprecision(3);
			cout << avglen << endl;

		}
	}
}				
