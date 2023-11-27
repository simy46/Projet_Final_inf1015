#pragma once
#include <string>

class Room {
public:

    Room();
    Room(const std::string& name, const std::string& description);

    const std::string& getName() const;
    const std::string& getDescription() const;

private:
    std::string name_;
    std::string description_;
};

