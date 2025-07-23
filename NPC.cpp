// myZork game created by Van Vite
#include "NPC.h"

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
	// No new pointers in derived class
}

// Getters
string NPC::GetDialog() const{
	return strDialog;
}

// Displays the NPC name and dialog
void NPC::Speak()
{
	cout << getName() << ": " << GetDialog() << endl;
}