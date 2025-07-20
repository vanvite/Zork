// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef ENTITY_H
#define ENTITY_H

using namespace std;
#include <iostream>
#include <list>

enum class EntityType
{
	ENTITY,	CREATURE, NPC, PLAYER, EXIT, ROOM, ITEM
};

class Entity
{
private:
	EntityType type;
	string name;
	string description;
	list<Entity*> contains;
public:
	Entity(string n, string d);
	Entity(EntityType t, string n, string d);
	~Entity();
	EntityType getType() const;
	string getName() const;
	string getDescription() const;
	list<Entity*> getContains() const;
	void setType(EntityType t);
	void setName(string n);
	void setDescription(string d);
	void setContains(list<Entity*> c);
	virtual void Update();
};

#endif // ENTITY_H