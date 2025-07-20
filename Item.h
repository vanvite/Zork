// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : public Entity
{
private:
public:
	Item(string n, string d);
	~Item();
};

#endif // ITEM_H