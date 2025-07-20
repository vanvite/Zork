// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : public Creature
{
private:
public:
	Player(string n, string d, Room* loc);
	~Player();
};

#endif // PLAYER_H