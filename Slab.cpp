#include "Slab.h"

Slab::Slab(TypeSlab type) {
	hitpoints = 100;

	ts = type;

	//setting the color based on type
	switch (ts) {
		case TypeSlab::DIAMOND:
			color = 0x67B7D1;
			break;

		case TypeSlab::CONCRETE:
			color = 0xD3D3D3;
			break;

		case TypeSlab::WOOD:
			color = 0xB5651D;
			break;

		default:
			color = 0xB5651D;
	}

	//initialize the sprite variable
	sprite = new uint32_t[20 * 20];

	//It will be initialized to be a white block
	for (int i = 0; i < 20 * 20; i++)
		sprite[i] = color;
}

uint32_t* Slab::getSprite() {
	return sprite;
}
Slab::~Slab() {

	delete[] sprite;
}