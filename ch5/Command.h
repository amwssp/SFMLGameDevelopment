#ifndef COMMAND_H
#define COMMAND_H

#include "SceneNode.h"
#include "Type.h"

#include <SFML/System.hpp>

#include <cassert>
#include <functional>

class SceneNode;

template <typename GameObject, typename Function>
std::function<void(SceneNode&, sf::Time)> derivedAction(Function fn) {
  return [=] (SceneNode& node, sf::Time dt) {
    //Check if cast is safe
    assert (dynamic_cast<GameObject*>(&node) != nullptr);
    
    //Downcast node and invoke function on it
    fn(static_cast<GameObject&>(node), dt);
  };
}

struct Command {
 public:
  Command();
  std::function<void(SceneNode&, sf::Time)> action;
  unsigned int category;
};

#endif
