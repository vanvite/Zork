// myZork game created by Van Vite
#include "Player.h"

// Constructor
Player::Player(string n, string d, Room* loc)
	: Creature(EntityType::PLAYER, n, d, loc),
	status(Size::NORMAL),
	gameWon(0)
{
	// Initializer list used
}

// Destructor
Player::~Player()
{
	//
}

string Player::getstrStatus() const
{
	switch (status)
	{
	case Size::SMALL:
		return "Small";
		break;
	case Size::NORMAL:
		return "Normal";
		break;
	case Size::LARGE:
		return "Large";
		break;
	default:
		return "unknown";
	}
}

bool Player::getGameWon() const
{
	return gameWon;
}

// Prints description of current room and Player status
bool Player::Look(vector<string> action)
{
	return 1;
}

// Moves to the adjacent room
bool Player::Go(vector<string> action)
{
	if (action[1] == "NORTH" || action[1] == "EAST"
		|| action[1] == "SOUTH" || action[1] == "WEST")
	{
		return 1;
	}
	else {
		return 0;
	}
}

// Talks to an NPC
bool Player::Ask(vector<string> action)
{
	if (action[1] == "CAT" || action[1] == "HATTER")
	{
		return 1;
	}
	else {
		return 0;
	}
}

// Picks up an item
bool Player::Take(vector<string> action)
{
	if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "CLOCK BELLS")
	{
		return 1;
	}
	else{
		return 0;
	}
}

// Puts an item down
bool Player::Drop(vector<string> action)
{
	if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "CLOCK BELLS")
	{
		return 1;
	}
	else {
		return 0;
	}
}

// Uses an item (e.g. eat cake, drink potion)
bool Player::Use(vector<string> action)
{
	if (action[1] == "POTION") // Shrink
	{
		switch (status)
		{
		case Size::SMALL:
			cout << "Alice is small and cannot shrink any further.\n";
			break;
		case Size::NORMAL:
			status = Size::SMALL;
			break;
		case Size::LARGE:
			status = Size::NORMAL;
			break;
		}
	}
	else if (action[1] == "CAKE") // Grow
	{
		switch (status)
		{
		case Size::SMALL:
			status = Size::NORMAL;
			break;
		case Size::NORMAL:
			status = Size::LARGE;
			break;
		case Size::LARGE:
			cout << "Alice is large and cannot grow any further.\n";
			break;
		}
	}
	else if (action[1] == "CLOCK BELLS") // Wake up
	{
		//
	}
	else
	{
		return 0;
	}
	return 1;
}

// Puts one item into another
bool Player::PutIn(vector<string> action)
{
	if (action[1] == "POTION" || action[1] == "CAKE")
	{
		if (action[2] == "IN") {
			if (action[3] == "TOOLSHED")
			{
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else if (action[1] == "CLOCK BELLS")
	{
		if (action[2] == "IN")
		{
			if (action[3] == "ALARM CLOCK") // Player wins
			{
				gameWon = 1;
				return 1;
			}
			else {
				return 0;
			}
		}
		else {
			return 0;
		}
	}
	else{
		return 0;
	}
}