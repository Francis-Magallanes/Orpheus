#include "Definitions.h"

//this is for the sprite where the player object facing upwards
//0xFFA500 - Orange
//0x00FF00 - Green

Player::Player(uint32_t* sprites) {

	//initialize the sprite pointers
	PLAYER_SPRITE_RIGHT = sprites + (BLOCK_WIDTH * 10);
	PLAYER_SPRITE_RIGHT_1 = PLAYER_SPRITE_RIGHT + BLOCK_WIDTH;
	PLAYER_SPRITE_LEFT = sprites + (BLOCK_WIDTH * 12);
	PLAYER_SPRITE_LEFT_1 = PLAYER_SPRITE_LEFT + BLOCK_WIDTH;
	
	//for the player with weapon
	PLAYER_SPRITE_RIGHT_WEAPON = sprites + (BLOCK_WIDTH * 14);
	PLAYER_SPRITE_RIGHT_1_WEAPON = PLAYER_SPRITE_RIGHT_WEAPON + BLOCK_WIDTH;
	PLAYER_SPRITE_LEFT_WEAPON = sprites + (BLOCK_WIDTH * 16);
	PLAYER_SPRITE_LEFT_1_WEAPON = PLAYER_SPRITE_LEFT_WEAPON + BLOCK_WIDTH;


	hitpoints = 100;
	attackDamage = 20;

	//by default, the player object will face to the right
	playerFacing = Direction::RIGHT;
	sprite = PLAYER_SPRITE_RIGHT;

	weapon = nullptr;
	
}

void Player::setNewDirectionFacing(Direction newDir) {
	playerFacing = newDir;
	
	//update the player sprite to be displayed accordingly
	switch (newDir) {

		case Direction::UP:

			if (isEquipWeapon()) {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1_WEAPON;
				else if (sprite == PLAYER_SPRITE_LEFT_1_WEAPON || sprite == PLAYER_SPRITE_LEFT_1)
					sprite = PLAYER_SPRITE_LEFT_WEAPON;
				else if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1_WEAPON;
				else
					sprite = PLAYER_SPRITE_RIGHT_WEAPON;
			}
			else {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1;
				else if (sprite == PLAYER_SPRITE_LEFT_1_WEAPON || sprite == PLAYER_SPRITE_LEFT_1)
					sprite = PLAYER_SPRITE_LEFT;
				else if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1;
				else
					sprite = PLAYER_SPRITE_RIGHT;
			}
			
			break;

		case Direction::DOWN:

			if (isEquipWeapon()) {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1_WEAPON;
				else if (sprite == PLAYER_SPRITE_LEFT_1_WEAPON || sprite == PLAYER_SPRITE_LEFT_1)
					sprite = PLAYER_SPRITE_LEFT_WEAPON;
				else if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1_WEAPON;
				else
					sprite = PLAYER_SPRITE_RIGHT_WEAPON;
			}
			else {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1;
				else if (sprite == PLAYER_SPRITE_LEFT_1_WEAPON || sprite == PLAYER_SPRITE_LEFT_1)
					sprite = PLAYER_SPRITE_LEFT;
				else if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1;
				else
					sprite = PLAYER_SPRITE_RIGHT;
			}
			
			break;

		case Direction::LEFT:
			
			if (isEquipWeapon()) {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1_WEAPON;
				else
					sprite = PLAYER_SPRITE_LEFT_WEAPON;
			}
			else {
				if (sprite == PLAYER_SPRITE_LEFT_WEAPON || sprite == PLAYER_SPRITE_LEFT)
					sprite = PLAYER_SPRITE_LEFT_1;
				else
					sprite = PLAYER_SPRITE_LEFT;
			}
			
			break;

		case Direction::RIGHT:

			if (isEquipWeapon()) {
				if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1_WEAPON;
				else
					sprite = PLAYER_SPRITE_RIGHT_WEAPON;
			}
			else {
				if (sprite == PLAYER_SPRITE_RIGHT_WEAPON || sprite == PLAYER_SPRITE_RIGHT)
					sprite = PLAYER_SPRITE_RIGHT_1;
				else
					sprite = PLAYER_SPRITE_RIGHT;
			}
			
			break;

		default:
			sprite = PLAYER_SPRITE_RIGHT;

	}
}


void Player::absorbDamage(int damage) {
	hitpoints = hitpoints - damage;
}

Direction Player::getPlayerFacing() { return playerFacing; }

int Player::getAttackDamage() { return attackDamage; }

void Player::healUp(int amount) {
	
	if(hitpoints < 140)
		hitpoints = hitpoints + amount;
}

std::vector<Items*> Player::getCollectedItems() { return bag; }

void Player::addCollectedItem(Items* collectable) {

	if (collectable->getType() == TypeItems::COLLECTABLE1 ||
		collectable->getType() == TypeItems::COLLECTABLE2 ||
		collectable->getType() == TypeItems::COLLECTABLE3) {
		bag.push_back(collectable);
	}
}

Items* Player::getWeapon() {
	return weapon;
}

void Player::equipWeapon(Items* item) {

	//equip only when the item is type of weapon
	if (item->getType() == TypeItems::WEAPON) {

		if (!isEquipWeapon()) { //for equiping if the player is not equipped 

			weapon = item;
		}
		else { //for equippng if the player is already equipped

			//delete the current object of the weapon
			delete weapon;

			//and replace it with the new one
			weapon = item;
		}

	}
}

bool Player::isEquipWeapon() {
	return weapon != nullptr;
}

void Player::disarmWeapon() {
	
	delete weapon;
	weapon = nullptr;
}

Player::~Player() {

	delete[] sprite;

}
