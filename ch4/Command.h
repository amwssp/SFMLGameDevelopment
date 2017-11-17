#ifndef COMMAND_H
#define COMMAND_H

#include "SceneNode.h"

#include <SFML/System.hpp>

#include <functional>

class Command {
 public:
  Command();
  std::function<void(SceneNode&, sf::Time)> action;
  unsigned int category;
};

Command::Command() : action(), category(Category::None) {}


#endif