//World.h

#ifndef WORLD_H
#define WORLD_H

#include "Aircraft.h"
#include "ResourceHolder.h"
#include "ResourceIdentifiers.h"
#include "SceneNode.h"

#include <SFML/Graphics.hpp>
#include <array>

class World : private sf::NonCopyable {
 public:
  explicit World(sf::RenderWindow& window);
  void update(sf::Time dt);
  void draw();

 private:
  enum Layer { Background, Air, LayerCount };

 private:
  sf::RenderWindow& mWindow;
  sf::View mWorldView;
  TextureHolder mTextures;
  SceneNode mSceneGraph;
  std::array<SceneNode*, LayerCount> mSceneLayers;

  sf::FloatRect mWorldBounds;
  sf::Vector2f mSpawnPosition;
  float mScrollSpeed;
  Aircraft* mPlayerAircraft;
};
  
#endif
