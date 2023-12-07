#include <iostream>
#include <unordered_map>
#include "display.h"


// formatage string : https://patorjk.com/software/taag/#p=display&h=1&v=3&f=Cyberlarge&t=to%20the%20game // 
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
    std::cout << "-- " << room.getName() << " --" << std::endl;
    std::cout << room.getDescription() << std::endl;
    std::cout << std::endl;
}


void Display::showCommandPrompt() {
    std::cout << std::endl;
    std::cout << "$ ";
}

void Display::displayLinks(const std::unordered_map<std::string, std::string>& links, Boat& house) {
    for (const auto& direction : { "N", "S", "W", "E", "U"}) {
        auto it = links.find(direction);
        if (it != links.end()) {
            std::cout << house.getCabin(it->second).getName() << " is " << getDirectionName(direction) << " (" << direction << ")" << std::endl;
        }
    }
}

std::string Display::getDirectionName(const std::string& direction) {
    if (direction == "N") {
        return "to the North";
    }
    else if (direction == "S") {
        return "to the South";
    }
    else if (direction == "W") {
        return "to the West";
    }
    else if (direction == "E") {
        return "to the East";
    }
    else if (direction == "U") {
        return "Up";
    }
    else {
        return "Unknown";
    }
}
