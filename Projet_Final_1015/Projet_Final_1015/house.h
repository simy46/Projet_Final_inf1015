#pragma once
#include <unordered_map>
#include "room.h"

class House {

private:
	std::unordered_map<std::string, Room> rooms_;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> roomLinks_;


public:

	House();

	void createHouse();

	Room& getRoom(std::string currentRoom);

	std::unordered_map<std::string, std::string>& getRoomLinks(std::string currentRoom);


};