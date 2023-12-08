#include <iostream>
#include <iomanip>
#include <unordered_map>
#include "Display.h"


// formatage string : https://www.asciiart.eu/vehicles/boats// // 
void Display::showBanner() { // choisir format //
    std::cout << "-- INF1015 -- dev: samyfruit, leanader1" << std::endl;
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

void Display::showGameState(const Cabin& cabin) {
    std::cout << std::endl;
    std::cout << "[-- " << cabin.getName() << " --]" << std::endl;
    std::cout << cabin.getDescription() << std::endl;
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
        std::cout << std::endl;
        std::cout << "Objects in the room" << std::endl;
        for (const auto& o : objects) {
            std::cout << "-> " << o.getName() << " : " << o.getDescription() << std::endl;
        }
    }
}


void Display::displayCommand() {
    const int boxWidth = 43;

    std::cout << std::setw(boxWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    std::cout << std::setw(boxWidth) << std::left << "| These are the commands that you can use |" << std::endl;

    std::cout << std::setw(boxWidth) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    for (const auto& direction : { "N", "S", "W", "E", "U", "D" }) {
        std::cout << std::setw(boxWidth / 3) << "| " << direction << " : " << getDirectionName(direction) << std::endl;
    }
    std::cout << std::setw(boxWidth / 3) << "| " << "C" << " : get command list" << std::endl;

    std::cout << std::setw(boxWidth / 3) << "| " << "use" << " : interact with objets" << std::endl;

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
