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
	bool gameWon;
public:
	World();
	~World();
	void ParseCommand(string& command);
	void ShowWin();
};

#endif // WORLD_H