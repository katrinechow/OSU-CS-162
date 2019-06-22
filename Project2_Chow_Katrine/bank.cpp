/*******************************************************************************
** Program Name: Project 2 - Zoo Tycoon: bank.cpp
** Author: Katrine Chow
** Date: January 30, 2018
** Description:	This is the implementation file for class Bank. It defines the
**		functions to get bank total, make a deposit and a withdrawal.
*******************************************************************************/

#include "bank.hpp"

/*******************************************************************************
**				Bank::Bank()
** Description:	This is the default constructor, which starts the player off
**		with $100,000 in the bank.
*******************************************************************************/
Bank::Bank()
{
	total = 100000;
}


/*******************************************************************************
**				Bank::getTotal()
** Description:	This function returns the current total the player has in the
**		bank.
*******************************************************************************/

double Bank::getTotal()
{
	return total;
}


/*******************************************************************************
**				Bank::makeDeposit(double)
** Description:	This function adds to the player's bank total.
*******************************************************************************/

void Bank::makeDeposit(double dmoney)
{
	total = total + dmoney;
}


/*******************************************************************************
**				Bank::makeWithdrawal(double)
** Description:	This function subtracts from the player's bank total.
*******************************************************************************/

void Bank::makeWithdrawal(double wmoney)
{
	total = total - wmoney;
}
