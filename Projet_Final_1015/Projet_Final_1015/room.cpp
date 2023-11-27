#include "room.h"

Room::Room()
    : line_(0), column_(0), floor_(0), name_(""), description_("") {}

Room::Room(int l, int c, int e, int s, const std::string& name, const std::string& description)
    : line_(l), column_(c), floor_(e), name_(name), description_(description) {}


//#########################//
//######## GETTERS ########//
//#########################//
int Room::getLine() const { return line_; }
int Room::getColumn() const { return column_; }
int Room::getFloor() const { return floor_; }
const std::string& Room::getName() const { return name_; }
const std::string& Room::getDescription() const { return description_; }

//#########################//
//######## SETTERS ########//
//#########################//
void Room::setLine(int l) { line_ = l; }
void Room::setColumn(int c) { column_ = c; }
void Room::setFloor(int f) { floor_ = f; }
void Room::setName(const std::string& name) { name_ = name; }
void Room::setDescription(const std::string& description) { description_ = description; }
