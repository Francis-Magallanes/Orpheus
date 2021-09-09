#include "Definitions.h"

Items::Items(TypeItems type, uint32_t* sprites) {

	this->type = type;

	switch(type) {

		case TypeItems::COLLECTABLE1:
			sprite = sprites;
			hitpoints = 1;
			break;
		case TypeItems::COLLECTABLE2:
			sprite = sprites + (BLOCK_WIDTH);
			hitpoints = 1;
			break;
		case TypeItems::COLLECTABLE3:
			sprite = sprites + (BLOCK_WIDTH * 2);
			hitpoints = 1;
			break;
		case TypeItems::WEAPON:
			sprite = sprites + (BLOCK_WIDTH * 18);
			hitpoints = 100; // hitspoints for weapon will be used as basis on the number of attacks
			break;
		case TypeItems::HEAL:
			sprite = sprites + (BLOCK_WIDTH * 19);
			hitpoints = 20; //hitspoints for heal will be used as basis on the number of heal will happen
			break;
		case TypeItems::CREEP:
			sprite = sprites + (BLOCK_WIDTH * 19);
			hitpoints = 20; //this will also the basis for the damage that player will receive
			break;
		case TypeItems::CERBERUS:
			sprite = sprites + (BLOCK_WIDTH * 22);
			hitpoints = 100000;
			break;

		default: //it will act as collectable 1
			sprite = sprites;
			break;
	}
}


void Items::absorbDamage(int damage) {
	hitpoints = hitpoints - damage;
}

TypeItems Items::getType() { return type; }

bool Items::isItemsInstance(){
	return true;
}