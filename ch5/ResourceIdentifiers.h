//ResourceIdentifiers.h

#ifndef RESOURCE_IDENTIFIERS_H
#define RESOURCE_IDENTIFIERS_H

#include "ResourceHolder.h"

namespace Textures {
  enum ID { Eagle, Raptor, Desert };
}

namespace Fonts {
  enum ID { Main, };
}

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;
typedef ResourceHolder<sf::Font, Fonts::ID> FontHolder;

#endif
