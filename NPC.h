// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef NPC_H
#define NPC_H

#include "Creature.h"

class NPC : public Creature
{
private:
	string strDialog;
public:
	NPC(string n, string d, Room* loc, string dg);
	~NPC();
	void Speak();
	string GetDialog() const;
};

#endif // NPC_H

