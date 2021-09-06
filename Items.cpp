#include "Definitions.h"

Items::Items(TypeItems type, uint32_t* sprites) {

	this->type = type;

	switch(type) {

		case TypeItems::COLLECTABLE1:
			sprite = sprites;
			break;
		case TypeItems::COLLECTABLE2:
			sprite = sprites + (BLOCK_WIDTH);
			break;
		case TypeItems::COLLECTABLE3:
			sprite = sprites + (BLOCK_WIDTH * 2);
			break;
		case TypeItems::WEAPON:
			sprite = sprites + (BLOCK_WIDTH * 18);
			break;
		case TypeItems::HEAL:
			sprite = sprites + (BLOCK_WIDTH * 19);
			break;
		case TypeItems::CREEP:
			sprite = sprites + (BLOCK_WIDTH * 19);
			break;
		case TypeItems::CERBERUS:
			sprite = sprites + (BLOCK_WIDTH * 22);
			break;

		default: //it will act as collectable 1
			sprite = sprites;
			break;
	}
}

void Items::absorbDamage(int damage) {
	hitpoints = hitpoints - damage;
}

int Items::getHitpoints() { return hitpoints; }

TypeItems Items::getType() { return type; }