// myZork game created by Van Vite
#include "Exit.h"
#include "Room.h"

// Constructor
Exit::Exit(string n, string d, ExitDirection dir, Room* src, Room* des, bool small)
	: Entity(EntityType::EXIT, n, d),
	direction(dir),
	source(src),
	destination(des),
	smallExit(small)
{
	// Initializer list used
}

// Destructor
Exit::~Exit()
{
	delete source;
	delete destination;
}

// Returns string of Exit direction
string Exit::getstrDirection() const
{
	switch (direction)
	{
	case ExitDirection::NORTH:
		return "NORTH";
	case ExitDirection::EAST:
		return "EAST";
	case ExitDirection::SOUTH:
		return "SOUTH";
	case ExitDirection::WEST:
		return "WEST";
	default:
		return "unknown";
	}
}

// Getters
ExitDirection Exit::getDirection() const{
	return direction;
}
Room* Exit::getSource() const{
	return source;
}
Room* Exit::getDestination() const{
	return destination;
}
bool Exit::isSmall() const{
	return smallExit;
}

// Setters
void Exit::setDirection(ExitDirection dir){
	direction = dir;
}
void Exit::setSource(Room* src){
	source = src;
}
void Exit::setDestination(Room* des){
	destination = des;
}