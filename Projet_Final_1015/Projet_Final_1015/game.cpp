#include "game.h"
#include "display.h"
#include <iostream>

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
            // DESCRIPTION PIECE 
            std::cout << rooms_[currentRoom_].getDescription() << std::endl;
        }

        else {
            std::cout << "Commande non reconnue." << std::endl;
        }
    }
}
