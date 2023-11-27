#pragma once
#include <string>

class Room {
private:
    int line_;
    int column_;
    int floor_;
    std::string name_;
    std::string description_;

public:
    Room();
    Room(int l, int c, int e, int s, const std::string& name, const std::string& description);

    int getLine() const;
    int getColumn() const;
    int getFloor() const;
    const std::string& getName() const;
    const std::string& getDescription() const;

    void setLine(int l);
    void setColumn(int c);
    void setFloor(int f);
    void setName(const std::string& name);
    void setDescription(const std::string& description);
};
