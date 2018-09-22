/*******************************************************************
 * Program Name:		--Dice War--
 * Author: Gabriel Rice
 * Date: 4/20/18
 * Description:			--Die.cpp--
 * This is the implementation file for the Die class.
 * ****************************************************************/
#include "Die.hpp"
#include <cstdlib>
#include <ctime>

/******************************************************************
 * Description: This function produces 1 random number each time
 * it is called using the system clock to seed numbers that change
 * each second.
 * ****************************************************************/

Die::Die()
{
	N = 0;
	randInt = 0;
}

void Die::setRoll(int numSides)
{
	N = numSides;
}

int Die::regularDieRoll()
{
	srand(time(0));

	for (int x = 1; x < N; x++)
		randInt = 1 + (rand() % N);

	return randInt;
}
