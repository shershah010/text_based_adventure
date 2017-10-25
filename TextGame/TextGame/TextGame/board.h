#pragma once

#include "room.h"
#include <vector>
#include "string"

class board
{
public:

	vector<vector<room>> rms;
	board();

	room& getRoom(int x, int y);

	
	string use(int x, int y, string item);
};

