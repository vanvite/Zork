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
			<< "inspired by the game Zork (1977) and the novel Alice's Adventures "
			<< "in Wonderland (1865). Try the command LOOK AROUND to begin playing. "
			<< "Enter EXIT GAME to quit.\n\n";
	string myCommand = "";
	while (myCommand != "EXIT GAME")
	{
		//myWorld.ParseCommand(myCommand);
		getline(cin, myCommand);
		transform(myCommand.begin(), myCommand.end(), myCommand.begin(), ::toupper);
	}
	return 0;
}