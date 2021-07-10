#include "GameMap.h"
#include "Slab.h"
#include "Player.h"

#include <stdlib.h>
#include <iostream>

//This will be one of the maze maps for the game
//This indicates where the slab object to be placed and its type
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
	
	//initialize the game map buffer
	gamemapBuffer = (uint32_t*)malloc(HEIGHT * WIDTH * 4);

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
	


	//initialize the game map buffer based from the initialized game map array
	for (int i = 0; i < MAP_HEIGHT; i++) {

		for (int j = 0; j < MAP_WIDTH; j++) {

			if (map[i][j]) {

				uint32_t* sprite_mat = map[i][j]->getSprite();

				for (int k = 0; k < 20; k++) {

					for (int l = 0; l < 20; l++) {

						gamemapBuffer[WIDTH * ((i * 20) + k) + ((j * 20) + l)] = sprite_mat[20 * k + l];

					}
				}

			}
			else {

				//for the null
				for (int k = 0; k < 20; k++) {

					for (int l = 0; l < 20; l++) {

						gamemapBuffer[WIDTH * ((i * 20) + k) + ((j * 20) + l)] =0x000000;

					}
				}
			}

		}
	}

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

			
			for (int i = 0; i < 20; i++) {

				for (int j = 0; j < 20; j++) {

					gamemapBuffer[ (WIDTH * ( ( (playerPos.Y + 1) * 20) + i)) + ((playerPos.X * 20) + j)] = sprite_mat[20 * i + j];
					gamemapBuffer[(WIDTH * (((playerPos.Y) * 20) + i)) + ((playerPos.X * 20) + j)] = 0x000000;
				}
			}

			//update the player postion
			playerPos.Y = playerPos.Y + 1;
			
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


			for (int i = 0; i < 20; i++) {

				for (int j = 0; j < 20; j++) {

					gamemapBuffer[(WIDTH * (((playerPos.Y - 1) * 20) + i)) + ((playerPos.X * 20) + j)] = sprite_mat[20 * i + j];
					gamemapBuffer[(WIDTH * (((playerPos.Y) * 20) + i)) + ((playerPos.X * 20) + j)] = 0x000000;
				}
			}

			//update the player postion
			playerPos.Y = playerPos.Y - 1;
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

			
			for (int i = 0; i < 20; i++) {

				for (int j = 0; j < 20; j++) {

					gamemapBuffer[(WIDTH * ((playerPos.Y * 20) + i)) + (( (playerPos.X + 1) * 20) + j)] = sprite_mat[20 * i + j];
					gamemapBuffer[(WIDTH * (((playerPos.Y) * 20) + i)) + ((playerPos.X * 20) + j)] = 0x000000;
				}
			}

			//update the player postion
			playerPos.X = playerPos.X + 1;


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


			for (int i = 0; i < 20; i++) {

				for (int j = 0; j < 20; j++) {

					gamemapBuffer[(WIDTH * ((playerPos.Y * 20) + i)) + (((playerPos.X - 1) * 20) + j)] = sprite_mat[20 * i + j];
					gamemapBuffer[(WIDTH * (((playerPos.Y) * 20) + i)) + ((playerPos.X * 20) + j)] = 0x000000;
				}
			}


			//update the player postion
			playerPos.X = playerPos.X - 1;

		}

	}

}