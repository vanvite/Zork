// myZork game created by Van Vite
#include "Item.h"

// Constructor
Item::Item(string n, string d)
	: Entity(EntityType::ITEM, n, d)
{
	// Initializer list used
}

// Destructor
Item::~Item()
{
	//
}

Item* Item::findItem(string name)
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