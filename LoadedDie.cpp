/********************************************************************
 * Program Name:		--Die Wars--
 * Author: Gabriel Rice
 * Date: 4/19/18
 * Description:			--LoadedDie.cpp
 *
 * This is the implementation file for the LoadedDie class.
 * *****************************************************************/
#include "LoadedDie.hpp"
#include <cstdlib>
#include <ctime>

LoadedDie::LoadedDie()
{
	N = 0;
	randInt = 0;
}

 void LoadedDie::setRoll(int numSides)
{
	N = numSides;
}

/*****************************************************************
 * Description: This is a redefinition of the regularDieRoll
 * function from the Die class, which has been inherited here, to
 * make it loaded by adding 3.
 * *********************************************************8****/
int LoadedDie::regularDieRoll()
{
	srand(time(0));

	for (int x = 3; x < N; x++)
    {
        randInt = 1 + (rand() % N);
    }

	return randInt;
}
