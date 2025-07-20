// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "Exit.h"

// Constructor
Exit::Exit(string n, string d, ExitDirection dir, Room* src, Room* des)
	: Entity(EntityType::EXIT, n, d),
	direction(dir),
	source(src),
	destination(des)
{
	// Initializer list used
}

// Destructor
Exit::~Exit()
{
	delete source;
	delete destination;
}

// Returns the ExitDirection
ExitDirection Exit::getDirection() const
{
	return direction;
}

// Returns the source room
Room* Exit::getSource() const
{
	return source;
}

// Returns the destination room
Room* Exit::getDestination() const
{
	return destination;
}

// Sets the ExitDirection
void Exit::setDirection(ExitDirection dir)
{
	direction = dir;
}

// Sets the source room
void Exit::setSource(Room* src)
{
	source = src;
}

// Sets the destination room
void Exit::setDestination(Room* des)
{
	destination = des;
}