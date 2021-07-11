#include "GameMap.h"
#include "Slab.h"
#include "Player.h"

#include <stdlib.h>
#include <iostream>

//This will be one of the maze maps for the game
//This indicates where the slab object to be placed with its type
// 1 represents the diamond slab
// 2 represents the concrete slab
// 3 represents the wood slab
int MAZE_1[MAP_HEIGHT][MAP_WIDTH] = {
	
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1, 1, 1},
	{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0, 0, 1},
	{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0, 0, 1},
	{1,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	2,	0,	0,	0,	3,	0,	0,	0,	3,	0,	0,	2,	0,	0,	0,	2,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	1,	0,	0,	0,	0,	2,	0,	0,	0,	3,	0,	0,	0,	3,	0,	0,	2,	0,	0,	0,	2,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	1,	0,	0,	0,	0,	2,	0,	0,	0,	3,	3,	3,	3,	3,	0,	0,	2,	2,	2,	2,	2,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	2,	0,	0,	0,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	2,	2,	2,	2,	2,	0,	0,	2,	0,	0,	0,	3,	0,	0,	3,	3,	3,	3,	3,	3,	3,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	2,	2,	2,	2,	2,	0,	0,	2,	0,	0,	0,	3,	0,	0,	2,	2,	2,	2,	2,	2,	2,	1,	0,	0,	1,	1, 1, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	2,	2,	2,	2,	3,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	2,	2,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	3,	3,	3,	3,	3,	3,	2,	2,	2,	2,	2,	2,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	3,	3,	3,	3,	3,	3,	2,	2,	2,	2,	2,	2,	0,	0,	1,	0,	3,	3,	3, 3, 1},
	{1,	0,	0,	3,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	2,	2,	0,	0,	0,	0,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	3,	3,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0, 0, 1},
	{0,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	3,	3,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0, 0, 1},
	{1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	3,	3,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0, 0, 0},
	{1,	0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	3,	3,	0,	0,	0,	0,	0,	0,	1,	1,	1,	0,	0,	0,	0, 0, 1},
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	0,	1,	1,	1,	1,	1,	1,	1,	1,	1, 1, 1}

};

GameMap::GameMap() {
	
	//initialize the game map buffer with black pixels
	gamemapBuffer = (uint32_t*)malloc(HEIGHT * WIDTH * 4);
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++)
			gamemapBuffer[WIDTH * i + j] = 0x000000;

	//initialize the game map with MAZE_1
	map = new Matter ** [MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map[i] = new Matter * [MAP_WIDTH];

		for (int j = 0; j < MAP_WIDTH; j++)
			
			if (MAZE_1[i][j] == 1) {
				//instantiate a diamond slab object
				map[i][j] = new Slab(TypeSlab::DIAMOND);
			}
			else if (MAZE_1[i][j] == 2) {
				//instantiate a concrete slab object
				map[i][j] = new Slab(TypeSlab::CONCRETE);
			}
			else if (MAZE_1[i][j] == 3) {
				//instantiate a wood slab object
				map[i][j] = new Slab(TypeSlab::WOOD);
			}
			else {
				//this signifies that it is an empty space for the player to move in
				map[i][j] = NULL;
			}
			
	}
		
	//Place the player in the map at (1,1)
	playerPos.X = 0;
	playerPos.Y = 20;
	map[playerPos.Y][playerPos.X] = new Player();
	
	updateBuffer();

}

uint32_t* GameMap::getBufferReference() {
	return gamemapBuffer;
}

