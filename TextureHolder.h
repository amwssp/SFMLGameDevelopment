//TextureHolder.h

#ifndef TEXTUREHOLDER_H
#define TEXTUREHOLDER_H

#include <cassert>
#include <map>
#include <memory>
#include <stdexcept>
#include <SFML/Graphics.hpp>

#include "Textures.h"

template <typename Resource, typename Identifier>
class ResourceHolder {
 public:
  Resource& get(Identifier id);
  const Resource& get(Identifier id) const;
  void load(Identifier id, const std::string& filename);

 private:
  std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
};

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) {
  auto found = mResourceMap.find(id);
  assert(found != mResourceMap.end());
  return *found->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const {
  auto found = mResourceMap.find(id);
  assert(found != mResourceMap.end());
  return *found->second;
}


template <typename Resource, typename Identifier>
  void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename) {
  std::unique_ptr<Resource> resource(new Resource());
  if (!resource->loadFromFile(filename))
    throw std::runtime_error("ResourceHolder::load - Failed to load " + filename);
  auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
  assert(inserted.second);
}
#endif
