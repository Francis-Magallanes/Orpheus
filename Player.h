#pragma once
#include "Matter.h"
#include "dependencies/CImg.h"
#include <stdint.h>

class Player : public Matter {
	
	private: 
		Direction playerFacing; //this will monitor where the player object is currently facing
		int attackDamage;
		uint32_t* PLAYER_SPRITE_RIGHT; // sprite for when the player facing to the right

	public:
		//Constructor
		Player();

		//Destructor
		~Player();

		//this will get the 20x20 pixel sprite from the player object in one-dimensional array
		uint32_t* getSprite();

		//this will set the direction for which the player object is currently facing
		//it will also update its sprite according to its direction
		void setNewDirectionFacing(Direction newDir);

		//this is for handling any "damage" (i.e. player's attack) towards the object
		void absorbDamage(int damage);

		//this will get the value of playerFacing
		Direction getPlayerFacing();

		//this will get the value of attackDamage
		int getAttackDamage();
};

