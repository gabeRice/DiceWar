/*****************************************************************
 * Program Name:		--Dice War--
 * Author: Gabriel Rice
 * Date: 4/20/18
 * Description:			--LoadedDie.hpp---
 * This is the header file for the LoadedDie class.
 * ***************************************************************/
#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP
#include "Die.hpp"

class LoadedDie : public Die//inheritance statement
{
	private:
			int N;
			int randInt;

	public:
			LoadedDie();
			void setRoll(int);
			int regularDieRoll();
};
#endif
