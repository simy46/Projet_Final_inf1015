#include "corridor.h"

Corridor::Corridor() : floor_(-1), startRoom_(nullptr), endRoom_(nullptr), orientation_(Orientation::Y) {}
Corridor::Corridor(int floor, Room* start, Room* end, Orientation o) : floor_(floor), startRoom_(start), endRoom_(end), orientation_(o) {}

int Corridor::getFloor() const { return floor_; }
Room* Corridor::getStartRoom() const { return startRoom_; }
Room* Corridor::getEndRoom() const { return endRoom_; }
Orientation Corridor::getOrientation() const { return orientation_; }
