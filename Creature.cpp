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

// Constructor with type of Creature Entity
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

// Returns the Creature's location
Room* Creature::getLocation() const
{
	return location;
}

// Sets the Creature's location
void Creature::setLocation(Room* r)
{
	location = r;
}