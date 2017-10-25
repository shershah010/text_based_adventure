// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "character.h"
#include "room.h"
#include "board.h"

using namespace std;

character player;
board brd;

string reader(string ans) {
	string reponse = "";
	if (ans == "help") {
		reponse = "This is a text based adventure game. You are an adventurerer tying to create the best adventure ever. Some tips are to respond in lower case, use 'look' to reveal information about a sceen, and use 'n, s, e, w' to move north, south, east, and west. Use 'inventory', to check to see what you got. Type 'quit' to exit. Good luck!";
	}
	else if (ans == "inventory") {
		reponse = player.showInv();
	} 
	else if (ans == "look") {
		reponse = brd.getRoom(player.xpos, player.ypos).look();
	}
	else if (ans == ("pick up " + brd.getRoom(player.xpos, player.ypos).thing)) {
		reponse = player.pickUp(brd.getRoom(player.xpos, player.ypos));
	}
	else if (ans == "n") { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 0); }
	else if (ans == "s") { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 1); }
	else if (ans == "e") { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 2); }
	else if (ans == "w") { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 3); }
	else if (ans.substr(0, 3) == "use") {
		for (int i = 0; i < player.inventory.size(); i++) {
			if (ans.substr(4, ans.length()) == player.inventory[i]) {
				reponse = brd.use(player.xpos, player.ypos, player.inventory[i]);
				if (reponse.substr(0, 5) == "You u") { player.inventory.erase(player.inventory.begin() + i); }
				break;
			}
			reponse = "Sorry, you do not have a " + ans.substr(4, ans.length());
		}
	}
	else {
		reponse = "Sorry, I don't understand.";
	}
	return reponse;
}
int main()
{
	string ans = "";
	string answer = "";
	cout << "Hello warrior! There is not much time. Find the magic ring and defeat the demon!" << endl;
	while (ans != "quit") {
		getline(cin, ans);
		cout << reader(ans) << endl;
	}
    return 0;
}

