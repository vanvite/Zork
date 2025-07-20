// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Room.h"

enum class ExitDirection
{
	NORTH, EAST, SOUTH, WEST
};

class Exit : public Entity
{
private:
	ExitDirection direction;
	Room* source;
	Room* destination;
public:
	Exit(string n, string d, ExitDirection dir, Room* src, Room* des);
	~Exit();
	ExitDirection getDirection() const;
	Room* getSource() const;
	Room* getDestination() const;
	void setDirection(ExitDirection dir);
	void setSource(Room* src);
	void setDestination(Room* des);
};

#endif // EXIT_H