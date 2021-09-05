#include "Definitions.h"

Slab::Slab(TypeSlab type, uint32_t* sprites) {
	
	ts = type;
	
	//asignment of internal pointers from the pointer containing the different sprites
	DIAMOND_SPRITE = sprites + (BLOCK_WIDTH * 9); //add (BLOCK_WIDTH * 9) to point to the diamond sprite

	CONCRETE_SPRITE_1 = sprites + (BLOCK_WIDTH * 6); //add (BLOCK_WIDTH * 6) to point to the concrete sprite
	CONCRETE_SPRITE_2 = CONCRETE_SPRITE_1 + BLOCK_WIDTH;
	CONCRETE_SPRITE_3 = CONCRETE_SPRITE_2 + BLOCK_WIDTH;

	WOOD_SPRITE_1 = sprites + (BLOCK_WIDTH * 3); //add (BLOCK_WIDTH * 3) to point to the wood sprite
	WOOD_SPRITE_2 = WOOD_SPRITE_1 + BLOCK_WIDTH;

	//setting the sprite based on type
	switch (ts) {

		case TypeSlab::DIAMOND:
			sprite = DIAMOND_SPRITE;
			break;
			

		case TypeSlab::CONCRETE:
			sprite = CONCRETE_SPRITE_1;
			hitpoints = 100;

			break;

		case TypeSlab::WOOD:
			sprite = WOOD_SPRITE_1;
			hitpoints = 50;
			break;

		default:
			sprite = DIAMOND_SPRITE;
	}

}

void Slab::absorbDamage(int damage) {
	
	if (ts != TypeSlab::DIAMOND) {
		
		//updating the hitpoints
		hitpoints = hitpoints - damage;

		//updating the sprite
		if (ts == TypeSlab::CONCRETE) {

			if ((hitpoints <= 75) && (hitpoints > 50))
				sprite = CONCRETE_SPRITE_2;

			else if (hitpoints <= 50)
				sprite = CONCRETE_SPRITE_3;
		}
		else if (ts == TypeSlab::WOOD) {

			if (hitpoints <= 25)
				sprite = WOOD_SPRITE_2;
		}
	}
	

}

Slab::~Slab() {


}