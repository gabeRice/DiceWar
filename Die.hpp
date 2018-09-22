/*****************************************************************************
 * Program Name:	--Dice War--
 * Author: Gabriel Rice
 * Date: 4/20/18
 * Description:		--Die.hpp--
 * 
 * This is the header file for the Die class.
 * **************************************************************************/
#ifndef DIE_HPP
#define DIE_HPP
#include "Game.hpp"

class Die
{
	private:
			int N;
			int randInt;

	public:
			Die();
			void setRoll(int);
			int regularDieRoll();
			
};
#endif				
