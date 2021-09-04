#pragma once
#include "Matter.h"
#include <stdint.h>

#define HEIGHT 720
#define WIDTH 1280

//each block will have a size of 30x30 pixels
#define MAP_HEIGHT 23 // height of the playable map: HEIGHT / 30 (in number of blocks)
#define MAP_WIDTH 42 // width of the playable map: WIDTH / 30  (in number of blocks)

#define MAP_START_X 10 //this where the pixels of the playable map start in x position
#define MAP_START_Y 30 //this where the pixels of the playable map start in y position

#define MAP_END_X 1270 //this where the pixels of the playable map end in x position
#define MAP_END_Y 720  //this where the pixels of the playable map end in y position

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
		GameMap(uint32_t* framebuffer);

		//this will handle on the one block movement of the player object depending of the inputted direction
		void movePlayer(Direction to);

		//this will the attack action of the player object
		void attackPlayer();
		
};

