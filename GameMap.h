#pragma once
#include "Matter.h"
#include <stdint.h>

#define HEIGHT 480
#define WIDTH 640

//each block will have a size of 20x20 pixels
#define MAP_HEIGHT 24 // HEIGHT / 20, in number of blocks
#define MAP_WIDTH 32 // WIDTH / 20, in number of blocks

//direction for which the player will move
enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};

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
	
	public:
		GameMap();

		//this will return the internal frame buffer of the game map object
		uint32_t* getBufferReference();

		void movePlayer(Direction to);
		
};

