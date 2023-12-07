#pragma once
#include <unordered_map>
#include "room.h"

class Boat {

private:
	std::unordered_map<std::string, Room> rooms_;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> roomLinks_;


public:

	Boat();

	void createBoat();

	Room& getRoom(std::string currentRoom);

	std::unordered_map<std::string, std::string>& getRoomLinks(std::string currentRoom);


};