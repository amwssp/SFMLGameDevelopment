#include "Player.h"
#include "Aircraft.h"

#include <iostream>

struct AircraftMover {
  AircraftMover(float vx, float vy) : velocity(vx, vy) {}

  void operator() (Aircraft& aircraft, sf::Time dt) const {
    aircraft.accelerate(velocity);
  }

  sf::Vector2f velocity;
};

void Player::handleRealtimeInput(CommandQueue& commands) {
  const float playerSpeed = 30.f;

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    Command moveUp;
    moveUp.category = Category::PlayerAircraft;
    moveUp.action = derivedAction<Aircraft> (AircraftMover(0.f, -playerSpeed));
    commands.push(moveUp);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    Command moveDown;
    moveDown.category = Category::PlayerAircraft;
    moveDown.action = derivedAction<Aircraft> (AircraftMover(0.f, playerSpeed));
    commands.push(moveDown);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
    Command moveLeft;
    moveLeft.category = Category::PlayerAircraft;
    moveLeft.action = derivedAction<Aircraft> (AircraftMover(-playerSpeed, 0.f));
    commands.push(moveLeft);
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    Command moveRight;
    moveRight.category = Category::PlayerAircraft;
    moveRight.action = derivedAction<Aircraft> (AircraftMover(playerSpeed, 0.f));
    commands.push(moveRight);
  }

  
}

void Player::handleEvent(const sf::Event& event, CommandQueue& commands) {
  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P) {
    Command output;
    output.category = Category::PlayerAircraft;
    output.action = [] (SceneNode& s, sf::Time) {
      std::cout << s.getPosition().x << "," << s.getPosition().y << "\n";
    };
    commands.push(output);
  }
}
