#pragma once
#include <unordered_map>
#include "cabin.h"

class Ship {

private:
	std::unordered_map<std::string, Cabin> cabins_;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> cabinLinks_;


public:

	Ship();

	void createShip();
	Cabin& getCabin(std::string currentCabin);

	std::unordered_map<std::string, std::string>& getCabinLinks(std::string currentCabin);


};