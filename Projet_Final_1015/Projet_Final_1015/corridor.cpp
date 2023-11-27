#include "corridor.h"

Corridor::Corridor() {

}

Corridor::Corridor(Room* start, Room* end, Orientation o) : startRoom_(start), endRoom_(end), orientation_(o) {}

Room* Corridor::getStartRoom() const { return startRoom_; }
Room* Corridor::getEndRoom() const { return endRoom_; }
Orientation Corridor::getOrientation() const { return orientation_; }
