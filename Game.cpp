#include "Game.hpp"
#include <iostream>
#include <limits>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::numeric_limits;
using std::string;
using std::streamsize;

Game::Game()
{
    choice = 0;
    numRounds = 0;
    dieType1 = 0;
    dieType2 = 0;
    numSides1 = 0;
    numSides2 = 0;
    rollResult1 = 0;
    rollResult2 = 0;
    p1Points = 0;
    p2Points = 0;
    totalPts1 = 0;
    totalPts2 = 0;
}

int Game::getNumRounds()
{
	return numRounds;
}

int Game::getNumSides1()//for player 1
{
	return numSides1;
}

int Game::getNumSides2()//for player 2
{
	return numSides2;
}

int Game::getP1Points()
{
    return p1Points;
}

int Game::getP2Points()
{
    return p2Points;
}

/******************************************************************
 * Description: This function initiates the game.
 * **************************************************************/
void Game::playGame(int roll1, int LRoll1, int roll2, int LRoll2)
{
	//Prompt player 1 to roll
	cout << "\nPlayer 1, enter 1 to roll" << endl;
	cin >> choice;

	while (!(choice == 1))
	{
		cout << "***** Invalid Entry *****\n" << endl;
		cout << "Player 1, enter 1 to roll" << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}


	if (dieType1 == 1)//if regular die for player 1
	{
		//call on regularDie func from Die class
		//returns random int

		rollResult1 = roll1;
		typeDie1 = "regular";
	}

	else if(dieType1 == 2)//if loaded die for player 1
	{
		//call on loadDie func from loadDie class
		//returns random int, however, loaded

		rollResult1 = LRoll1;
		typeDie1 = "loaded";
	}

	//Player 2's turn
	cout << "\nPlayer 2, enter 2 to roll" << endl;
	cin >> choice;

	while (!(choice == 2))
	{
		cout << "***** Invalid Entry *****\n" << endl;
		cout << "Player 2, enter 2 to roll" << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}

	if (dieType2 == 1)//if regular die for player 2
	{
		//call on regularDie func from Die class
		//returns random int

		rollResult2 = roll2;
		typeDie2 = "regular";
	}

	else if(dieType2 == 2)//if loaded die for player 2
	{
		//call on loadDie func from loadDie class
		//returns random int, however, loaded

		rollResult2 = LRoll2;
		typeDie2 = "loaded";
	}

    cout << "\n\tPlayer 1 rolled a -----> " << rollResult1 <<
            "\n \tWith a " << numSides1 << " sided " << typeDie1 << " die.\n" << endl;
    cout << "\n\tPlayer 2 rolled a -----> " << rollResult2 <<
            "\n \tWith a " << numSides2 << " sided " << typeDie2 << " die.\n" << endl;



	if (rollResult1 > rollResult2)
    {
        cout << "\t\t\t\t** Winner: Player 1! **" << endl;
        p1Points += 1;
    }

    else if (rollResult1 < rollResult2)
    {
        cout << "\t\t\t\t** Winner: Player 2! **" << endl;
        p2Points += 1;
    }

    else
        cout << "\t\t\t\t** It's a Draw! **" << endl;
}


/*************************************************************************
 * Description: This function gathers user inputs as data for the game.
 * ***********************************************************************/
void Game::startMenu()
{
	cout << "Enter 1 to play game" << endl;
	cout << "Enter 2 to exit" << endl;
	cin >> choice;

	while (!(choice == 1 || choice == 2))
	{
		cout << "Invalid Choice\n" << endl;
		cout << "Enter 1 to play game" << endl;
		cout << "Enter 2 to exit" << endl;

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> choice;
	}

	if (choice == 1)
	{
		while (cout << "\nHow many rounds would you like to play?\n" &&
			(!(cin >> numRounds) || numRounds < 1))
		{
			cout << "Enter a positive integer greater than 1\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		cout << "\nPlayer 1, what type of die?\nEnter 1 for Regular or 2 for Loaded:\n" << endl;
		cin >> dieType1;

		while (!(dieType1 == 1 || dieType1 == 2))
		{
			cout << "Invalid Choice\n" << endl;
			cout << "Enter 1 for regular" << endl;
			cout << "Enter 2 for loaded" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> dieType1;
		}

		cout << "\nPlayer 2, what type of die?\nEnter 1 for Regular or 2 for Loaded:\n" << endl;
		cin >> dieType2;

		while (!(dieType2 == 1 || dieType2 == 2))
		{
			cout << "Invalid Choice\n" << endl;
			cout << "Enter 1 for regular" << endl;
			cout << "Enter 2 for loaded" << endl;

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> dieType2;
		}

		while (cout << "\nPlayer 1, Enter the number of sides for your die:\n" &&
			(!(cin >> numSides1) || numSides1 < 4))
		{
			cout << "The smallest die is 4!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}

		while (cout << "\nPlayer 2, Enter the number of sides for your die:\n" &&
			(!(cin >> numSides2) || numSides2 < 4) && (numSides2 != numSides1))
		{
			cout << "You must pick a die larger than 4 and different than Player 1!\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

