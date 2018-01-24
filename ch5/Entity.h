//Entity.h

#ifndef ENTITY_H
#define ENTITY_H

#include "SceneNode.h"

#include <SFML/Graphics.hpp>

class Entity : public SceneNode {
 public:
  void accelerate(sf::Vector2f velocity);
  void accelerate(float vx, float vy);
  void setVelocity(sf::Vector2f velocity);
  void setVelocity(float vx, float vy);
  sf::Vector2f getVelocity() const;

 private:
  virtual void updateCurrent(sf::Time dt);
  
 private:
  sf::Vector2f mVelocity;
};

#endif
