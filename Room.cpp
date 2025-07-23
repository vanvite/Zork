// myZork game created by Van Vite
#include "Room.h"
#include "Exit.h"
#include "NPC.h"
#include "Item.h"

// Constructor
Room::Room(string n, string d)
	: Entity(EntityType::ROOM, n, d)
{
	// Initializer list used
}

// Destructor
Room::~Room()
{
	// No new pointers in derived class
}

// Finds a certain Exit in the Room
Exit* Room::findExit(string direction)
{	
	for (int i = 0; i < getContains().size(); i++)
	{
		if (EntityType::EXIT == getContains().at(i)->getType())
		{
			Exit* target = dynamic_cast<Exit*>(getContains().at(i));
			if (direction == target->getstrDirection())
			{
				return target;
			}
		}
	}

	return NULL; // If Exit not found
}

// Finds a certain NPC in the Room
NPC* Room::findNPC(string name)
{
	for (int i = 0; i < getContains().size(); i++)
	{
		if (EntityType::NPC == getContains().at(i)->getType())
		{
			NPC* target = dynamic_cast<NPC*>(getContains().at(i));
			if (name == target->getName())
			{
				return target;
			}
		}
	}

	return NULL; // If NPC not found
}

// Finds a certain Item in the Room
Item* Room::findItem(string name)
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