#include "display.h"
#include <iostream>

void Display::showBanner() {
    std::cout << "SAMYFRUIT && LEANADER1" << std::endl;
}

void Display::showGameState(const Room& room) {
    std::cout << "You are in " << room.getName() << "." << std::endl;
    std::cout << room.getDescription() << std::endl;
    showCommandPrompt();
}

void Display::showCommandPrompt() {
    std::cout << "$ ";
}
