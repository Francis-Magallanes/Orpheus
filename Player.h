#pragma once
#include "Matter.h"
#include <stdint.h>

class Player : public Matter {
	
	private: 
		uint32_t* sprite; //this will be used to store the sprite

	public:
		//Constructor
		Player();

		//Destructor
		~Player();

		//this will get the 20x20 pixel sprite from the player object in one-dimensional array
		uint32_t* getSprite();

};

