// TextGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include "character.h"
#include "room.h"
#include "board.h"
#include <algorithm>
#include "windows.h"

using namespace std;

character player;
board brd;
vector<string> cmd = {"help", "inventory", "look", "pick up", "use", "inspect", "teleport", "w", "a", "s", "d", "lcmd", "quit"};

string reader(string ans) {
	string reponse = "";
	if (ans == "help" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) {
		reponse = "This is a text based adventure game. You are an adventurer trying to create the best adventure ever. Some tips are to respond in lower case, use 'look' to reveal information about a scene, and use 'w, a, s, d' to move north, south, east, and west. Use 'inventory', to check to see what you got. Type 'quit' to exit. Use 'lcmd' out all commands. Good luck!";
	}
	else if (ans == "inventory" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) {
		reponse = player.showInv();
	} 
	else if (ans == "look" &&  find(cmd.begin(), cmd.end(), ans) != cmd.end()) {
		reponse = brd.getRoom(player.xpos, player.ypos).look();
	}
	else if (ans == ("pick up " + brd.getRoom(player.xpos, player.ypos).thing) && find(cmd.begin(), cmd.end(), ans.substr(0, 7)) != cmd.end()) {
		reponse = player.pickUp(brd.getRoom(player.xpos, player.ypos));
	}
	else if (ans == "w" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 0); }
	else if (ans == "s" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 1); }
	else if (ans == "a" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 2); }
	else if (ans == "d" && find(cmd.begin(), cmd.end(), ans) != cmd.end()) { reponse = player.move(brd.getRoom(player.xpos, player.ypos), 3); }
	else if (ans.substr(0, 3) == "use" && find(cmd.begin(), cmd.end(), ans.substr(0, 3)) != cmd.end()) {
		for (int i = 0; i < player.inventory.size(); i++) {
			if (ans.length() < 4) {  }
			else if (ans.substr(4, ans.length()) == player.inventory[i]) {
				reponse = brd.use(player.xpos, player.ypos, player.inventory[i]);
				if (reponse.substr(0, 5) == "You u") { player.inventory.erase(player.inventory.begin() + i); }
				else if (reponse.substr(0, 5) == "You p") { player.inventory = {}; cmd = { "KILL ME", "lcmd" }; }
				break;
			}
			reponse = "Sorry, you do not have a " + ans.substr(4, ans.length());
		}
	}
	else if (ans.substr(0, 7) == "inspect" && find(cmd.begin(), cmd.end(), ans.substr(0, 7)) != cmd.end()) {
		if (ans.length() > 9) {
			reponse = brd.inspect(player.xpos, player.ypos, ans.substr(8, ans.length()));
		}
	}
	else if (ans == "teleport" && brd.getRoom(player.xpos, player.ypos).look() == "A teleporter is infront of you." && find(cmd.begin(), cmd.end(), ans) != cmd.end()) {
		player.xpos = 2;
		player.ypos = 4;
		reponse = "You teleported!";
	}
	else if(ans == "lcmd"){
		for (int i = 0; i < cmd.size(); i++) {
			reponse += cmd[i] + "\n";
		}
	}
	else if (ans == "KILL ME" && cmd.size() == 2) {
		exit(EXIT_FAILURE);
	}
	else if (ans == "quit" && find(cmd.begin(), cmd.end(), ans) != cmd.end() ) {
		exit(0);
	}
	else {
		reponse = "Sorry, I don't understand.";
	}
	
	if (player.xpos == 0 && player.ypos == 6 && brd.getRoom(0, 6).discription != "The world is black.") {
		cout << "The sky darkens. You feel uneasy. You fall to your knees, exhusted. The world spins. The world is black. " << endl;
		cout.flush();
		Sleep(2000);
		system("CLS");
		for (int i = 0; i < 150; i++) {
			cout << "The world is black." << endl;
			Sleep(10);
		}
		player.inventory = {"DEPRESSION", "DOUBT", "DISPAIR", "DAMAGED", "DAMNED", "DELUSIONAL", "DEPRIVED", "DISCOURAGED", "STONE"};
		cmd = {"inventory", "look", "w", "a", "s", "d", "use",  "lcmd"};
		reponse = "ERROR 623: MISSING 'oscx.dll'\nREBOOTING...Hello warrior! There is not much time. Find the magic ring and defeat the demons!";
		brd.change();
	}
	if (player.xpos == 2 && player.ypos == 4 && brd.getRoom(2, 4).discription == "The world is black." && cmd.size() != 2 && player.inventory[8] == "STONE") {
		player.inventory = { "DEPRESSION", "DOUBT", "DISPAIR", "DAMAGED", "DAMNED", "DELUSIONAL", "DEPRIVED", "DISCOURAGED", "ring" };
		reponse = "The world shakes. inventory";
	}

	return reponse;
}
int main()
{
	string ans = "";
	string answer = "";
	cout << "Hello warrior! There is not much time. Find the magic ring and defeat the demons!" << endl;
	while (true) {
		getline(cin, ans);
		cout << reader(ans) << endl;
	}
    return 0;
}

