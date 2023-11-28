#pragma once
#include <unordered_map>
#include "room.h"

class Game {
public:
    Game();

    void startGame();

    

private:
    void createHouse();
    void displayLinks(const std::unordered_map<std::string, std::string>& roomLinks);
    void verifyUserCommand(const std::string& command);
    std::string getDirectionName(const std::string& direction);

    std::unordered_map<std::string, Room> rooms_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> roomLinks_;
    std::string currentRoom_;
};
