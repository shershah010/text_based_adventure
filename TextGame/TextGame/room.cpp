#include "stdafx.h"
#include "room.h"

#include "string.h"

using namespace std;


room::room(string dis, int xpos, int ypos, string item, bool n, bool s, bool e, bool w)
{
	disc = dis;
	discription = dis;
	if (item != "") {
		discription += " There is a " + item + " here.";
	}
	x = xpos;
	y = ypos;
	thing = item;
	north = n;
	south = s;
	east = e;
	west = w;
}

string room::look() {
	return discription;
}

string room::getThing() {
	string s = thing;
	thing = "";
	discription = disc;
	return s;
}

bool room::getNorth() {
	return north;
}

bool room::getSouth() {
	return south;
}

bool room::getEast() {
	return east;
}

bool room::getWest() {

	return west;
}