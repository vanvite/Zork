// myZork game created by Van Vite
#include "Player.h"
#include "NPC.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"

// Constructor
Player::Player(string n, string d, Room* loc)
	: Creature(EntityType::PLAYER, n, d, loc),
	status(PlayerSize::NORMAL),
	gameWon(0)
{
	// Initializer list used
}

// Destructor
Player::~Player()
{
	// No new pointers in derived class
}

// Returns string of Player size status
string Player::getstrStatus() const
{
	switch (status)
	{
	case PlayerSize::SMALL:
		return "small";
	case PlayerSize::NORMAL:
		return "normal";
	case PlayerSize::LARGE:
		return "large";
	default:
		return "unknown";
	}
}

// Retuerns whether or not the Player has won the game
bool Player::getGameWon() const{
	return gameWon;
}

// Finds a certain Item in Player inventory
Item* Player::findItem(string name)
{
	for (int i = 0; i < getContains().size(); i++)
	{
		if (EntityType::ITEM == getContains().at(i)->getType())
		{
			Item* target = dynamic_cast<Item*>(getContains().at(i));
			if (name == target->getName())
			{
				return target;
			}
		}
	}

	return NULL; // If Item not found
}

// Displays the Room description and contents
bool Player::Look()
{
	cout	<< "Alice is at the " << getLocation()->getstrEntity()
			<< "This room contains:\n"
			<< getLocation()->getstrContains();
	return 1;
}

// Displays the Player size and inventory
bool Player::Check()
{
	cout << "Alice" << getDescription() << endl;

	if (getstrContains().empty()) {
		cout << "Inventory is empty.\n";
	}
	else {
		cout << "Inventory Items:\n" << getstrContains();
	}

	return 1;
}

// Moves Player to the target room
bool Player::Go(vector<string> action)
{
	if (action.size() > 1) {
		if (action[1] == "NORTH" || action[1] == "EAST"
			|| action[1] == "SOUTH" || (action[1] == "WEST"))
		{
			Exit* myExit = getLocation()->findExit(action[1]);
			if (myExit != NULL)
			{
				// If small Exit, checks if Player is small
				if (myExit->isSmall() && (status != PlayerSize::SMALL))
				{
					cout << "Alice cannot fit through the door. ";
					return 0;
				}

				// If Player fits through Exit, updates Player location
				setLocation(myExit->getDestination());
				Look();
				return 1;
			}
			else { 
				cout << "This room has no " << action[1] << " exit. ";
				return 0;
			}
		}
		else { return 0; }
	}
	else { return 0; }
}

// Displays helpful information from an NPC
bool Player::Ask(vector<string> action)
{
	if (action.size() > 1) {
		if (action[1] == "CAT" || action[1] == "HATTER")
		{
			NPC* myNPC = getLocation()->findNPC(action[1]);
			if (myNPC != NULL) // Checks if NPC is in the room
			{
				myNPC->Speak();
				return 1;
			}
			else {
				cout << action[1] << " is not in this room. ";
				return 0;
			}
		}
		else { return 0; }
	}
	else { return 0; }
}

// Displays information about an item or container
bool Player::Examine(vector<string> action)
{
	if (action.size() > 1)
	{
		if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS"
			|| action[1] == "TREE" || action[1] == "TOOLSHED" || action[1] == "CLOCK")
		{
			Item* myItem = getLocation()->findItem(action[1]);
			Item* myInventoryItem = findItem(action[1]);

			if (myItem != NULL) // Checks if Item is in the room
			{
				cout << myItem->getstrEntity();
				if (myItem->getName() == "TREE" || myItem->getName() == "TOOLSHED")
				{
					if (!myItem->getContains().empty())
					{
						cout << "contains:\n" << myItem->getstrContains();
					}
				}
				return 1;
			}
			else if (myInventoryItem != NULL) // Checks if Item is in Player inventory
			{
				cout << myInventoryItem->getstrEntity();
				return 1;
			}
			else {
				cout << action[1] << " is not here. ";
				return 0;
			}
		}
		else { return 0; }
	}
	else { return 0; }
}

