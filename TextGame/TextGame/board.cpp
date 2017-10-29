#include "stdafx.h"
#include "board.h"



board::board()
{
	room room00 = room("You reached a corner of the world map. Do not travel any futher.", 0, 0, "", true, false, true, false);
	room room01 = room("Proof that the programmer is lazy.", 1, 0, "", true, true, true, false);
	room room02 = room("There is just a grassy plain.", 0, 2, "key", false, true, true, false);
	room room03 = room("This place look sad. You feel lonely.", 0, 3, "battery", false, false, true, false);
	room room10 = room("You take in the vast expanse of the field and the sky. You think of how little you mean in the grand scheme of things.", 0, 1, "depression", true, false, true, true);
	room room11 = room("You are in a grassy field. You don't see anyone nearby.", 1, 1, "stone", true, true, true, true);
	room room12 = room("There is a door in front of you. It is locked. Try using a key if you have one.", 1, 2, "", false, true, true, true);
	room room13 = room("This is the end so far. The programmer who made this is very lazy. He might not finish it because he is so lazy. JK, he fixed that now. Go forth!", 1, 3, "", false, true, true, true);
	room room20 = room("You are getting bored of seeing just a the grassy field. You could say that this plain is quite plain.", 2, 0, "", true, false, false, true);
	room room21 = room("What is the meaning of life?", 2, 1, "doubt", true, true, false, true);
	room room22 = room("You wonder why you are here.", 2, 2, "", false, true, false, true);
	room room23 = room("There was a fire here recently. Everything is burned except for a metal object.", 2, 3, "", false, false, false, true);
	room room04 = room("Demons. You have to defeat the demons. But where are they?", 0, 4, "discouraged", true, false, true, false);
	room room14 = room("You need a ring to defeat the demons. Were can you find a ring?", 1, 4, "", true, false, true, true);
	room room24 = room("The teleporter behind you exploded.", 2, 4, "dispair", true, false, false, true);
	room room05 = room("Demons. You have to defeat the demons. But where are they?", 0, 5, "", true, true, true, false);
	room room06 = room("Demons. You have to defeat the demons. But where are they?", 0, 6, "", false, true, false, false);
	room room15 = room("Why are you doing this?", 1, 5, "", false, true, true, true);
	room room25 = room("Some many questions. Do you have the answers? I guess that is just another question. ", 2, 5, "", false, true, false, true);

	rms = { {room00, room01, room02, room03, room04, room05, room06}, {room10, room11, room12, room13, room14, room15}, {room20, room21, room22, room23, room24, room25} };


}



room& board::getRoom(int x, int y) {
	return rms[x][y];
}

string board::use(int x, int y, string item) {
	room& rmXY = getRoom(x, y);
	if (x == 1 && y == 2 && item == "key") {
		rmXY.north = true;
		rmXY.discription = "There is a door in front of you. It is unlocked. You can go through it.";
		return "You used the " + item + " on the door.";
	}
	else if (x == 2 && y == 3 && item == "battery") {
		rmXY.discription = "A teleporter is infront of you.";
		return "You used the " + item + "on the teleporter. The teleporter whirls into life. It is beeping and booping. Lights are flashing. You can now use the teleporter.";
	}
	else if (x == 2 && y == 4 && item == "ring") {
		return "You put on the stone ring. You feel nothing. The world is dark. Where are your demons. You must kill your demons.\nKill demons.\nKill Demon\nKILL DEMO\nKILL EM\nKILL ME\nlcmd";
	}

	return "You can't use that item here.";
}

string board::inspect(int x, int y, string object) {
	room& rmXY = getRoom(x, y);
	if (x == 2 && y == 3 && object == "metal object" && rmXY.discription == "There was a fire here recently. Everything is burned except for a metal object.") {
		rmXY.discription = "There was a fire here recently. Everything is burned except for this teleporter.";
		return "Upon further inspection you realize that this is a teleporter. It looks lifeless.";
	}
	return "What you want to inspect is not here.";
}

void board::change() {
	for (int i = 0; i < rms.size(); i++) {
		for (int j = 0; j < rms[i].size(); j++) {
			room& rmXY = getRoom(i, j);
			rmXY.discription = "The world is black.";
		}
	}
}