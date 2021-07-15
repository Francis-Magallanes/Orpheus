#pragma once
#include "dependencies/CImg.h"
#include <stdint.h>

#define LIGHT 0xEEDD82
#define DARK 0x000000

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
		uint32_t* sprite; //this will be used to store the sprite

	public:

		//this will get the 20x20 pixel sprite from the object in one-dimensional array
		virtual uint32_t* getSprite() = 0;

		//this is for handling any "damage" (i.e. player's attack) towards the object
		virtual void absorbDamage(int damage) = 0;

		//this will get the value of the hitpoints
		int getHitpoints() {
			return hitpoints;
		}
};

