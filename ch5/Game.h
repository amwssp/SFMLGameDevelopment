//Game.h

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "World.h"

#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game : private sf::NonCopyable {
 public:
  Game();
  void run();

 private:
  void processInput();
  void update(sf::Time elapsedTime);
  void render();

 private:
  static const sf::Time TimePerFrame;

  sf::RenderWindow mWindow;
  World mWorld;
  Player mPlayer;
  
};

#endif
