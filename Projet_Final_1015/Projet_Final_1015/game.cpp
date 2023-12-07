#include <iostream>
#include "game.h"
#include "display.h"


Game::Game() : currentCabin_("deck"), ship_(Ship()) {}

void Game::verifyCommand(const std::string& command) {
    if (command.size() == 1) {
        const auto& links = ship_.getCabinLinks(currentCabin_);
        auto it = links.find(command);
        if (it != links.end()) {
            currentCabin_ = it->second;
            std::cout << "Going " << Display::getDirectionName(command) << "..." << std::endl;

        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << ship_.getCabin(currentCabin_).getDescription() << std::endl;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}

void Game::startGame() {
    Display::showBanner();

    while (true) {
        const Cabin& currentCabin = ship_.getCabin(currentCabin_);
        Display::showGameState(currentCabin);

        const auto& links = ship_.getCabinLinks(currentCabin_);
        Display::displayLinks(links, ship_);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyCommand(command);
    }
}
