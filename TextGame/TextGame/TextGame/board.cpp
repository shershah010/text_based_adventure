#include "stdafx.h"
#include "board.h"



board::board()
{
	room room00 = room("You reached a corner of the world map. Do not travel any futher.", 0, 0, "", true, false, true, false);
	room room01 = room("Proof that the programmer is lazy.", 1, 0, "", true, true, true, false);
	room room02 = room("There is just a grassy plain.", 0, 2, "key", false, true, true, false);
	room room10 = room("You take in the vast expanse of the field and the sky. You think of how little you mean in the grand scheme of things. You become depressed.", 0, 1, "", true, false, true, true);
	room room11 = room("You are in a grassy field. You don't see anyone nearby.", 1, 1, "stone", true, true, true, true);
	room room12 = room("There is a door in front of you. It is locked. Try using a key if you have one.", 1, 2, "", false, true, true, true);
	room room13 = room("This is the end so far. The programmer who made this is very lazy. He might not finish it because he is so lazy.", 1, 3, "", false, true, false, false);
	room room20 = room("You are getting bored of seeing just a the grassy field. You could say that this plain is quite plain.", 2, 0, "", true, false, false, true);
	room room21 = room("What is the meaning of life?", 2, 1, "doubt", true, true, false, true);
	room room22 = room("You wonder why you are here.", 2, 2, "", false, true, false, true);

	rms = { {room00, room01, room02}, {room10, room11, room12, room13}, {room20, room21, room22} };


}



room& board::getRoom(int x, int y) {
	return rms[x][y];
}

string board::use(int x, int y, string item) {
	if (x == 1 && y == 2 && item == "key") {
		room& rm12 = getRoom(1, 2);
		rm12.north = true;
		rm12.discription = "There is a door in front of you. It is unlocked. You can go through it.";
		return "You used the " + item + " on the door.";
	}
	return "You can't use that item here.";
}