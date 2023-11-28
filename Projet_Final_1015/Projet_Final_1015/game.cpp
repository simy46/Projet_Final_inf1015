#include <iostream>
#include "game.h"
#include "display.h"


Game::Game() : currentRoom_("entrance") {
    house_;
}

void Game::verifyCommand(const std::string& command) {
    if (command.size() == 1) {
        const auto& links = house_.getRoomLinks(currentRoom_);
        auto it = links.find(command);
        if (it != links.end()) {
            currentRoom_ = it->second;
        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << house_.getRoom(currentRoom_).getDescription() << std::endl;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}

void Game::startGame() {
    Display::showBanner();

    while (true) {
        const Room& currentRoom = house_.getRoom(currentRoom_);
        Display::showGameState(currentRoom);

        const auto& links = house_.getRoomLinks(currentRoom_);
        Display::displayLinks(links);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyCommand(command);
    }
}
