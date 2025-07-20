// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
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

// Returns the EntityType
EntityType Entity::getType() const
{
	return type;
}

// Returns the Entity's name
string Entity::getName() const
{
	return name;
}

// Returns the Entity's description
string Entity::getDescription() const
{
	return description;
}

// Returns the list contained by the Entity
list<Entity*> Entity::getContains() const
{
	return contains;
}

// Sets the EntityType
void Entity::setType(EntityType t)
{
	type = t;
}

// Sets the Entity's name
void Entity::setName(string n)
{
	name = n;
}

// Sets the Entity's description
void Entity::setDescription(string d)
{
	description = d;
}

// Sets the list contained by the Entity
void Entity::setContains(list<Entity*> c)
{
	contains = c;
}

// Updates the state of the Entity
void Entity::Update()
{
	//
}