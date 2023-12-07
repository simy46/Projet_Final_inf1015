#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "display.h"


// formatage string : https://www.asciiart.eu/vehicles/boats// // 
void Display::showBanner() { // choisir format //
    std::cout << R"(

                    v ~.      v
          v           /|
                     / |          v
              v     /__|__
                  \--------/
~~~~~~~~~~~~~~~~~~~`~~~~~~'~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                The pirate ship                                  
)" << std::endl;
}

void Display::showGameState(const Cabin& room) {
    std::cout << std::endl;
    std::cout << "[-- " << room.getName() << " --]" << std::endl;
    std::cout << room.getDescription() << std::endl;
    std::cout << std::endl;
}


void Display::showCommandPrompt() {
    std::cout << std::endl;
    std::cout << "$ ";
}

void Display::displayLinks(const std::unordered_map<std::string, std::string>& links, Ship& ship) {
    for (const auto& direction : { "N", "S", "W", "E", "U", "D"}) {
        auto it = links.find(direction);
        if (it != links.end()) {
            if (it->first == "U" || it->first == "D") {
                std::cout << ship.getCabin(it->second).getName() << " is " << getDirectionName(direction) << " (" << direction << ")" << std::endl;
            }
            else {
                std::cout << ship.getCabin(it->second).getName() << " is to the " << getDirectionName(direction) << " (" << direction << ")" << std::endl;
            }
        }
    }
}

void Display::displayObjects(const Cabin& cabin) {
    const auto& objects = cabin.getObjects();
    if (!objects.empty()) {
        std::cout << "Objects in the room:" << std::endl;
        for (const auto& obj : objects) {
            std::cout << "- " << obj.getName() << ": " << obj.getDescription() << std::endl;
        }
    }
}


void Display::displayCommand() {
    const int boxWidth = 40;

    std::cout << std::setw(boxWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(boxWidth) << std::left << "These are the commands that you can use" << std::endl;

    std::cout << std::setw(boxWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    for (const auto& direction : { "N", "S", "W", "E", "U", "D" }) {
        std::cout << std::setw(boxWidth / 2) << direction << " : " << getDirectionName(direction) << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::setw(boxWidth / 2) << "C" << " : get command list" << std::endl;

    std::cout << std::setw(boxWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');
}


std::string Display::getDirectionName(const std::string& direction) {
    if (direction == "N") {
        return "North";
    }
    else if (direction == "S") {
        return "South";
    }
    else if (direction == "W") {
        return "West";
    }
    else if (direction == "E") {
        return "East";
    }
    else if (direction == "U") {
        return "Up";
    }
    else if (direction == "D") {
        return "Down";
    }
    else {
        return "Unknown";
    }
}
