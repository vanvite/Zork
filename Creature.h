// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"

class Creature : public Entity
{
private:
	Room* location;
public:
	Creature(string n, string d, Room* loc);
	Creature(EntityType t, string n, string d, Room* loc);
	~Creature();
	Room* getLocation() const;
	void setLocation(Room* r);
};

#endif // CREATURE_H