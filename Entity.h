// myZork game created by Van Vite
#ifndef ENTITY_H
#define ENTITY_H

using namespace std;
#include <iostream>
#include <vector>

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
	vector<Entity*> contains;
public:
	Entity(string n, string d);
	Entity(EntityType t, string n, string d);
	~Entity();
	EntityType getType() const;
	string getName() const;
	string getDescription() const;
	vector<Entity*> getContains() const;
	void setType(EntityType t);
	void setName(string n);
	void setDescription(string d);
	void setContains(vector<Entity*> c);
	virtual void Update();
	string getstrEntity() const;
	bool hasEntity(Entity* e);
	void addContains(Entity* e);
	void removeContains(Entity* e);
	string getstrContains() const;
};

#endif // ENTITY_H