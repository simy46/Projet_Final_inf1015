#include "house.h"


House::House() {
    createHouse();
};

void House::createHouse() {
    rooms_["entrance"] = Room("The Entrance", "Welcome my dear friend. Please take off your shoes so we can keep the house cleeeeeeaaaann !");
    rooms_["livingRoom"] = Room("The Living Room", "You can always sit, relax, and watch the TV.");
    rooms_["kitchen"] = Room("The Kitchen", "There is a lot of food... Don't you dare take some!");
    rooms_["basement"] = Room("The Basement", "This is a good place to chill -- or a good place to hide..?");
    rooms_["bedroom"] = Room("The Bedroom", "The coziest place in the house. Sweet dreams await you.");
    rooms_["bathroom"] = Room("The Bathroom", "A place for profound thoughts and questionable singing.");
    rooms_["gameRoom"] = Room("The Game Room", "Challenge accepted! Feel free to play games and unwind.");
    rooms_["library"] = Room("The Library", "Shhh... The books might be old, but they have great stories to tell.");

    // Lien "entrance"
    roomLinks_["entrance"]["N"] = "livingRoom";
    roomLinks_["entrance"]["E"] = "basement";

    // Lien "livingRoom"
    roomLinks_["livingRoom"]["S"] = "entrance";
    roomLinks_["livingRoom"]["W"] = "kitchen";
    roomLinks_["livingRoom"]["E"] = "gameRoom";

    // Lien "kitchen"
    roomLinks_["kitchen"]["E"] = "livingRoom";
    roomLinks_["kitchen"]["N"] = "library";  // Nouveau lien vers la bibliothèque

    // Lien "basement"
    roomLinks_["basement"]["W"] = "entrance";
    roomLinks_["basement"]["N"] = "bedroom";  // Nouveau lien vers la chambre

    // Lien "bedroom"
    roomLinks_["bedroom"]["S"] = "basement";

    // Lien "gameRoom"
    roomLinks_["gameRoom"]["W"] = "livingRoom";

    // Lien "library"
    roomLinks_["library"]["S"] = "kitchen";
}

Room& House::getRoom(std::string currentRoom) {
    return rooms_[currentRoom];
}

std::unordered_map<std::string, std::string>& House::getRoomLinks(std::string currentRoom) {
    return roomLinks_[currentRoom];
}