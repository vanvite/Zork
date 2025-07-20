// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "World.h"

// Constructor
World::World()
{
	//
}

// Destructor
World::~World()
{
	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}
}