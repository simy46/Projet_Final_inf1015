#pragma once
#include "ship.h"

class Display {
private:

    

public:
    static void showBanner();

    static void displayCommand();

    static void displayLinks(const std::unordered_map<std::string, std::string>& links¸, Ship& ship);

    static void showGameState(const Cabin& room);

    static void showCommandPrompt();

    static std::string getDirectionName(const std::string& direction);
};

