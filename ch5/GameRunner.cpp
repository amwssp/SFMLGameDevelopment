//GameRunner.cpp

#include "Game.h"

#include <exception>
#include <iostream>

int main() {
  try {
    Game game;
    game.run();
  }
  catch (std::exception e) {
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
  }
}
