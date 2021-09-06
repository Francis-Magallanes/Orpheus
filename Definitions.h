#pragma once
#include "dependencies/CImg.h"
#include <stdint.h>

//dimensions of the screen resolution
#define HEIGHT 720
#define WIDTH 1280

//each block will have a size of 30x30 pixels
#define MAP_HEIGHT 23 // height of the playable map: HEIGHT / 30 (in number of blocks)
#define MAP_WIDTH 42 // width of the playable map: WIDTH / 30  (in number of blocks)

#define MAP_START_X 10 //this where the pixels of the playable map start in x position
#define MAP_START_Y 30 //this where the pixels of the playable map start in y position

#define MAP_END_X 1270 //this where the pixels of the playable map end in x position
#define MAP_END_Y 720  //this where the pixels of the playable map end in y position

#define BLOCK_WIDTH 30 //in pixels
#define BLOCK_HEIGHT 30 //in pixels

#define NUMBER_SPRITES 59 //this is a number of sprites stored in a file which can be accessed by the "sprites" pointer

#define LIGHT 0xFFFFFF
#define DARK 0x000000


// this will distinguish the different type of slab and it characteristics
// each type of slab will have a unique color, whether can be damage or not, and hitpoints
enum class TypeSlab {

	//this cannot be damaged by the player
	//Color: Light Blue (0x67B7D1)
	DIAMOND = 1,

	// it takes 3 hits before it gets destroyed
	CONCRETE = 2,

	// it takes 2 hits before it gets destroyed
	// Color: Light Brown (0xB5651D)
	WOOD = 3
};

//direction for which the player will move
enum class Direction {
	UP,
	DOWN,
	LEFT,
	RIGHT
};


struct Coordinate {
	int X;
	int Y;
};

class Matter
	{
	protected:
		int hitpoints;
		uint32_t* sprite; //this will be used to store the sprite

	public:

		//this is for handling any "damage" (i.e. player's attack) towards the object
		virtual void absorbDamage(int damage) = 0;

		//this will get the value of the hitpoints
		int getHitpoints() {
			return hitpoints;
		}

		uint32_t* getSprite() {
			return sprite;
		}
};



class GameMap
{
private:
	//this will contain the different objects inside the game map
	// it is in two dimensional scheme for easier access of the objects
	Matter*** map;
	uint32_t* gamemapBuffer;

	uint32_t* sprites; //this will contain all the sprites needed for the game

	Coordinate playerPos; // this will store the position of the player in the map

	//this will update the buffer when the player object moves
	//this will get the surroundings of the character (distance is 2 blocks) for the display
	void updateBuffer();

	//this will update the gamebar portion when the stats of the player is affected
	void updateGameBar();

public:
	GameMap(uint32_t* framebuffer);

	//this will handle on the one block movement of the player object depending of the inputted direction
	void movePlayer(Direction to);

	//this will the attack action of the player object
	void attackPlayer();

};


class Player : public Matter {

	private:
		Direction playerFacing; //this will monitor where the player object is currently facing
		int attackDamage;
		uint32_t* PLAYER_SPRITE_RIGHT; // sprite for when the player facing to the right
		uint32_t* PLAYER_SPRITE_RIGHT_1; // sprite for when the player facing to the right second version
		uint32_t* PLAYER_SPRITE_LEFT_1; // sprite for when the player facing to the left
		uint32_t* PLAYER_SPRITE_LEFT; //sprite for when the playyer facing to the left second version

	public:
		//Constructor
		//sprites will contain the different sprites that is used in the game
		//At a specific index, it will return a unique sprite. Following are the index sprite needed by the Player class
		// 10-17: Player Spirte
		Player(uint32_t* sprites);

		//Destructor
		~Player();

		//this will set the direction for which the player object is currently facing
		//it will also update its sprite according to its direction
		void setNewDirectionFacing(Direction newDir);

		//this is for handling any "damage" (i.e. player's attack) towards the object
		void absorbDamage(int damage);

		//this will get the value of playerFacing
		Direction getPlayerFacing();

		//this will get the value of attackDamage
		int getAttackDamage();
};

class Slab :
	public Matter
{

	private:
		TypeSlab ts;
		uint32_t* DIAMOND_SPRITE; //for the diamond sprite
		uint32_t* CONCRETE_SPRITE_1;//for the concrete sprite at 100% 
		uint32_t* CONCRETE_SPRITE_2;//for the concrete sprite at 75% 
		uint32_t* CONCRETE_SPRITE_3;//for the concrete sprite at 50%
		uint32_t* WOOD_SPRITE_1; //for the wood sprite at 100%
		uint32_t* WOOD_SPRITE_2;// for the wood sprite at 50%


	public:
		//sprites will contain the different sprites that is used in the game
		//At a specific index, it will return a unique sprite. Following are the index sprite needed by the Slab class
		// 3-5 : Wood Sprite (in descending)
		// 6-8 : Concerete Sprite (in descending)
		// 9: Diamond sprite
		//type will indicate what type of Slab to be instantiated. Refer to the definiton of the TypeSlab
		Slab(TypeSlab type, uint32_t* sprites);
		~Slab();

		//this is for handling any "damage" (i.e. player's attack) towards the object
		void absorbDamage(int damage);

};