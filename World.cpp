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
	Room* roomGarden = new Room("Queen's Garden", "A beautiful garden filled with red rose bushes.");
	entities.push_back(roomHole);
	entities.push_back(roomWood);
	entities.push_back(roomHouse);
	entities.push_back(roomParty);
	entities.push_back(roomGarden);

	// Creatures
	alice = new Player("ALICE", " is normal in size.", roomHole);
	entities.push_back(alice);

	string dHatter = "";
	NPC* npcHatter = new NPC("HATTER", "", roomParty, dHatter);
	entities.push_back(npcHatter);
	roomParty->addContains(npcHatter);

	string dCat = "";
	NPC* npcCat = new NPC("CAT", "", roomHole, dCat);
	entities.push_back(npcCat);
	roomHole->addContains(npcCat);

	// Rabbit Hole exits and items
	Exit* exitHoleW = new Exit("West Exit", "A small brown door.", ExitDirection::WEST, roomHole, roomWood, 1);
	Exit* exitHoleE = new Exit("East Exit", "An open tunnel.", ExitDirection::EAST, roomHole, roomHouse, 0);
	Exit* exitHoleS = new Exit("South Exit", "A small purple door.", ExitDirection::SOUTH, roomHole, roomParty, 1);
	entities.push_back(exitHoleW);
	entities.push_back(exitHoleE);
	entities.push_back(exitHoleS);
	roomHole->addContains(exitHoleW);
	roomHole->addContains(exitHoleE);
	roomHole->addContains(exitHoleS);

	// Tulgey Wood exits and items
	Exit* exitWoodE = new Exit("East Exit", "A small brown door.", ExitDirection::EAST, roomWood, roomHole, 1);
	Item* itemTree = new Item("TREE", "A very tall Tumtum tree.");
	Item* itemClock = new Item("CLOCK", "This appears to be missing some pieces.");
	entities.push_back(exitWoodE);
	entities.push_back(itemTree);
	entities.push_back(itemClock);
	roomWood->addContains(exitWoodE);
	roomWood->addContains(itemTree);
	itemTree->addContains(itemClock);

	// White Rabbit's House exits and items
	Exit* exitHouseW = new Exit("West Exit", "An open tunnel.", ExitDirection::WEST, roomHouse, roomHole, 0);
	Exit* exitHouseS = new Exit("South Exit", "An open pathway.", ExitDirection::SOUTH, roomHouse, roomGarden, 0);
	Item* itemPotion = new Item("POTION", "The bottle is labelled 'Drink Me'.");
	entities.push_back(exitHouseW);
	entities.push_back(exitHouseS);
	entities.push_back(itemPotion);
	roomHouse->addContains(exitHouseW);
	roomHouse->addContains(exitHouseS);
	roomHouse->addContains(itemPotion);

	// Tea Party exits and items
	Exit* exitPartyN = new Exit("North Exit", "A small purple door.", ExitDirection::NORTH, roomParty, roomHole, 1);
	Exit* exitPartyE = new Exit("East Exit", "An open gate.", ExitDirection::EAST, roomParty, roomGarden, 0);
	Item* itemCake = new Item("CAKE", "The box is labelled 'Eat Me'.");
	entities.push_back(exitPartyN);
	entities.push_back(exitPartyE);
	entities.push_back(itemCake);
	roomParty->addContains(exitPartyN);
	roomParty->addContains(exitPartyE);
	roomParty->addContains(itemCake);

	// Queen's Garden exits and items
	Exit* exitGardenN = new Exit("North Exit", "An open pathway.", ExitDirection::NORTH, roomGarden, roomHouse, 0);
	Exit* exitGardenW = new Exit("West Exit", "An open gate.", ExitDirection::WEST, roomGarden, roomParty, 0);
	Item* itemToolshed = new Item("TOOLSHED", "descr");
	Item* itemGears = new Item("GEARS", "This looks like the missing clock pieces!");
	entities.push_back(exitGardenN);
	entities.push_back(exitGardenW);
	entities.push_back(itemToolshed);
	entities.push_back(itemGears);
	roomGarden->addContains(exitGardenN);
	roomGarden->addContains(exitGardenW);
	roomGarden->addContains(itemToolshed);
	itemToolshed->addContains(itemGears);
}

// Destructor
World::~World()
{
	for (Entity* e : entities)
	{
		delete e;
	}
}

// Splits a string into a vector of substrings
vector<string> World::SplitString(string c, string delimiter)
{
	vector<string> s;
	size_t start = 0;
	size_t end = c.find(delimiter);

	if (start == string::npos) { // If 1 word only
		s.push_back(c);
	}
	else {
		while (end != string::npos) // If multiple words
		{
			s.push_back(c.substr(start, end-start));
			start = end + delimiter.length();
			end = c.find(delimiter, start);
		}
		s.push_back(c.substr(start, end - start));
	}

	return s;
}

// Executes a command as a Player action
void World::ParseCommand(string &command)
{
	if (!command.empty() && command != "QUIT GAME")
	{
		vector<string> c = SplitString(command, " ");
		bool isValid = 0;

		if (!c.empty())
		{
			cout << "-----\n";
			if (c[0] == "LOOK") {
				isValid = alice->Look();
			}
			else if (c[0] == "CHECK") {
				isValid = alice->Check();
			}
			else if (c[0] == "GO") {
				isValid = alice->Go(c);
			}
			else if (c[0] == "ASK") {
				isValid = alice->Ask(c);
			}
			else if (c[0] == "EXAMINE") {
				isValid = alice->Examine(c);
			}
			else if (c[0] == "GET") {
				isValid = alice->Get(c);
			}
			else if (c[0] == "DROP") {
				isValid = alice->Drop(c);
			}
			else if (c[0] == "USE" || c[0] == "DRINK" || c[0] == "EAT") {
				isValid = alice->Use(c);
			}
			else if (c[0] == "PUT") {
				isValid = alice->PutIn(c);
				if (alice->getGameWon()) {
					ShowWin();
					command = "QUIT GAME";
				}
			}
			else {
				isValid = 0;
			}

			if (!isValid)
			{
				cout << "I cannot do that command.\n";
			}
			cout << "==========\n";
		}
	}
}

void World::ShowWin()
{
	cout << "The alarm clock rings... Alice wakes up and escapes Wonderland!\n";
}