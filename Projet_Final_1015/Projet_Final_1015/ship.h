#pragma once
#include <unordered_map>
#include "cabin.h"

class Ship {

private:
	std::unordered_map<std::string, Cabin> cabins_;
	std::unordered_map<std::string, std::unordered_map<std::string, std::string>> cabinLinks_;
	std::unordered_map<std::string, std::vector<Object>> cabinObjects_;

public:

	Ship();

	void createShip();
	Cabin& getCabin(std::string currentCabin);

	std::unordered_map<std::string, std::string>& getCabinLinks(std::string currentCabin);
	void addObjectToCabin(const std::string& cabinName, const Object& object);
	void createObjects();



};