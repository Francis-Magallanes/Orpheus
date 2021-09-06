#include "Definitions.h"


//This will be one of the maze maps for the game
//This indicates where the slab object to be placed with its type
// 1 represents the diamond slab
// 2 represents the concrete slab
// 3 represents the wood slab
// 4 represents collectable
// 5 represents Player or cerberus
// 6 represents the heal
// 7 represents the trap
// 8 represents the weapon
int MAZE_1[MAP_HEIGHT][MAP_WIDTH] = {
	
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1},
	{1,	8,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	2,	1,	2,	2,	2,	2,	2,	2,	1,	-1,	-1,	6,	-1,	-1,	-1,	-1,	7,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	1,	3,	3,	3,	-1,	1},
	{1,	-1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	1,	2,	1,	2,	1,	1,	1,	1,	2,	1,	-1,	-1,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	-1,	-1,	1,	1,	3,	1,	-1,	-1,	1},
	{1,	-1,	3,	7,	3,	-1,	-1,	-1,	-1,	1,	2,	1,	2,	1,	2,	2,	1,	2,	1,	-1,	-1,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	3,	-1,	-1,	1,	1,	3,	1,	6,	-1,	1},
	{1,	-1,	-1,	3,	6,	-1,	2,	-1,	-1,	1,	2,	1,	7,	1,	1,	2,	1,	7,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	6,	-1,	-1,	-1,	-1,	1,	1,	3,	1,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	2,	7,	2,	-1,	-1,	2,	1,	2,	2,	2,	2,	1,	2,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	7,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	3,	3,	1,	-1,	-1,	1},
	{1,	-1,	-1,	3,	-1,	-1,	2,	-1,	-1,	-1,	2,	1,	1,	1,	1,	1,	1,	2,	1,	-1,	-1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	-1,	-1,	1,	2,	1,	1,	-1,	6,	1},
	{1,	-1,	3,	7,	3,	-1,	-1,	-1,	-1,	-1,	2,	2,	2,	2,	2,	7,	2,	2,	1,	-1,	-1,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	2,	-1,	-1,	1,	4,	1,	1,	-1,	-1,	1},
	{1,	6,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	6,	-1,	-1,	-1,	1,	1,	1,	1,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	1,	1,	1,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	6,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	3,	3,	-1,	-1,	2,	2,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1},
	{1,	3,	3,	3,	3,	3,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	1,	1,	3,	3,	3,	1,	1,	1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	-1,	-1,	1},
	{1,	3,	3,	3,	3,	3,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	-1,	-1,	6,	7,	-1,	-1,	-1,	1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	2,	2,	2,	2,	2,	2,	1,	-1,	2,	2,	2,	2,	2,	-1,	1,	-1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	2,	2,	2,	2,	2,	2,	1,	-1,	2,	3,	3,	3,	2,	-1,	1,	-1,	-1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	1},
	{1,	3,	3,	3,	3,	3,	3,	-1,	6,	-1,	-1,	-1,	-1,	-1,	1,	-1,	2,	3,	4,	3,	2,	-1,	1,	-1,	-1,	-1,	-1,	3,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1},
	{1,	3,	3,	3,	3,	3,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	-1,	2,	3,	3,	3,	2,	6,	1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1},
	{1,	-1,	-1,	-1,	-1,	6,	-1,	6,	2,	2,	2,	2,	2,	2,	1,	-1,	2,	2,	2,	2,	2,	-1,	1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	-1,	-1,	-1,	-1,	-1, -1,	-1,	-1,	-1,	-1,	1},
	{1,	4,	-1,	-1,	-1,	-1,	-1,	-1,	2,	2,	2,	2,	2,	2,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	1,	-1,	-1,	-1,	-1,	-1,	-1,	-1,	3,	-1,	-1,	-1,	1,	5,	1,	-1,	-1,	-1,	8,	1},
	{1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1,	1}

};

