//ResourceIdentifiers.h

#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

#include "ResourceHolder.h"

namespace Textures {
  enum ID { Eagle, Raptor };
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

#endif
