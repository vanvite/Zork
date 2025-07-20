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

// Returns the vector of Entities in the World
vector<Entity*> World::getEntities() const
{
	return entities;
}

// Sets the vector of Entities in the World
void World::setEntities(vector<Entity*> e)
{
	entities = e;
}