// Picks up an item
bool Player::Get(vector<string> action)
{
	if (action.size() > 1)
	{
		if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS")
		{
			// If Player is in the Queen's Garden
			if (getLocation()->getName() == "Queen's Garden")
			{
				Item* myToolshed = getLocation()->findItem("TOOLSHED");
				Item* toolshedItem = myToolshed->findItem(action[1]);

				if (toolshedItem != NULL) // Checks if Item is in the toolshed
				{
					myToolshed->removeContains(toolshedItem); // Removes Item from the toolshed
					addContains(toolshedItem); // Adds Item to Player inventory
					cout << action[1] << " is now in Alice's inventory.\n";
					return 1;
				}
				else {
					// If not in toolshed, continue with the function below
				}
			}

			// Checks if Item is in the room
			Item* myItem = getLocation()->findItem(action[1]);
			if (myItem != NULL)
			{
				getLocation()->removeContains(myItem); // Removes Item from the Room
				addContains(myItem); // Adds Item to Player inventory
				cout << action[1] << " is now in Alice's inventory.\n";
				return 1;
			}
			else {
				cout << action[1] << " is not here. ";
				return 0;
			}
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
			Item* myItem = findItem(action[1]);
			if (myItem != NULL)
			{
				removeContains(myItem); // Removes Item from Player inventory
				getLocation()->addContains(myItem); // Adds Item to the room
				cout	<< "Alice leaves the " << action[1]
						<< " in the " << getLocation()->getName() << endl;
				return 1;
			}
			else {
				cout << action[1] << " is not in Alice's inventory. ";
				return 0;
			}
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
		if ((action[0] == "DRINK" || action[0] == "USE")
			&& action[1] == "POTION") // Drink potion to shrink
		{
			switch (status)
			{
			case PlayerSize::SMALL:
				cout << "Alice is small and cannot shrink any further.\n";
				break;
			case PlayerSize::NORMAL:
				status = PlayerSize::SMALL;
				cout << "Alice shrinks to small size.\n";
				break;
			case PlayerSize::LARGE:
				status = PlayerSize::NORMAL;
				cout << "Alice shrinks to normal size.\n";
				break;
			}
		}
		else if ((action[0] == "EAT" || action[0] == "USE")
			&& (action[1] == "CAKE")) // Eat cake to grow
		{
			switch (status)
			{
			case PlayerSize::SMALL:
				status = PlayerSize::NORMAL;
				cout << "Alice grows to normal size.\n";
				break;
			case PlayerSize::NORMAL:
				status = PlayerSize::LARGE;
				cout << "Alice grows to large size.\n";
				break;
			case PlayerSize::LARGE:
				cout << "Alice is large and cannot grow any further.\n";
				break;
			}
		}
		else { return 0; }

		setDescription(string(" is " + getstrStatus() + " in size."));
		return 1;
	}
	else { return 0; }
}

// Puts an Item into a container Item
bool Player::PutIn(vector<string> action)
{
	if (action.size() > 3)
	{
		if (action[2] == "IN") // Checks for "PUT...IN"
		{
			if (action[3] == "TOOLSHED") // Checks for "PUT Item IN TOOLSHED"
			{
				if (action[1] == "POTION" || action[1] == "CAKE" || action[1] == "GEARS")
				{
					if (getLocation()->getName() == "Queen's Garden") // Checks if Player is in correct room
					{
						Item* myItem = findItem(action[1]);
						Item* myToolshed = getLocation()->findItem("TOOLSHED");
						if (myItem != NULL) // Checks if Player has the Item
						{
							removeContains(myItem); // Removes Item from Player inventory
							myToolshed->addContains(myItem); // Adds Item to the toolshed
							return 1;
						}
						else {
							cout << action[1] << " is not in Alice's inventory. ";
							return 0;
						}
					}
					else {
						cout << "TOOLSHED is not in this room. ";
						return 0;
					}
				}
				else { return 0; }
			}
			else if ((action[1] == "GEARS") && (action[3] == "CLOCK")) // Checks for "PUT GEARS IN CLOCK"
			{
				if (getLocation()->getName() == "Tulgey Wood") // Checks if Player is in correct room
				{
					Item* myItem = findItem(action[1]);
					if (myItem != NULL) // Checks if Player has GEARS
					{
						if (status == PlayerSize::LARGE) // Checks if Player can reach the clock
						{
							gameWon = 1; // Player wins the game
							return 1;
						}
						else {
							cout << "Alice cannot reach the clock. ";
							return 0;
						}
					}
					else {
						cout << "GEARS is not in Alice's inventory. ";
						return 0;
					}
				}
				else {
					cout << "CLOCK is not in this room. ";
					return 0;
				}
			}
			else { return 0; }
		}
		else { return 0; }
	}
	else { return 0; }
}