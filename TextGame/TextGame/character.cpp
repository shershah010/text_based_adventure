#include "stdafx.h"
#include "character.h"


character::character()
{
	xpos = 1;
	ypos = 1;
}


string character::showInv() {
	string inv = "You have a ";
	if (inventory.size() == 0) {
		return "You have nothing.";
	}
	for (int i = 0; i < inventory.size(); ++i) {
		
		inv += inventory[i] + ", ";
	}
		return inv + "\b\b \b.";
}

string character::pickUp(room& rm) {
	inventory.push_back(rm.thing);
	return "you picked up " + rm.getThing() + ".";
}


string character::move(room rm, int direction) {
	if (direction == 0 && rm.getNorth()) {
		ypos++;
	}
	else if (direction == 1 && rm.getSouth()) {
		ypos--;
	}
	else if (direction == 2 && rm.getEast()) {
		xpos++;
	}
	else if (direction == 3 && rm.getWest()) {
		xpos--;
	}
	else {
		return "You can't go that way.";
	}
	return "You changed rooms!";
}