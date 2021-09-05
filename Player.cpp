#include "Definitions.h"

//this is for the sprite where the player object facing upwards
//0xFFA500 - Orange
//0x00FF00 - Green

Player::Player() {

	uint8_t r, g, b;
	uint32_t color;

	//initialize the sprite 
	PLAYER_SPRITE_RIGHT = new uint32_t[20 * 20];
	PLAYER_SPRITE_RIGHT_1 = new uint32_t[20 * 20];
	PLAYER_SPRITE_LEFT = new uint32_t[20 * 20];
	PLAYER_SPRITE_LEFT_1 = new uint32_t[20 * 20];
	
	//load the sprite
	cimg_library::CImg<unsigned char> ps_right("assets/player_right_sprite_1.bmp");
	uint8_t* ps_right_pt = ps_right.data();

	cimg_library::CImg<unsigned char> ps_right_1("assets/player_right_sprite.bmp");
	uint8_t* ps_right_pt_1 = ps_right_1.data();

	cimg_library::CImg<unsigned char> ps_left("assets/player_left_sprite.bmp");
	uint8_t* ps_left_pt = ps_left.data();

	cimg_library::CImg<unsigned char> ps_left_1("assets/player_left_sprite_1.bmp");
	uint8_t* ps_left_pt_1 = ps_left_1.data();

	//putting the image into the sprite variable
	for (int y = 0; y < 20; y++) {

		for (int x = 0; x < 20; x++) {

			// Get the RGB data
			r = ps_right_pt[20 * y + x];
			g = ps_right_pt[20 * y + x + 20 * 20];
			b = ps_right_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//it will adjust the background color of white into the appropreaite color
			if (color == 0xFFFFFF)
				PLAYER_SPRITE_RIGHT[20 * y + x] = LIGHT;
			else
				PLAYER_SPRITE_RIGHT[20 * y + x] = (r << 16) + (g << 8) + b;

			// Get the RGB data
			r = ps_right_pt_1[20 * y + x];
			g = ps_right_pt_1[20 * y + x + 20 * 20];
			b = ps_right_pt_1[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//it will adjust the background color of white into the appropreaite color
			if (color == 0xFFFFFF)
				PLAYER_SPRITE_RIGHT_1[20 * y + x] = LIGHT;
			else
				PLAYER_SPRITE_RIGHT_1[20 * y + x] = (r << 16) + (g << 8) + b;

			r = ps_left_pt[20 * y + x];
			g = ps_left_pt[20 * y + x + 20 * 20];
			b = ps_left_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//it will adjust the background color of white into the appropreaite color
			if (color == 0xFFFFFF)
				PLAYER_SPRITE_LEFT[20 * y + x] = LIGHT;
			else
				PLAYER_SPRITE_LEFT[20 * y + x] = (r << 16) + (g << 8) + b;

			r = ps_left_pt_1[20 * y + x];
			g = ps_left_pt_1[20 * y + x + 20 * 20];
			b = ps_left_pt_1[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//it will adjust the background color of white into the appropreaite color
			if (color == 0xFFFFFF)
				PLAYER_SPRITE_LEFT_1[20 * y + x] = LIGHT;
			else
				PLAYER_SPRITE_LEFT_1[20 * y + x] = (r << 16) + (g << 8) + b;

		}
	}


	hitpoints = 100;
	attackDamage = 20;

	//by default, the player object will face to the right
	playerFacing = Direction::RIGHT;
	sprite = PLAYER_SPRITE_RIGHT;

	
}

void Player::setNewDirectionFacing(Direction newDir) {
	playerFacing = newDir;
	
	switch (newDir) {

		case Direction::UP:
			if (sprite == PLAYER_SPRITE_LEFT)
				sprite = PLAYER_SPRITE_LEFT_1;
			else if (sprite == PLAYER_SPRITE_LEFT_1)
				sprite = PLAYER_SPRITE_LEFT;
			else if (sprite == PLAYER_SPRITE_RIGHT)
				sprite = PLAYER_SPRITE_RIGHT_1;
			else
				sprite = PLAYER_SPRITE_RIGHT;
			break;

		case Direction::DOWN:
			if (sprite == PLAYER_SPRITE_LEFT)
				sprite = PLAYER_SPRITE_LEFT_1;
			else if (sprite == PLAYER_SPRITE_LEFT_1)
				sprite = PLAYER_SPRITE_LEFT;
			else if (sprite == PLAYER_SPRITE_RIGHT)
				sprite = PLAYER_SPRITE_RIGHT_1;
			else
				sprite = PLAYER_SPRITE_RIGHT;
			break;

		case Direction::LEFT:
			if (sprite == PLAYER_SPRITE_LEFT)
				sprite = PLAYER_SPRITE_LEFT_1;
			else
				sprite = PLAYER_SPRITE_LEFT;
			break;

		case Direction::RIGHT:
			if (sprite == PLAYER_SPRITE_RIGHT)
				sprite = PLAYER_SPRITE_RIGHT_1;
			else
				sprite = PLAYER_SPRITE_RIGHT;
			break;

		default:
			sprite = PLAYER_SPRITE_RIGHT;

	}
}


void Player::absorbDamage(int damage) {

}

Direction Player::getPlayerFacing() { return playerFacing; }

int Player::getAttackDamage() { return attackDamage; }

Player::~Player() {

	delete[] sprite;

}
