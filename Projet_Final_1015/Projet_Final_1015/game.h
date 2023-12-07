#pragma once
#include "boat.h"

class Game {
public:
    Game();

    void startGame();

    

private:

    void verifyCommand(const std::string& command);

    Boat boat_;

    std::unordered_map<std::string, Room> rooms_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> roomLinks_;
    std::string currentRoom_;
};
