// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef WORLD_H
#define WORLD_H

using namespace std;
#include <iostream>
#include <vector>
#include "Entity.h"

class World
{
private:
	vector<Entity*> entities;
public:
	World();
	~World();
};

#endif // WORLD_H