#pragma once
#include "Matter.h"
#include <stdint.h>

#define HEIGHT 720
#define WIDTH 1280

//each block will have a size of 20x20 pixels
#define MAP_HEIGHT 23 // HEIGHT / 20, in number of blocks
#define MAP_WIDTH 42 // WIDTH / 20, in number of blocks


struct Coordinate {
	int X;
	int Y;
};


class GameMap
{
	private:
		//this will contain the different objects inside the game map
		// it is in two dimensional scheme for easier access of the objects
		Matter*** map;
		uint32_t* gamemapBuffer;

		Coordinate playerPos; // this will store the position of the player in the map
		
		//this will update the buffer when the player object moves
		//this will get the surroundings of the character (distance is 2 blocks) for the display
		void updateBuffer();

	public:
		GameMap();

		//this will return the internal frame buffer of the game map object
		uint32_t* getBufferReference();

		//this will handle on the one block movement of the player object depending of the inputted direction
		void movePlayer(Direction to);

		//this will the attack action of the player object
		void attackPlayer();
		
};

