// C++ Test - Simple Zork Game Assignment
// by Van Wreena Xiel Vite
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <vector>

enum class Size {
	SMALL, NORMAL, LARGE
};

class Player : public Creature
{
private:
	Size status;
public:
	Player(string n, string d, Room* loc);
	~Player();
	void Look(vector<string> action);
	bool Go(vector<string> action);
	bool TalkTo(vector<string> action);
	bool Take(vector<string> action);
	bool Drop(vector<string> action);
	bool Use(vector<string> action, bool& win);
	bool PutIn(vector<string> action);
};

#endif // PLAYER_H