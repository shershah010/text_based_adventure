#pragma once

#include "string.h"
#include <iostream>

using namespace std;

class room
{
public:
	
	string discription;
	string thing;
	string disc;
	int x;
	int y;
	bool north;
	bool south;
	bool east;
	bool west;
	
	room(string dis, int xpos, int ypos, string item, bool n, bool s, bool e, bool w);

	string look();

	string getThing();

	bool getNorth();
	bool getSouth();
	bool getEast();
	bool getWest();
	
};

