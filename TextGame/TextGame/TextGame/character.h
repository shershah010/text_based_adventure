#pragma once
#include "room.h"
#include <vector>

using namespace std;

class character
{
public:
	vector<string> inventory;
	int xpos;
	int ypos;

	character();
	
	string showInv();

	string pickUp(room& rm);

	string move(room rm, int direction);
		
};

