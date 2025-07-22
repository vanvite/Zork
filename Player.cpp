// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "Player.h"

// Constructor
Player::Player(string n, string d, Room* loc)
	: Creature(EntityType::PLAYER, n, d, loc),
	status(Size::NORMAL)
{
	// Initializer list used
}

// Destructor
Player::~Player()
{
	//
}

// Prints description of current room and Player status
void Player::Look(vector<string> action)
{
	//
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
bool Player::TalkTo(vector<string> action)
{
	if (!(action[1] == "CHESHIRE" || action[1] == "CAT"
		|| action[1] == "MAD" || action[1] == "HATTER")
		||
		!(action[2] == "CHESHIRE" || action[2] == "CAT"
			|| action[2] == "MAD" || action[2] == "HATTER"))
	{
		return 0;
	}
	else {
		return 1;
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
bool Player::Use(vector<string> action, bool& win)
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
	if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "CLOCK BELLS")
	{
		if (action[2] == "IN")
		{
			if (action[3] == "TOOLSHED" || action[3] == "ALARM CLOCK")
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
	else {
		return 0;
	}
}