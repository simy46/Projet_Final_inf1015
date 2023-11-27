#pragma once
#include "Room.h"

enum class Orientation { X, Y };

class Corridor {
private:

    int floor_;
    Room* startRoom_;
    Room* endRoom_;
    Orientation orientation_;

public:

    Corridor();
    Corridor(int floor, Room* start, Room* end, Orientation o);

    int getFloor() const;
    Room* getStartRoom() const;
    Room* getEndRoom() const;
    Orientation getOrientation() const;
};
