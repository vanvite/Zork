# About

myZork - a simple text-based game inspired by Zork (1977 game) and Alice's Adventures in Wonderland (1865 novel)

### Author
Van Vite - Created using Visual Studio 2019 Community for a C++ assignment

### Links
[GitHub Repository]()

[MIT License](/LICENSE)

# Game Guide

### Commands
* **LOOK** - Displays the Room description and contents
* **CHECK** - Displays the Player size and inventory
* **GO** [direction] - Moves the Player to the target room
* **ASK** [NPC] - Displays game clues from an NPC
* **EXAMINE** [item/container] - Displays information about an Item or container
* **GET** [item] - Removes Item from the room/container and adds it to Player inventory
* **DROP** [item] - Removes Item from Player inventory and adds it to the room
* **USE** [item] - Player can drink potion or eat cake
* **PUT** [item] **IN** [container] - Removes Item from inventory/room and adds it to the container
* **QUIT GAME** - Exits the game

**[direction]**: NORTH, EAST, SOUTH, WEST

**[item]**: POTION, CAKE, GEARS

**[container]**: TOOLSHED, TREE, CLOCK

**[NPC]**: CAT, HATTER

### World Map
![World Map](/myZork_map.png)

### How To Win
1. GO EAST and then GET POTION
2. GO SOUTH and then GET GEARS
3. GO WEST and then GET CAKE
4. DRINK POTION and then GO NORTH
5. GO WEST and then EAT CAKE
6. EAT CAKE again
7. PUT GEARS IN CLOCK

# Developer Notes

### Unique Features
* NPC dialog - Located in certain rooms to assist the Player in figuring out what to do.
* Player status - Similar to the original story, Alice can be small, normal, or large in size.
* Item/Room that can only be accessed when the Player is the correct size - I thought this would be an interesting alternative to unlocking things with keys.

### Personal Challenges
I spent a lot of time on deciding how to approach the assignment because I am not used to text-based games. After re-reading the instructions and doing a bit of research into what made Zork a classic in the industry, I understood the objectives and chose to use a familiar story that would allow me to add some creative elements. Due to the deadline, my code is not as optimized as I would have liked it to be.
