#include "room.h"

Room::Room() : name_(""), description_("") {}

Room::Room(const std::string& name, const std::string& description) : name_(name), description_(description) {}

const std::string& Room::getName() const {
    return name_;
}

const std::string& Room::getDescription() const {
    return description_;
}
