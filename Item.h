// myZork game created by Van Vite
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
private:
public:
	Item(string n, string d);
	~Item();
	Item* findItem(string name);
};

#endif // ITEM_H