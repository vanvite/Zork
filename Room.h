// myZork game created by Van Vite
#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"
class Exit;
class NPC;
class Item;

class Room : public Entity
{
private:
public:
	Room(string n, string d);
	~Room();
	Exit* findExit(string direction);
	NPC* findNPC(string name);
	Item* findItem(string name);
};

#endif // ROOM_H