GameMap::GameMap(uint32_t* framebuffer) {
	
	int collectable_counter = 1;

	//initialize the game map buffer with black pixels
	gamemapBuffer = framebuffer;

	memset(gamemapBuffer, 0, HEIGHT * WIDTH * sizeof(uint32_t));
	
	//load the sprites
	cimg_library::CImg<unsigned char> all_sprites("assets/in_game_sprites.bmp");
	uint8_t* all_sprites_pt = all_sprites.data();
	sprites = new uint32_t[BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES)];
	//putting the image into the sprite variable for wood slab
	//putting the image into the sprite variable for wood slab
	for (int y = 0; y < BLOCK_HEIGHT; y++) {

		for (int x = 0; x < (BLOCK_WIDTH * NUMBER_SPRITES); x++) {

			// Get the RGB data
			uint8_t r = all_sprites_pt[(BLOCK_WIDTH * NUMBER_SPRITES) * y + x];
			uint8_t g = all_sprites_pt[(BLOCK_WIDTH * NUMBER_SPRITES) * y + x + (BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES))];
			uint8_t b = all_sprites_pt[(BLOCK_WIDTH * NUMBER_SPRITES) * y + x + (2 * BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES))];

			//transfer it 
			sprites[(BLOCK_WIDTH * NUMBER_SPRITES) * y + x] = (r << 16) + (g << 8) + b;

		}
	}

	//retrieval of the alphanumeric sprites
	sprites_alphanum = new uint32_t[ BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM)];
	cimg_library::CImg<unsigned char> all_sprites_alphanum("assets/alphanum_sprites.bmp");
	uint8_t* all_sprites_alphanum_pt = all_sprites_alphanum.data();
	//putting the image into the sprite variable for wood slab
	//putting the image into the sprite variable for wood slab
	for (int y = 0; y < BLOCK_HEIGHT; y++) {

		for (int x = 0; x < (BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM); x++) {

			// Get the RGB data
			uint8_t r = all_sprites_alphanum_pt[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x];
			uint8_t g = all_sprites_alphanum_pt[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x + (BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM))];
			uint8_t b = all_sprites_alphanum_pt[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x + (2 * BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM))];

			//transfer it 
			sprites_alphanum[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x] = (r << 16) + (g << 8) + b;

		}
	}


	//initialize the game map with MAZE_1
	map = new Matter ** [MAP_HEIGHT];
	for (int i = 0; i < MAP_HEIGHT; i++) {
		map[i] = new Matter * [MAP_WIDTH];

		for (int j = 0; j < MAP_WIDTH; j++)
			
			if (MAZE_1[i][j] == 1) {
				//instantiate a diamond slab object
				map[i][j] = new Slab(TypeSlab::DIAMOND, sprites);
			}
			else if (MAZE_1[i][j] == 2) {
				//instantiate a concrete slab object
				map[i][j] = new Slab(TypeSlab::CONCRETE, sprites);
			}
			else if (MAZE_1[i][j] == 3) {
				//instantiate a wood slab object
				map[i][j] = new Slab(TypeSlab::WOOD, sprites);
			}
			else if (MAZE_1[i][j] == 4) {
				//instantiate collectable object
				map[i][j] = new Items(static_cast<TypeItems> (collectable_counter++), sprites);
			}
			else if (MAZE_1[i][j] == 5) {
				//instantiate the cerberus object via the Items class
				map[i][j] = new Items(static_cast<TypeItems> (5), sprites);

			}
			else if (MAZE_1[i][j] == 6) {
				//instantiate heal object via the Items class
				map[i][j] = new Items(static_cast<TypeItems> (6), sprites);
			
			}
			else if (MAZE_1[i][j] == 7) {
				//instantiate creep object via the Items class
				map[i][j] = new Items(static_cast<TypeItems> (7), sprites);
			}
			else if (MAZE_1[i][j] == 8) {
				//instantiate weapon object via the Items class
				map[i][j] = new Items(static_cast<TypeItems> (8), sprites);
			}
			else {
				//this signifies that it is an empty space for the player to move in
				map[i][j] = NULL;
			}
			
	}
		
	//Place the player in the map at (1,1)
	playerPos.X = 3;
	playerPos.Y = 11;
	map[playerPos.Y][playerPos.X] = new Player(sprites);
	
	updateBuffer();

	std::vector <Items *> collectables;
	collectables.push_back(new Items(static_cast<TypeItems>(1), sprites));
	collectables.push_back(new Items(static_cast<TypeItems>(2), sprites));
	collectables.push_back(new Items(static_cast<TypeItems>(3), sprites));

	updateGameBar(100, 100, collectables);
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
			
			//delete the upper portion
			if (playerPos.Y - 3 >= 0) {

				for (int i = 0; i < 5; i++) {

					if ((playerPos.X - 2 + i) < MAP_WIDTH and (playerPos.X - 2 + i) >= 0) {
						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * ((playerPos.Y - 3) * BLOCK_WIDTH + k  + MAP_START_Y) + (((playerPos.X - 2 + i) * BLOCK_WIDTH) + l + MAP_START_X)] = DARK;

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
			

			//delete the lower portion
			if (playerPos.Y + 3 < MAP_HEIGHT) {

				for (int i = 0; i < 5; i++) {

					if ((playerPos.X - 2 + i) < MAP_WIDTH and (playerPos.X - 2 + i) >= 0) {

						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * ((playerPos.Y + 3) * BLOCK_WIDTH + k + MAP_START_Y) + (((playerPos.X - 2 + i) * BLOCK_WIDTH) + l + MAP_START_X)] = DARK;

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
			

			//delete the left portion
			if (playerPos.X - 3 >= 0) {

				for (int y = 0; y < 5; y++) {

					if ((playerPos.Y - 2 + y) < MAP_HEIGHT and (playerPos.Y - 2 + y) >= 0) {

						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * (((playerPos.Y - 2 + y) * BLOCK_WIDTH) + k + MAP_START_Y) + (((playerPos.X - 3) * BLOCK_WIDTH) + l + MAP_START_X)] = DARK;

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
			

			//delete the rightmost part
			if (playerPos.X + 3 >= 0) {

				for (int y = 0; y < 5; y++) {

					if ((playerPos.Y - 2 + y) < MAP_HEIGHT and (playerPos.Y - 2 + y) >= 0) {

						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * (((playerPos.Y - 2 + y) * BLOCK_WIDTH) + k + MAP_START_Y) + (((playerPos.X + 3) * BLOCK_WIDTH) + l + MAP_START_X)] = DARK;

							}
						}
					}
					
				}

			}

		}

	}

	//update the direction for which the player object is facing
	dynamic_cast<Player*>(map[playerPos.Y][playerPos.X])->setNewDirectionFacing(to);
	//update the buffer
	//this will get the surroundings of the character (distance is 2 blocks)
	updateBuffer();

}

