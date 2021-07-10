#pragma once
#include "Matter.h"
#include <stdint.h>

#define HEIGHT 480
#define WIDTH 640

#define MAP_HEIGHT 24 // HEIGHT / 20
#define MAP_WIDTH 32 // WIDTH / 20

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

		//this will give the image version of the game map variable
		uint32_t* getBufferReference();

		void movePlayer(Direction to);
		
};

