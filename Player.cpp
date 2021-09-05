#include "Definitions.h"

//this is for the sprite where the player object facing upwards
//0xFFA500 - Orange
//0x00FF00 - Green

Player::Player(uint32_t* sprites) {

	uint8_t r, g, b;
	uint32_t color;

	//initialize the sprite pointers
	PLAYER_SPRITE_RIGHT = sprites + (BLOCK_WIDTH * 10);
	PLAYER_SPRITE_RIGHT_1 = PLAYER_SPRITE_RIGHT + BLOCK_WIDTH;
	PLAYER_SPRITE_LEFT = sprites + (BLOCK_WIDTH * 13);
	PLAYER_SPRITE_LEFT_1 = PLAYER_SPRITE_LEFT + BLOCK_WIDTH;
	
	//TODO: Add sprites for the player with weapon

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
