#include "Block.h"

Block::Block() {
	hitpoints = 100;

	//initialize the sprite variable
	sprite = new uint32_t[20 * 20];

	//It will be initialized to be a white block
	for (int i = 0; i < 20 * 20; i++)
		sprite[i] = 0xFFFFFF;
}

uint32_t* Block::getSprite() {
	return sprite;
}

Block::~Block() {

	delete[] sprite;
}