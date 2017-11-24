//Player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "Command.h"
#include "CommandQueue.h"

class Player {
 public:
  void handleEvent(const sf::Event& event, CommandQueue& commands);
  void handleRealtimeInput(CommandQueue& commands);
};

#endif
