#include <iostream>
#include "game.h"
#include "display.h"


Game::Game() : currentRoom_("entrance") {
    createHouse();
}


void Game::createHouse() {
    rooms_["entrance"] = Room("The Entrance", "Welcome my dear friend. Please take of your shoes so we can keep the house cleeeeeeaaaann !");
    rooms_["livingRoom"] = Room("The LivingRoom", "You can always sit, relax and watch the tv.");
    rooms_["kitchen"] = Room("The Kitchen", "There is a lot of food... Don't you dare take some !");
    rooms_["basement"] = Room("The Basement", "This is a good place to chill -- or a good place to hide..?");

    rooms_; // ajouter dautre piece
    rooms_;
    rooms_;

    // lien entrance //
    roomLinks_["entrance"]["N"] = "livingRoom";
    roomLinks_["entrance"]["E"] = "basement";

    // liens livingRoom //
    roomLinks_["livingRoom"]["S"] = "entrance";
    roomLinks_["livingRoom"]["W"] = "kitchen";
    //roomLinks_["livingRoom"][""] = "";

    // liens kitchen //
    roomLinks_["kitchen"]["E"] = "livingRoom";
    //roomLinks_["kitchen"][""] = "";
    //roomLinks_["kitchen"][""] = "";
    //roomLinks_["kitchen"][""] = "";


    // liens basement //
    roomLinks_["basement"]["W"] = "entrance";
    //roomLinks_["basement"][""] = "";
    //roomLinks_["basement"][""] = "";
}

std::string Game::getDirectionName(const std::string& direction) {
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

void Game::displayLinks(const std::unordered_map<std::string, std::string>& links) {
    for (const auto& direction : { "N", "S", "W", "E" }) {
        auto it = links.find(direction);
        if (it != links.end()) {
            std::cout << it->second << " is to the " << getDirectionName(direction) << " (" << direction << ")" << std::endl;
        }
    }
}


void Game::verifyUserCommand(const std::string& command) {
    if (command.size() == 1) {
        const auto& links = roomLinks_[currentRoom_];
        auto it = links.find(command);
        if (it != links.end()) {
            currentRoom_ = it->second;
        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << rooms_[currentRoom_].getDescription() << std::endl;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}

void Game::startGame() {
    Display::showBanner();

    while (true) {
        const Room& currentRoom = rooms_[currentRoom_];
        Display::showGameState(currentRoom);

        const auto& links = roomLinks_[currentRoom_];
        displayLinks(links);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyUserCommand(command);
    }
}

