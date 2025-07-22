// myZork game created by Van Vite
#include "World.h"
#include "Player.h"
#include "Room.h"
#include "Exit.h"
#include "Item.h"
#include "NPC.h"
#include <iostream>
#include <string>

// Constructor
World::World()
{
	// Rooms
	Room* roomHole = new Room("Rabbit Hole", "");
	Room* roomWood = new Room("Tulgey Wood", "");
	Room* roomHouse = new Room("White Rabbit's House", "");
	Room* roomParty = new Room("Tea Party", "");
	Room* roomGarden = new Room("Queen's Garden", "");
	entities.push_back(roomHole);
	entities.push_back(roomWood);
	entities.push_back(roomHouse);
	entities.push_back(roomParty);
	entities.push_back(roomGarden);

	// Creatures
	alice = new Player("Alice", "", roomHole);
	NPC* npcMadHatter = new NPC("Mad Hatter", "", roomParty);
	NPC* npcCheshireCat = new NPC("Cheshire Cat", "", roomWood);
	entities.push_back(alice);
	entities.push_back(npcMadHatter);
	entities.push_back(npcCheshireCat);

	// Rabbit Hole exits and items
	Exit* exitHoleW = new Exit("West Exit", "A small brown door", ExitDirection::WEST, roomHole, roomWood);
	Exit* exitHoleE = new Exit("East Exit", "An open tunnel", ExitDirection::EAST, roomHole, roomHouse);
	Exit* exitHoleS = new Exit("South Exit", "A small purple door", ExitDirection::SOUTH, roomHole, roomParty);
	entities.push_back(exitHoleW);
	entities.push_back(exitHoleE);
	entities.push_back(exitHoleS);

	// Tulgey Wood exits and items
	Exit* exitWoodE = new Exit("East Exit", "A small brown door", ExitDirection::EAST, roomWood, roomHole);
	Item* itemTree = new Item("Tumtum Tree", "descr");
	Item* itemClock = new Item("Alarm Clock", "descr");
	entities.push_back(exitWoodE);
	entities.push_back(itemTree);
	entities.push_back(itemClock);

	// White Rabbit's House exits and items
	Exit* exitHouseW = new Exit("West Exit", "An open tunnel", ExitDirection::WEST, roomHouse, roomHole);
	Exit* exitHouseS = new Exit("South Exit", "An open pathway", ExitDirection::SOUTH, roomHouse, roomGarden);
	Item* itemPotion = new Item("Potion Bottle", "descr");
	entities.push_back(exitHouseW);
	entities.push_back(exitHouseS);
	entities.push_back(itemPotion);

	// Tea Party exits and items
	Exit* exitPartyN = new Exit("North Exit", "A small purple door", ExitDirection::NORTH, roomParty, roomHole);
	Exit* exitPartyE = new Exit("East Exit", "An open gate", ExitDirection::EAST, roomParty, roomGarden);
	Item* itemCake = new Item("Cake", "descr");
	entities.push_back(exitPartyN);
	entities.push_back(exitPartyE);
	entities.push_back(itemCake);

	// Queen's Garden exits and items
	Exit* exitGardenN = new Exit("North Exit", "An open pathway", ExitDirection::NORTH, roomGarden, roomHouse);
	Exit* exitGardenW = new Exit("West Exit", "An open gate", ExitDirection::WEST, roomGarden, roomParty);
	Item* itemToolshed = new Item("Toolshed", "descr");
	Item* itemBells = new Item("Clock Bells", "descr");
	entities.push_back(exitGardenN);
	entities.push_back(exitGardenW);
	entities.push_back(itemToolshed);
	entities.push_back(itemBells);
}

// Destructor
World::~World()
{
	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}

void World::ParseCommand(string c)
{
	if (!c.empty()) {
		vector<string> command;
	}
}