#include "cabin.h"

Cabin::Cabin() : name_(""), description_("") {}

Cabin::Cabin(const std::string& name, const std::string& description) : name_(name), description_(description) {}

const std::string& Cabin::getName() const {
    return name_;
}

const std::string& Cabin::getDescription() const {
    return description_;
}

const std::vector<Object>& Cabin::getObjects() const {
    return objects_;
}

void Cabin::addObject(const Object& object) {
    objects_.push_back(object);
}

const Object* Cabin::findObject(const std::string& keyword) const {
    for (const auto& obj : objects_) {
        // Check if the keyword is present in the object's name or description
        if (obj.getName().find(keyword) != std::string::npos || obj.getDescription().find(keyword) != std::string::npos) {
            return &obj;
        }
    }
    return nullptr;
}