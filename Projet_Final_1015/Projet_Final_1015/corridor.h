#pragma once
#include <vector>
#include "room.h"

class Corridor {

private:

	std::vector<Room> room; // un corridor peut avoir max 4 piece lié à celui-ci (intersection) // index : [0 = N | 1 = E | 2 = S | 3 = O]

	

public:

	Corridor();

};