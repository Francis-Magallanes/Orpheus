#include "Slab.h"

Slab::Slab(TypeSlab type) {
	
	//initialize the different variables and pointers for the loading of the sprite
	uint8_t r, g, b;
	uint32_t color;
	uint8_t *ws_sprite1_pt, *ws_sprite2_pt, * cs_sprite1_pt, * cs_sprite2_pt, * cs_sprite3_pt;

	//initialize the different sprites for wood slab
	cimg_library::CImg<unsigned char> ws_sprite1("assets/wood_sprite_1.bmp");
	ws_sprite1_pt = ws_sprite1.data();
	WOOD_SPRITE_1 = new uint32_t[20 * 20];

	cimg_library::CImg<unsigned char> ws_sprite2("assets/wood_sprite_2.bmp");
	ws_sprite2_pt = ws_sprite2.data();
	WOOD_SPRITE_2 = new uint32_t[20 * 20];

	//initialize the different sprites for concrete slab
	cimg_library::CImg<unsigned char> cs_sprite1("assets/concrete_sprite_1.bmp");
	cs_sprite1_pt = cs_sprite1.data();
	CONCRETE_SPRITE_1 = new uint32_t[20 * 20];

	cimg_library::CImg<unsigned char> cs_sprite2("assets/concrete_sprite_2.bmp");
	cs_sprite2_pt = cs_sprite2.data();
	CONCRETE_SPRITE_2 = new uint32_t[20 * 20];

	cimg_library::CImg<unsigned char> cs_sprite3("assets/concrete_sprite_3.bmp");
	cs_sprite3_pt = cs_sprite3.data();
	CONCRETE_SPRITE_3 = new uint32_t[20 * 20];

	//putting the image into the sprite variable for wood slab
	for (int y = 0; y < 20; y++) {

		for (int x = 0; x < 20; x++) {

			// Get the RGB data
			r = ws_sprite1_pt[20 * y + x];
			g = ws_sprite1_pt[20 * y + x + 20 * 20];
			b = ws_sprite1_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//transfer it 
			WOOD_SPRITE_1[20 * y + x] = color;

			// Get the RGB data
			r = ws_sprite2_pt[20 * y + x];
			g = ws_sprite2_pt[20 * y + x + 20 * 20];
			b = ws_sprite2_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//transfer it 
			WOOD_SPRITE_2[20 * y + x] = color;
		}
	}

	//putting the image into the sprite variable for concrete slab
	for (int y = 0; y < 20; y++) {

		for (int x = 0; x < 20; x++) {

			// Get the RGB data
			r = cs_sprite1_pt[20 * y + x];
			g = cs_sprite1_pt[20 * y + x + 20 * 20];
			b = cs_sprite1_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//transfer it 
			CONCRETE_SPRITE_1[20 * y + x] = color;

			// Get the RGB data
			r = cs_sprite2_pt[20 * y + x];
			g = cs_sprite2_pt[20 * y + x + 20 * 20];
			b = cs_sprite2_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//transfer it 
			CONCRETE_SPRITE_2[20 * y + x] = color;

			// Get the RGB data
			r = cs_sprite3_pt[20 * y + x];
			g = cs_sprite3_pt[20 * y + x + 20 * 20];
			b = cs_sprite3_pt[20 * y + x + 2 * 20 * 20];
			color = (r << 16) + (g << 8) + b;

			//transfer it 
			CONCRETE_SPRITE_3[20 * y + x] = color;
		}
	}

	ts = type;

	//setting the sprite based on type
	switch (ts) {

		case TypeSlab::DIAMOND:

			sprite = new uint32_t[400];
			for (int i = 0; i < 20 * 20; i++)
				sprite[i] = 0x67B7D1;
			hitpoints = 1;

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
			sprite = CONCRETE_SPRITE_1;
	}

}

void Slab::absorbDamage(int damage) {
	
	if (ts != TypeSlab::DIAMOND) {
		
		//updating the hitpoints
		hitpoints = hitpoints - damage;

		//updating the sprite
		if (ts == TypeSlab::CONCRETE) {

			if ( (hitpoints <= 75) && (hitpoints > 50) )
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

uint32_t* Slab::getSprite() {
	return sprite;
}
Slab::~Slab() {

	delete[] WOOD_SPRITE_1;
	delete[] WOOD_SPRITE_2;

}