void GameMap::movePlayer(Direction to) {

	if (to == Direction::DOWN and playerPos.Y + 1 < MAP_HEIGHT) {

		//the player can only move towards a empty space in the map (or null value in the map variable) and within provided space
		if (!map[playerPos.Y + 1][playerPos.X]) {

			//this will get the sprite of the object before updating
			uint32_t* sprite_mat = map[playerPos.Y][playerPos.X]->getSprite();

			//this will move the player in game map array
			map[playerPos.Y + 1][playerPos.X] = map[playerPos.Y][playerPos.X];
			map[playerPos.Y][playerPos.X] = NULL;
			
			//update the player postion
			playerPos.Y = playerPos.Y + 1;
			
			//update the buffer
			//this will get the surroundings of the character (distance is 2 blocks)
			updateBuffer();

			//delete the upper portion
			if (playerPos.Y - 3 >= 0) {

				for (int i = 0; i < 5; i++) {

					if ((playerPos.X - 2 + i) < MAP_WIDTH and (playerPos.X - 2 + i) >= 0) {
						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * ((playerPos.Y - 3) * 20 + k) + (((playerPos.X - 2 + i) * 20) + l)] = 0x000000;

							}
						}
					}

				}
			}
			
			
		}

	}
	else if (to == Direction::UP and playerPos.Y - 1 >= 0 ) {

		//the player can only move towards a empty space in the map (or null value in the map variable) and within provided space
		if (!map[playerPos.Y - 1][playerPos.X]) {
			
			//this will get the sprite of the object before updating
			uint32_t* sprite_mat = map[playerPos.Y][playerPos.X]->getSprite();

			//this will move the player in game map array
			map[playerPos.Y - 1][playerPos.X] = map[playerPos.Y][playerPos.X];
			map[playerPos.Y][playerPos.X] = NULL;

			//update the player postion
			playerPos.Y = playerPos.Y - 1;

			//update the buffer
			//this will get the surroundings of the character (distance is 2 blocks)
			updateBuffer();

			//delete the lower portion
			if (playerPos.Y + 3 < MAP_HEIGHT) {

				for (int i = 0; i < 5; i++) {

					if ((playerPos.X - 2 + i) < MAP_WIDTH and (playerPos.X - 2 + i) >= 0) {

						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * ((playerPos.Y + 3) * 20 + k) + (((playerPos.X - 2 + i) * 20) + l)] = 0x000000;

							}
						}
					}

				}
			}

			
		}

	}
	else if (to == Direction::RIGHT and playerPos.X + 1 < MAP_WIDTH) {

		//the player can only move towards a empty space in the map (or null value in the map variable) and within provided space
		if (!map[playerPos.Y][playerPos.X + 1]) {

			//this will get the sprite of the object before updating
			uint32_t* sprite_mat = map[playerPos.Y][playerPos.X]->getSprite();

			//this will move the player in game map array
			map[playerPos.Y][playerPos.X + 1] = map[playerPos.Y][playerPos.X];
			map[playerPos.Y][playerPos.X] = NULL;

			//update the player postion
			playerPos.X = playerPos.X + 1;

			//update the buffer
			//this will get the surroundings of the character (distance is 2 blocks)
			updateBuffer();

			//delete the left portion
			if (playerPos.X - 3 >= 0) {

				for (int y = 0; y < 5; y++) {

					if ((playerPos.Y - 2 + y) < MAP_HEIGHT and (playerPos.Y - 2 + y) >= 0) {

						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * (((playerPos.Y - 2 + y) * 20) + k) + (((playerPos.X - 3) * 20) + l)] = 0x000000;

							}
						}
					}

				}

			}


		}

	}
	else if (playerPos.X - 1 >= 0){

		//for the left move
		//the player can only move towards a empty space in the map (or null value in the map variable) and within provided space
		if (!map[playerPos.Y][playerPos.X - 1]) {

			//this will get the sprite of the object before updating
			uint32_t* sprite_mat = map[playerPos.Y][playerPos.X]->getSprite();

			//this will move the player in game map array
			map[playerPos.Y][playerPos.X - 1] = map[playerPos.Y][playerPos.X];
			map[playerPos.Y][playerPos.X] = NULL;

			//update the player postion
			playerPos.X = playerPos.X - 1;

			//update the buffer
			updateBuffer();

			//delete the rightmost part
			if (playerPos.X + 3 >= 0) {

				for (int y = 0; y < 5; y++) {

					if ((playerPos.Y - 2 + y) < MAP_HEIGHT and (playerPos.Y - 2 + y) >= 0) {

						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * (((playerPos.Y - 2 + y) * 20) + k) + (((playerPos.X + 3) * 20) + l)] = 0x000000;

							}
						}
					}
					
				}

			}

		}

	}

}

void GameMap::updateBuffer() {

	for (int i = 0; i < 5; i++) {


		if ((playerPos.Y - 2) + i >= 0 and (playerPos.Y - 2) + i < MAP_HEIGHT) {

			for (int j = 0; j < 5; j++) {

				if ((playerPos.X - 2) + j >= 0 and (playerPos.X - 2) + j < MAP_WIDTH) {

					if (map[(playerPos.Y - 2) + i][(playerPos.X - 2) + j]) {
						//put the sprite in the buffer if there is an object on it

						uint32_t* sprite_mat = map[(playerPos.Y - 2) + i][(playerPos.X - 2) + j]->getSprite();

						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * ((((playerPos.Y - 2) + i) * 20) + k) + ((((playerPos.X - 2) + j) * 20) + l)] = sprite_mat[20 * k + l];

							}
						}

					}
					else {

						//for the null
						for (int k = 0; k < 20; k++) {

							for (int l = 0; l < 20; l++) {

								gamemapBuffer[WIDTH * ((((playerPos.Y - 2) + i) * 20) + k) + ((((playerPos.X - 2) + j) * 20) + l)] = 0x000000;

							}
						}

					}

				}


			}

		}

	}
}