void GameMap::updateBuffer() {

	for (int i = 0; i < 5; i++) {


		if ((playerPos.Y - 2) + i >= 0 and (playerPos.Y - 2) + i < MAP_HEIGHT) { //the condition is based on the 2d array

			for (int j = 0; j < 5; j++) {

				if ((playerPos.X - 2) + j >= 0 and (playerPos.X - 2) + j < MAP_WIDTH) { //the condition is based on the 2d array

					if (map[(playerPos.Y - 2) + i][(playerPos.X - 2) + j]) {
						//put the sprite in the buffer if there is an object on it

						uint32_t* sprite_mat = map[(playerPos.Y - 2) + i][(playerPos.X - 2) + j]->getSprite();

						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * ((((playerPos.Y - 2) + i) * BLOCK_WIDTH) + k + MAP_START_Y) + ((((playerPos.X - 2) + j) * BLOCK_WIDTH) + l + MAP_START_X)] = sprite_mat[(BLOCK_WIDTH * NUMBER_SPRITES) * k + l];

							}
						}

					}
					else {

						//this "light up" the surrondings of the player
						for (int k = 0; k < BLOCK_HEIGHT; k++) {

							for (int l = 0; l < BLOCK_WIDTH; l++) {

								gamemapBuffer[WIDTH * ((((playerPos.Y - 2) + i) * BLOCK_WIDTH) + k + MAP_START_Y) + ((((playerPos.X - 2) + j) * BLOCK_WIDTH) + l + MAP_START_X)] = LIGHT;

							}
						}

					}

				}


			}

		}

	}
}

