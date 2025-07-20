// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "Creature.h"

// Default Constructor
Creature::Creature(string n, string d, Room* loc)
	: Entity(EntityType::CREATURE, n, d),
	location(loc)
{
	// Initializer list used
}

// Constructor with child class
Creature::Creature(EntityType t, string n, string d, Room* loc)
	: Entity(t, n, d),
	location(loc)
{
	// Initializer list used
}

// Destructor
Creature::~Creature()
{
	delete location;
}