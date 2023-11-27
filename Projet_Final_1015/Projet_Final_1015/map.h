#pragma once
#include <vector>
#include "room.h"
#include "corridor.h"

static const int DIMENSION = 3; // appartement est un 3x3 (x2 etage)
static const int CORRIDORS = 12;


class Map {

private:

	uint8_t presentRoom_;
	std::vector<Room> room_;
	std::vector<Corridor> corridor_;



public:
	Map();



};