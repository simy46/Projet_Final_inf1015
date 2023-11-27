#include "room.h"


Room::Room() : line_(-1), column_(-1), floor_(-1), size_(-1) {}

Room::Room(int l, int c, int e, int s) : line_(l), column_(c), floor_(e), size_(s) {}

int Room::getLine() const {
	return line_;
}

int Room::getColumn() const {
	return column_;
}

int Room::getSize() const {
	return size_;
}

int Room::getFloor() const {
	return floor_;
}

void Room::setLine(int l) {
	line_ = l;
}

void Room::setColumn(int c) {
	column_ = c;
}

void Room::setSize(int s) {
	size_ = s;
}

void Room::setFloor(int f) {
	floor_ = f;
}