// myZork game created by Van Vite
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
	bool gameWon;
public:
	Player(string n, string d, Room* loc);
	~Player();
	string getstrStatus() const;
	bool getGameWon() const;
	bool Look(vector<string> action);
	bool Go(vector<string> action);
	bool Ask(vector<string> action);
	bool Take(vector<string> action);
	bool Drop(vector<string> action);
	bool Use(vector<string> action);
	bool PutIn(vector<string> action);
};

#endif // PLAYER_H