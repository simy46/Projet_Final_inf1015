#include <iostream>
#include "game.h"
#include "display.h"


Game::Game() : currentCabin_("deck"), ship_(Ship()) {}

void Game::verifyCommand(const std::string& command) {
    const Cabin& currentCabin = ship_.getCabin(currentCabin_);
    const auto& links = ship_.getCabinLinks(currentCabin_);

    if (command.size() == 1) {
        auto it = links.find(command);
        if (it != links.end()) {
            currentCabin_ = it->second;
            std::cout << "Going " << Display::getDirectionName(command) << "..." << std::endl;
        }
        else if (command == "C") {
            Display::displayCommand();
        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << currentCabin.getName() << std::endl;
        std::cout << currentCabin.getDescription() << std::endl;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}

void Game::startGame() {
    Display::showBanner();
    Display::displayCommand();

    while (true) { // on va changer le while true pour un while (!exit) ou meme while (start) pour livrable 2 //
        Display::showGameState(ship_.getCabin(currentCabin_));

        const auto& links = ship_.getCabinLinks(currentCabin_);
        Display::displayLinks(links, ship_);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyCommand(command);
    }
}

void Game::interactWithObject(const Cabin& cabin, const std::string& objectKeyword) {
    const Object* foundObject = cabin.findObject(objectKeyword);
    if (foundObject) {
        std::cout << "You interact with " << foundObject->getName() << ": " << foundObject->getDescription() << std::endl;

        // Handle linking to other cabins based on your logic
        const auto& linkedObjects = ship_.getCabinLinks(cabin.getName());
        auto linkedObjectIt = linkedObjects.find(foundObject->getName());
        if (linkedObjectIt != linkedObjects.end()) {
            currentCabin_ = linkedObjectIt->second;
            std::cout << "You discover a new area: " << currentCabin_ << std::endl;
        }
    }
    else {
        std::cout << "Object not found." << std::endl;
    }
}
