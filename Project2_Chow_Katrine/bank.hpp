/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: bank.hpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the header file for class Bank, which controls all the
**		monetary transactions that happen during the game.
*******************************************************************************/

#ifndef BANK_HPP
#define BANK_HPP

class Bank
{
	private:
		double total;

	public:
		Bank(); //Default constructor
		double getTotal();
		void makeDeposit(double);
		void makeWithdrawal(double);
};

#endif
