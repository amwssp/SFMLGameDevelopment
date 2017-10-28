//Game.hpp

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

class Game {
public:
  Game();
  void run();

private:
  void processEvents();
  void update(sf::Time);
  void render();
  void handlePlayerInput(sf::Keyboard::Key, bool);
  
private:
  const float PlayerSpeed = 100.f;
  const sf::Time TimePerFrame = sf::seconds(1.f / 30.f);

  
  sf::RenderWindow mWindow;
  sf::Texture mTexture;
  sf::Sprite mPlayer;
  
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};

#endif