void GameMap::attackPlayer() {

	//the player will attack only one block in front of what he is facing
	Direction currFacing = dynamic_cast<Player *>(map[playerPos.Y][playerPos.X])->getPlayerFacing();
	int playerAD = dynamic_cast<Player*>(map[playerPos.Y][playerPos.X])->getAttackDamage();

	if (currFacing == Direction::UP) {

		//deal damage to the object 
		if (map[playerPos.Y - 1][playerPos.X]) {
			
			map[playerPos.Y - 1][playerPos.X]->absorbDamage(playerAD);

			if (map[playerPos.Y - 1][playerPos.X]->getHitpoints() <= 0)
				delete map[playerPos.Y - 1][playerPos.X]; //this signifies that the object is destroyed
				map[playerPos.Y - 1][playerPos.X] = NULL;

		}
	}
	else if (currFacing == Direction::DOWN) {
		//deal damage to the object 
		if (map[playerPos.Y + 1][playerPos.X]) {

			map[playerPos.Y + 1][playerPos.X]->absorbDamage(playerAD);

			if (map[playerPos.Y + 1][playerPos.X]->getHitpoints() <= 0) {
				delete map[playerPos.Y + 1][playerPos.X]; //this signifies that the object is destroyed
				map[playerPos.Y + 1][playerPos.X] = NULL;
			}
				

		}

	}
	else if (currFacing == Direction::RIGHT) {
		//deal damage to the object 
		if (map[playerPos.Y][playerPos.X+1]) {

			map[playerPos.Y][playerPos.X+1]->absorbDamage(playerAD);

			if (map[playerPos.Y][playerPos.X + 1]->getHitpoints() <= 0) {
				delete map[playerPos.Y][playerPos.X + 1]; //this signifies that the object is destroyed
				map[playerPos.Y][playerPos.X + 1] = NULL;
			}
				
		}
	}
	else if (currFacing == Direction::LEFT) {
		//deal damage to the object 
		if (map[playerPos.Y][playerPos.X - 1]) {

			map[playerPos.Y][playerPos.X - 1]->absorbDamage(playerAD);

			if (map[playerPos.Y][playerPos.X - 1]->getHitpoints() <= 0) {
				delete map[playerPos.Y][playerPos.X - 1]; //this signifies that the object is destroyed
				map[playerPos.Y][playerPos.X - 1] = NULL;
			}

		}

	}

	updateBuffer();
}

void GameMap::updateGameBar(int playerHitpoints, int weaponHitpoints, std::vector<Items *> collectables) {
	
	//clear the gamebar part
	memset(gamemapBuffer, LIGHT, 30 * WIDTH * sizeof(uint32_t));

	std::string string_display = "health:" + std::to_string(playerHitpoints) + " weapon health:" + std::to_string(weaponHitpoints) + " items:";
	
	//display the PlayerHitsPoints, weapon health
	for (int i = 0; i < string_display.length(); i++) {

		//this "light up" the surrondings of the player
		for (int y = 0; y < BLOCK_HEIGHT; y++) {

			for (int x = 0; x < BLOCK_WIDTH; x++) {

				if (isdigit(string_display.at(i))) { //for the case when the number is a digit
					gamemapBuffer[WIDTH * y + x + (BLOCK_WIDTH * i)] = sprites_alphanum[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x + BLOCK_WIDTH * (string_display.at(i) - '0')];
				}
				else if (string_display.at(i) == ' ') {
					gamemapBuffer[WIDTH * y + x + (BLOCK_WIDTH * i)] = LIGHT;
				}
				else if (string_display.at(i) == ':') { //for the colon. It can be found at the last portion of the sprites for alphanum
					gamemapBuffer[WIDTH * y + x + (BLOCK_WIDTH * i)] = sprites_alphanum[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x + BLOCK_WIDTH * (NUMBER_SPRITES_ALPHANUM - 1)];
				}
				else {//for the letters
					gamemapBuffer[WIDTH * y + x + (BLOCK_WIDTH * i)] = sprites_alphanum[(BLOCK_WIDTH * NUMBER_SPRITES_ALPHANUM) * y + x + BLOCK_WIDTH * (10 + string_display.at(i) - 'a')];
				}
				

			}
		}

	}

	//for the collected items
	for (int i = 0; i < collectables.size(); i++) 
		for (int y = 0; y < BLOCK_HEIGHT; y++)
			for (int x = 0; x < BLOCK_WIDTH; x++)
				//start the end of the items portion of the gamebar
				gamemapBuffer[WIDTH * y + x + (BLOCK_WIDTH * i) + (string_display.length() * BLOCK_WIDTH)] = collectables.at(i)->getSprite()[(BLOCK_WIDTH * NUMBER_SPRITES) * y + x];
	

}

