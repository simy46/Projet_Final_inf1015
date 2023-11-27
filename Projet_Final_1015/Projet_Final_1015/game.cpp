#include "game.h"
#include "display.h"
#include <iostream>

Game::Game() : currentRoom_("entrance") {
    rooms_["entrance"] = Room("The Entrance", "Welcome my dear friend.");
    rooms_["livingRoom"] = Room("The LivingRoom", "You can always sit, relax and watch the tv.");
    rooms_["kitchen"] = Room("The Kitchen", "There is a lot of food... Don't you dare take some !");

    rooms_; // ajouter dautre piece
    rooms_;
    rooms_;


    // Initialisation des liens entre les pièces
    roomLinks_["entrance"]["N"] = "livingRoom";
    // ... Définissez d'autres liens entre les pièces
}

void Game::startGame() {
    Display::showBanner();

    while (true) {
        const Room& currentRoom = rooms_[currentRoom_];
        Display::showGameState(currentRoom);

        std::string command;
        std::cin >> command;

        if (command.size() == 1) {
            const auto& links = roomLinks_[currentRoom_];
            auto it = links.find(command);
            if (it != links.end()) {
                currentRoom_ = it->second;
            }
            else {
                std::cout << "Direction non valide." << std::endl;
            }
        }

        else if (command == "look") {
            // Logique pour afficher la description de la pièce
            // ...
        }

        else {
            std::cout << "Commande non reconnue." << std::endl;
        }
    }
}
