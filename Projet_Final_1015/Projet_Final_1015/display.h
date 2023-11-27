#pragma once
#include "room.h"

class Display {
public:
    static void showBanner();

    static void showGameState(const Room& room);

    static void showCommandPrompt();
};

