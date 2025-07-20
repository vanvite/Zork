// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class NPC : public Creature
{
private:
public:
	NPC(string n, string d, Room* loc);
	~NPC();
};

#endif // NPC_H

