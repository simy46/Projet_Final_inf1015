#pragma once
#include "boat.h"

class Game {
public:
    Game();

    void startGame();

    

private:

    void verifyCommand(const std::string& command);

    Boat boat_;

    std::unordered_map<std::string, Cabin> cabins_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> cabinlinks_;
    std::string currentCabin_;
};
