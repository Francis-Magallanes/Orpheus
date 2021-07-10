#include "Player.h"
#include <stdint.h>

Player::Player() {

	hitpoints = 100;

	//initialize the sprite variable
	sprite = new uint32_t[20 * 20];

	//It will be initialized to be a blue block
	for (int i = 0; i < 20 * 20; i++)
		sprite[i] = 0x00FF00;
	
}

uint32_t* Player::getSprite() {
	return sprite;
}

Player::~Player() {

	delete[] sprite;

}
