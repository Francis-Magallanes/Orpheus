#include "Definitions.h"

Slab::Slab(TypeSlab type) {
	
	ts = type;
	
	//setting the sprite based on type
	switch (ts) {

		case TypeSlab::DIAMOND:
			sprite = sprites + (BLOCK_WIDTH * 9); //add (BLOCK_WIDTH * 9) to point to the diamond sprite
			break;
			

		case TypeSlab::CONCRETE:
			sprite = sprites + (BLOCK_WIDTH * 6); //add (BLOCK_WIDTH * 6) to point to the concrete sprite
			hitpoints = 100;

			break;

		case TypeSlab::WOOD:
			sprite = sprites + (BLOCK_WIDTH * 3); //add (BLOCK_WIDTH * 3) to point to the wood sprite
			hitpoints = 50;
			break;

		default:
			sprite = sprites + (BLOCK_WIDTH * 9); //add (BLOCK_WIDTH * 9) to point to the diamond sprite
	}

}

void Slab::absorbDamage(int damage) {
	
	if (ts != TypeSlab::DIAMOND) {
		
		//updating the hitpoints
		hitpoints = hitpoints - damage;

		//updating the sprite
		if (ts == TypeSlab::CONCRETE) {

			if ( (hitpoints <= 75) && (hitpoints > 50) )
				sprite = sprites + (BLOCK_WIDTH * 7); //add (BLOCK_WIDTH * 7) to point to the 2nd concrete sprite 

			else if (hitpoints <= 50)
				sprite = sprites + (BLOCK_WIDTH * 8); //add (BLOCK_WIDTH * 8) to point to the 3rd concrete sprite 
		}
		else if (ts == TypeSlab::WOOD) {

			if (hitpoints <= 25)
				sprite = sprites + (BLOCK_WIDTH * 4); //add (BLOCK_WIDTH * 4) to point to the 2nd wood sprite 
		}
	}
	

}

Slab::~Slab() {


}