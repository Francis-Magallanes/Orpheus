#include "dependencies/MiniFB.h"
#include "Definitions.h"



GameMap* gm;// this object will handle most of the game


void keypress(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed)
{	

	if (key == KB_KEY_ESCAPE) {
		mfb_close(window);
	}

	//This will handle the keypress for the movement of player
	if (key == KB_KEY_UP || key == KB_KEY_W) {
		//for move up
		gm->movePlayer(Direction::UP);

	}
	else if (key == KB_KEY_DOWN || key == KB_KEY_S){
		//for move down
		gm->movePlayer(Direction::DOWN);
	}
	else if (key == KB_KEY_RIGHT || key == KB_KEY_D) {
		//for move right
		gm->movePlayer(Direction::RIGHT);
	}
	else if (key == KB_KEY_LEFT || key == KB_KEY_A) {
		//for move left
		gm->movePlayer(Direction::LEFT);

	}
	//this will handle the keypress for attack 
	else if (key == KB_KEY_SPACE) {
		gm->attackPlayer();
	}

}
int main()
{
	//load the sprites
	cimg_library::CImg<unsigned char> all_sprites("assets/spritesheet.bmp");
	uint8_t * all_sprites_pt = all_sprites.data();
	sprites = new uint32_t[BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES)];
	//putting the image into the sprite variable for wood slab
	for (int y = 0; y < BLOCK_HEIGHT; y++) {

		for (int x = 0; x < (BLOCK_WIDTH * NUMBER_SPRITES); x++) {

			// Get the RGB data
			uint8_t r = all_sprites_pt[BLOCK_HEIGHT * y + x];
			uint8_t g = all_sprites_pt[BLOCK_HEIGHT * y + x + BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES)];
			uint8_t b = all_sprites_pt[BLOCK_HEIGHT * y + x + 2 * BLOCK_HEIGHT * (BLOCK_WIDTH * NUMBER_SPRITES)];
			uint32_t color = (r << 16) + (g << 8) + b;

			//transfer it 
			sprites[20 * y + x] = color;

		}
	}

	
	struct mfb_window* window = mfb_open("Orpheus", WIDTH, HEIGHT);
	mfb_set_keyboard_callback(window, keypress); // the bind the keypress callback
	uint32_t* framebuffer = (uint32_t*)malloc(HEIGHT * WIDTH * 4);
	
	gm = new GameMap(framebuffer);

	

	if (!window)
		return -1;

	
	do
	{
		mfb_update(window, framebuffer);

	} while (mfb_wait_sync(window));

	return 0;
}