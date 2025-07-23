// myZork game created by Van Vite
using namespace std;
#include "World.h"
#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	World myWorld;
	cout	<< "Welcome to myZork - a simple text-based game created by Van Vite, "
			<< "inspired by Zork (1977 game) and Alice's Adventures in Wonderland "
			<< "(1865 novel). Try the command LOOK to begin playing. "
			<< "Enter QUIT GAME at any time.\n\n";
	string myCommand = "";
	while (myCommand != "QUIT GAME")
	{
		getline(cin >> ws, myCommand);
		transform(myCommand.begin(), myCommand.end(), myCommand.begin(), ::toupper);
		myWorld.ParseCommand(myCommand);
	}
	return 0;
}