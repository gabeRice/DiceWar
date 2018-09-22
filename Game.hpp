#ifndef GAME_HPP
#define GAME_HPP
#include <string>

class Game
{
    private:
            int choice,
                numRounds,
                dieType1,
                dieType2,
                numSides1,
                numSides2,
                rollResult1,
                rollResult2,
                p1Points,
                p2Points,
                totalPts1,
                totalPts2;
            std::string typeDie1;
            std::string typeDie2;

    public:
            Game();
            void startMenu();//collects user data
            void playGame(int, int, int, int);//game starts
            int calcTotalPts();
			void setNumSides1(int);
			int getNumSides1();
			int getNumSides2();
			int getNumRounds();
			int getP1Points();
			int getP2Points();

};

#endif
