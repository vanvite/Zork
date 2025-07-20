// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "NPC.h"

// Constructor
NPC::NPC(string n, string d, Room* loc)
	: Creature(EntityType::NPC, n, d, loc)
{
	// Initializer list used
}

// Destructor
NPC::~NPC()
{
	//
}