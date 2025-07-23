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
	// No new pointers in derived class
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
	cout	<< getLocation()->getstrEntity()
			<< "This room contains:\n"
			<< getLocation()->getstrContains();
	return 1;
}

// Moves Player to the target room
bool Player::Go(vector<string> action)
{
	if (action.size() > 1) {
		if (action[1] == "NORTH" || action[1] == "EAST"
			|| action[1] == "SOUTH" || action[1] == "WEST")
		{
			// move
			return 1;
		}
		else { return 0; }
	}
	else { return 0; }
}

// Talks to an NPC
bool Player::Ask(vector<string> action)
{
	if (action.size() > 1) {
		if (action[1] == "CAT" || action[1] == "HATTER")
		{
			// Display dialog
			return 1;
		}
		else { return 0; }
	}
	else { return 0; }
}

// Picks up an item
bool Player::Take(vector<string> action)
{
	if (action.size() > 1)
	{
		if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS")
		{
			// pick up
			return 1;
		}
		else { return 0; }
	}
	else { return 0; }
}

// Puts an item down
bool Player::Drop(vector<string> action)
{
	if (action.size() > 1)
	{
		if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS")
		{
			// put down
			return 1;
		}
		else { return 0; }
	}
	else { return 0; }
}

// Uses an item
bool Player::Use(vector<string> action)
{
	if (action.size() > 1)
	{
		if (action[1] == "POTION") // Drink potion to shrink
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
		else if (action[1] == "CAKE") // Eat cake to grow
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
		else { return 0; }

		return 1;
	}
	else { return 0; }
}

// Puts one item into another
bool Player::PutIn(vector<string> action)
{
	if (action.size() > 3)
	{
		if (action[3] == "TOOLSHED")
		{
			if (action[2] == "IN") {
				if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS")
				{
					// put in
					return 1;
				}
				else { return 0; }
			}
			else { return 0; }
		}
		else if (action[3] == "CLOCK")
		{
			if (action[2] == "IN")
			{
				if (action[1] == "GEARS") // Player wins
				{
					gameWon = 1;
					return 1;
				}
				else { return 0; }
			}
			else { return 0; }
		}
		else { return 0; }
	}
	else { return 0; }
}