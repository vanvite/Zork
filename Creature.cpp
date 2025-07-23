// myZork game created by Van Vite
#include "Creature.h"
#include "Room.h"

// Constructor
Creature::Creature(string n, string d, Room* loc)
	: Entity(EntityType::CREATURE, n, d),
	location(loc)
{
	// Initializer list used
}

// Constructor with type of Entity
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
Room* Creature::getLocation() const{
	return location;
}

// Sets the Creature's location
void Creature::setLocation(Room* r){
	location = r;
}