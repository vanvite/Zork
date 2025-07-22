// myZork game created by Van Vite
#ifndef WORLD_H
#define WORLD_H

#include <vector>
#include "Entity.h"
class Player;

class World
{
private:
	vector<Entity*> entities;
	Player* alice;
public:
	World();
	~World();
	void ParseCommand(string c);
};

#endif // WORLD_H