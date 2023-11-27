#pragma once
#include <string>

class Room {
private:
    int line_;
    int column_;
    int roomNumber_;

public:
    Room();
    Room(int line, int column, int roomNumber);

    int getLine() const;
    int getColumn() const;
    int getRoomNumber() const;

    void setLine(int l);
    void setColumn(int c);
    void setRoomNumber(int n);
};
