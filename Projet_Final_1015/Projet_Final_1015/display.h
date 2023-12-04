#pragma once
#include "house.h"

class Display {
private:

    

public:
    static void showBanner();

    static void displayLinks(const std::unordered_map<std::string, std::string>& links¸, House& house);

    static void showGameState(const Room& room);

    static void showCommandPrompt();

    static std::string getDirectionName(const std::string& direction);
};

