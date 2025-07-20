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