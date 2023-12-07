#include <iostream>
#include "game.h"
#include "display.h"


Game::Game() : currentRoom_("entrance"), boat_(Boat()) {}

void Game::verifyCommand(const std::string& command) {
    if (command.size() == 1) {
        const auto& links = boat_.getRoomLinks(currentRoom_);
        auto it = links.find(command);
        if (it != links.end()) {
            currentRoom_ = it->second;
            std::cout << "Going " << Display::getDirectionName(command) << "..." << std::endl;

        }
        else {
            std::cout << "Cannot go there." << std::endl;
        }
    }
    else if (command == "look") {
        std::cout << boat_.getRoom(currentRoom_).getDescription() << std::endl;
    }
    else {
        std::cout << "Command not found." << std::endl;
    }
}

void Game::startGame() {
    Display::showBanner();

    while (true) {
        const Room& currentRoom = boat_.getRoom(currentRoom_);
        Display::showGameState(currentRoom);

        const auto& links = boat_.getRoomLinks(currentRoom_);
        Display::displayLinks(links, boat_);

        Display::showCommandPrompt();
        std::string command;
        std::cin >> command;

        verifyCommand(command);
    }
}
