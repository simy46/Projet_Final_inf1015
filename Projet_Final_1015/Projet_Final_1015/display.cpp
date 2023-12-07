#include <iostream>
#include <unordered_map>
#include "display.h"


// formatage string : https://patorjk.com/software/taag/#p=display&h=1&v=3&f=Cyberlarge&t=to%20the%20game // 
void Display::showBanner() { // choisir format //
    std::cout << R"(

               #   ___                            ___           |"|                   
    ()_()      #  <_*_>            ()_()         .|||.         _|_|_           __MMM__
    (o o)      #  (o o)            (o o)         (o o)         (o o)            (o o)  
ooO--`o'--Ooo--8---(_)--Ooo----ooO--`o'--Ooo-ooO--(_)--Ooo-ooO--(_)--Ooo----ooO--(_)--
                                                                                             
)" << std::endl;
}

void Display::showGameState(const Room& room) {
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
    for (const auto& direction : { "N", "S", "W", "E" }) {
        auto it = links.find(direction);
        if (it != links.end()) {
            std::cout << house.getRoom(it->second).getName() << " is to the " << getDirectionName(direction) << " (" << direction << ")" << std::endl;
        }
    }
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
    else {
        return "Unknown";
    }
}
