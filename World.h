// myZork game created by Van Vite
#ifndef WORLD_H
#define WORLD_H

#include <list>
#include "Entity.h"
class Player;

class World
{
private:
	list<Entity*> entities;
	Player* alice;
public:
	World();
	~World();
	vector<string> SplitString(string c, string delimiter);
	void ParseCommand(string &command);
	void ShowWin();
};

#endif // WORLD_H