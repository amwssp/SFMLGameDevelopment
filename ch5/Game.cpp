#include "Game.h"

const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : mWindow(sf::VideoMode(640, 480), "World", sf::Style::Close), mWorld(mWindow) {}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (mWindow.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;
    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;

      processInput();
      
      //processEvents();
      update(TimePerFrame);
    }

    render();
  }
}

/*
void Game::processEvents() {
  sf::Event event;
  while (mWindow.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::Closed:
      mWindow.close();
      break;
    }
  }
}
*/

void Game::processInput() {
  CommandQueue& commands = mWorld.getCommandQueue();

  sf::Event event;
  while (mWindow.pollEvent(event)) {
    mPlayer.handleEvent(event, commands);

    if (event.type == sf::Event::Closed)
      mWindow.close();
  }

  mPlayer.handleRealtimeInput(commands);
}

void Game::update(sf::Time elapsedTime) {
  mWorld.update(elapsedTime);
}

void Game::render() {
  mWindow.clear();
  mWorld.draw();

  mWindow.setView(mWindow.getDefaultView());
  mWindow.display();
}
