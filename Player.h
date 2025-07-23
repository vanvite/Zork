// myZork game created by Van Vite
#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include <vector>
class Item;

enum class PlayerSize {
	SMALL, NORMAL, LARGE
};

class Player : public Creature
{
private:
	PlayerSize status;
	bool gameWon;
public:
	Player(string n, string d, Room* loc);
	~Player();
	string getstrStatus() const;
	bool getGameWon() const;
	Item* findItem(string name);
	bool Look();
	bool Check();
	bool Go(vector<string> action);
	bool Ask(vector<string> action);
	bool Examine(vector<string> action);
	bool Get(vector<string> action);
	bool Drop(vector<string> action);
	bool Use(vector<string> action);
	bool PutIn(vector<string> action);
};

#endif // PLAYER_H