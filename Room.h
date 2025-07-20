// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

class Room : public Entity
{
private:
public:
	Room(string n, string d);
	~Room();
};

#endif // ROOM_H