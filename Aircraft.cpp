#include "Aircraft.h"

Textures::ID toTextureID(Aircraft::Type type) {
  switch (type) {
  case Aircraft::Eagle:
    return Textures::Eagle;
  case Aircraft::Raptor:
    return Textures::Raptor;
  }
}

Aircraft::Aircraft (Type type) : mType(type) {}

void Aircraft::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(mSprite, states);
}
