// myZork game created by Van Vite
#include "Entity.h"

// Default Constructor
Entity::Entity(string n, string d)
	: type(EntityType::ENTITY), name(n), description(d)
{
	// Initializer list used
}

// Constructor with type of Entity
Entity::Entity(EntityType t, string n, string d)
	: type(t), name(n), description(d)
{
	// Initializer list used
}

// Destructor
Entity::~Entity()
{
	contains.clear();
}

// Getters
EntityType Entity::getType() const{
	return type;
}
string Entity::getName() const{
	return name;
}
string Entity::getDescription() const{
	return description;
}
vector<Entity*> Entity::getContains() const{
	return contains;
}

// Setters
void Entity::setType(EntityType t){
	type = t;
}
void Entity::setName(string n){
	name = n;
}
void Entity::setDescription(string d){
	description = d;
}
void Entity::setContains(vector<Entity*> c){
	contains = c;
}

// Virtual function needed for dynamic_cast
void Entity::Update(){
	// empty
}

// Returns string of Entity name and description
string Entity::getstrEntity() const
{
	string s = "";
	s = name + " - " + description + "\n";
	return s;
}

// Checks whether or not the Entity contains a certain Entity
bool Entity::hasEntity(Entity* e)
{
	bool has = 0;
	for (int i = 0; i < contains.size(); i++)
	{
		if (e->getName() == contains[i]->getName()) {
			has = 1;
		}
	}
	return has;
}

// Adds a given Entity to the contains list
void Entity::addContains(Entity* e)
{
	if (hasEntity(e)) {
		cout << getName() << " already has " << e->getName() << endl;
	}
	else {
		contains.push_back(e);
	}
}

// Removes a given Entity from the contains list
void Entity::removeContains(Entity* e)
{
	for (int i = 0; i < contains.size(); i++)
	{
		if (e->getName() == contains[i]->getName()) {
			contains.erase(contains.begin() + i);
		}
	}
}

// Returns string of entities in contains
string Entity::getstrContains() const
{
	string s = "";
	for (int i = 0; i < contains.size(); i++)
	{
		s += contains[i]->getstrEntity();
	}
	return s;
}