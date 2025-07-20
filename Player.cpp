// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "Player.h"

// Constructor
Player::Player(string n, string d, Room* loc)
	: Creature(EntityType::PLAYER, n, d, loc)
{
	// Initializer list used
}

// Destructor
Player::~Player()
{
	//
}