#include "GameMap.h"
#include "Slab.h"
#include "Player.h"

#include <stdlib.h>
#include <iostream>

GameMap::GameMap() {
	
	//initialize the game map buffer
	gamemapBuffer = (uint32_t*)malloc(HEIGHT * WIDTH * 4);

	//initialize the game map
	map = new Matter ** [MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map[i] = new Matter * [MAP_WIDTH];

		for (int j = 0; j < MAP_WIDTH; j++)
			map[i][j] = NULL;
	}
		
		
		
	//putting objects in the map variable
	//a simple square around the screen
	for (int h = 0; h < MAP_WIDTH; h++)
		map[0][h] =  new Slab(TypeSlab::DIAMOND);

	for (int h = 0; h < MAP_WIDTH; h++)
		map[MAP_HEIGHT-1][h] = new Slab(TypeSlab::WOOD);

	for (int i = 0; i < MAP_HEIGHT - 2; i++)
		map[i+1][0] = new Slab(TypeSlab::CONCRETE);
	
	for (int i = 0; i < MAP_HEIGHT - 2; i++)
		map[i + 1][MAP_WIDTH - 1] = new Slab(TypeSlab::DIAMOND);


	//Place the player in the map at (1,1)
	playerPos.X = 2;
	playerPos.Y = 2;
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

	if (to == Direction::DOWN) {

		//the player can only move towards a empty space in the map (or null value in the map variable)
		//Also, the 
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
	else if (to == Direction::UP) {

		//the player can only move towards a empty space in the map (or null value in the map variable)
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
	else if (to == Direction::RIGHT) {

		//the player can only move towards a empty space in the map (or null value in the map variable)
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
	else {

		//for the left move
		//the player can only move towards a empty space in the map (or null value in the map variable)
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