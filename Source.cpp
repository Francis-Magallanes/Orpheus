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