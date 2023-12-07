#include "cabin.h"

Cabin::Cabin() : name_(""), description_("") {}

Cabin::Cabin(const std::string& name, const std::string& description) : name_(name), description_(description) {}

const std::string& Cabin::getName() const {
    return name_;
}

const std::string& Cabin::getDescription() const {
    return description_;
}
