#pragma once
#include "boat.h"

class Display {
private:

    

public:
    static void showBanner();

    static void displayLinks(const std::unordered_map<std::string, std::string>& links¸, Boat& house);

    static void showGameState(const Cabin& room);

    static void showCommandPrompt();

    static std::string getDirectionName(const std::string& direction);
};

