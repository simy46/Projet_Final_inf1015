#include "room.h"

Room::Room()
    : line_(0), column_(0), roomNumber_(-1) {}

Room::Room(int line, int column, int roomNumber)
    : line_(line), column_(column), roomNumber_(roomNumber){}


//#########################//
//######## GETTERS ########//
//#########################//
int Room::getLine() const { return line_; }
int Room::getColumn() const { return column_; }
int Room::getRoomNumber() const { return roomNumber_;  }

//#########################//
//######## SETTERS ########//
//#########################//
void Room::setLine(int l) { line_ = l; }
void Room::setColumn(int c) { column_ = c; }
void Room::setRoomNumber(int n) { roomNumber_ = n; }
