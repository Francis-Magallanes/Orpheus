#pragma once
#include <stdint.h>

//direction for which the player will move
enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

class Matter
{
	protected:
		int hitpoints;

	public:

		//this will get the 20x20 pixel sprite from the object in one-dimensional array
		virtual uint32_t* getSprite() = 0;

};

