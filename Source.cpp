#include <iostream>
#include <stdlib.h>

#include <fstream>
#include "dependencies/MiniFB.h"
#include "GameMap.h"

#include "windows.h"


#define HEIGHT 480
#define WIDTH 640

GameMap gm;// this object will handle most of the game


void keypress(struct mfb_window* window, mfb_key key, mfb_key_mod mod, bool isPressed)
{	
	
	if (key == KB_KEY_ESCAPE) {
		mfb_close(window);
	}

	//This will handle the keypress for the movement of player
	if (key == KB_KEY_UP || key == KB_KEY_W) {
		//for move up
		gm.movePlayer(Direction::UP);

	}
	else if (key == KB_KEY_DOWN || key == KB_KEY_S){
		//for move down
		gm.movePlayer(Direction::DOWN);
	}
	else if (key == KB_KEY_RIGHT || key == KB_KEY_D) {
		//for move right
		gm.movePlayer(Direction::RIGHT);
	}
	else if (key == KB_KEY_LEFT || key == KB_KEY_A) {
		//for move left
		gm.movePlayer(Direction::LEFT);

	}

}
int main()
{
	
	
	struct mfb_window* window = mfb_open("Orpheus", WIDTH, HEIGHT);
	mfb_set_keyboard_callback(window, keypress); // the bind the keypress callback

	if (!window)
		return -1;

	
	do
	{
		mfb_update(window, gm.getBufferReference());

	} while (mfb_wait_sync(window));

	return 0;
}