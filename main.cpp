/*******************************************************************
 * 				-Main-
 *
 * *****************************************************************/
#include "LoadedDie.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int numRounds;
	int numSides1;
	int numSides2;
	int regRoll1;
	int regRoll2;
	int LRoll1;
	int LRoll2;
	int p1Points;
	int p2Points;

	Game g;
	Die d;
	LoadedDie ld;

	//Call start menu to collect all data from user
	g.startMenu();

	numRounds = g.getNumRounds();
	for (int i= 1; i <= numRounds; i++)
    {



        /******************Player 1*********************************/
		//Call getNumSides1 to get number of sided die for player 1
		numSides1 = g.getNumSides1();//For player 1

		//Call reg die roll function to get return of random int
		d.setRoll(numSides1);//for player 1
		regRoll1 = d.regularDieRoll();

		ld.setRoll(numSides1);
		LRoll1 = ld.regularDieRoll();//for loaded die option

		/**********************Player 2********************************/
		numSides2 = g.getNumSides2();//Fore player 2

		d.setRoll(numSides2);//for player 2
		regRoll2 = d.regularDieRoll();

		ld.setRoll(numSides2);
		LRoll2 = ld.regularDieRoll();//loaded die

		numRounds = g.getNumRounds();

		cout << "__________________________________" << endl;
        cout << "\n            **  Round " << i << " **" << endl;//Kick off the Game!
		g.playGame(regRoll1, LRoll1, regRoll2, LRoll2);

	}

	p1Points = g.getP1Points();
	p2Points = g.getP2Points();

	cout << "__________________________________\n" << endl;
	cout << "\tPlayer 1 earned " << p1Points << " points.\n" << endl;
	cout << "\tPlayer 2 earned " << p2Points << " points.\n" << endl;
	if (p1Points > p2Points)
    {
        cout << "\n\t\t**** Player 1 won the game!!! ****\n" << endl;
    }

    else if (p1Points < p2Points)
    {
        cout << "\n\t\t**** Player 2 won the game!!! ****\n" << endl;
    }

	return 0;
}
