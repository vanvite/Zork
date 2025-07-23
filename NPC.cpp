// myZork game created by Van Vite
#include "NPC.h"
#include <iostream>

// Constructor
NPC::NPC(string n, string d, Room* loc, string dg)
	: Creature(EntityType::NPC, n, d, loc),
	strDialog(dg)
{
	// Initializer list used
}

// Destructor
NPC::~NPC()
{
	//
}

string NPC::GetDialog() const
{
	return strDialog;
}

void NPC::Speak()
{
	cout << getName() << ": " << GetDialog() << endl;
}