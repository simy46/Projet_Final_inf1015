#pragma once
#include "Room.h"

enum class Orientation { X, Y };

class Corridor {
private:
    Room* startRoom_;
    Room* endRoom_;
    Orientation orientation_;

public:

    Corridor();
    Corridor(Room* start, Room* end, Orientation o);

    Room* getStartRoom() const;
    Room* getEndRoom() const;
    Orientation getOrientation() const;
};
