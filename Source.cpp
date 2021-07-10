#include <iostream>
#include <stdlib.h>

#include <fstream>
#include "dependencies/MiniFB.h"
#include "GameMap.h"

#define HEIGHT 480
#define WIDTH 640

GameMap gm;

/*
	This will create a 20 x 20 pixel with a white block from the top-level coordinate
*/
void CreateBlock(uint32_t* buffer, int topLeftX, int topLeftY) {

	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			buffer[WIDTH * (topLeftY + i) + (topLeftX + j)] = 0xFFFFFF;

}

void LoadSprite(uint32_t* buffer, int locX, int locY) {

	std::ifstream sprite;
	sprite.open("assests/Player_Sprite.png", std::ios::binary);

	if (sprite.is_open()) {
		std::cout << "Successfully Opened the Sprite" << std::endl;

		sprite.seekg(0, std::ios::end);

		int datasize = sprite.tellg();

		//This is an error-prone point. Reset the file pointer to the beginning to read the file content
		char* imgbuff = new char[datasize + 1];
		sprite.seekg(0, std::ios::beg);
		sprite.read(imgbuff, datasize);

		std::cout << std::hex << &imgbuff << std::endl;

		delete[] imgbuff;
	}
	else {
		std::cout << "Unable to Open the Sprite" << std::endl;
	}
	sprite.close();
}

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