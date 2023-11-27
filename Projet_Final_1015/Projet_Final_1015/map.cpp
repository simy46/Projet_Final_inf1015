#include "map.h"

Map::Map() : presentRoom_(0) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			Room room(i, j, presentRoom_++);
			room_.emplace_back(room);
		}
	}

	int carte[][3]{
		{1, 0, 1}, {1, 1, 2},					// entré -> cuisine1				cuisine1 -> cuisine2 
		{1, 0, 3}, {1, 1, 4}, {1, 2, 5},		// entré -> salon1					cuisine1 -> chambre principale			cuisine2 -> sortie jardin
		{1, 3, 4}, {1, 4, 5},					// salon1 -> chambre principale		chambre principale -> sortie jardin
		{1, 3, 6}, {1, 6, 7}, {1, 4, 7},		// salon1 -> salon2					salon2 -> toilette						chambre principale -> toilette
		{1, 7, 8}, {1, 5, 8}					// toilette -> escalier				sortie jardin -> escalier
	};

	for (int i = 0; i < CORRIDORS; i++) {
		int floor = carte[i][0];
		int startRoomNumber = carte[i][1];
		int endRoomNumber = carte[i][2];

		Room* startRoom = &room_[startRoomNumber];
		Room* endRoom = &room_[endRoomNumber];
		Orientation orientation = (startRoom->getColumn() == endRoom->getColumn()) ? Orientation::Y : Orientation::X;

		corridor_.emplace_back(floor, startRoom, endRoom, orientation); 
	}
}