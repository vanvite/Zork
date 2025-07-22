// myZork game created by Van Vite
using namespace std;
#include <iostream>
#include <string>
#include "World.h"

int main()
{
	World myWorld;
	cout	<< "Welcome to myZork - a simple text-based game created by Van Vite, "
			<< "inspired by the game Zork (1977) and the novel Alice's Adventures "
			<< "in Wonderland (1865). Try the command LOOK AROUND to begin playing. "
			<< "Enter EXIT GAME to quit.\n\n";
	string myCommand = "";
	while (myCommand != "EXIT GAME")
	{
		myWorld.ParseCommand(myCommand);
		getline(cin, myCommand);
	}
	return 0;
}