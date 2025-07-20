// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#include "Entity.h"

// Constructor
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

void Entity::Update()
{
	//
}