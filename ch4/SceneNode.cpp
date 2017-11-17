//SceneNode.cpp

#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

#include "SceneNode.h"

SceneNode::SceneNode() : mParent(nullptr) {}

void SceneNode::attachChild(Ptr child) {
  child->mParent = this;
  mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) {
  auto found = std::find_if(mChildren.begin(), mChildren.end(),
			    [&] (Ptr& p) -> bool { return p.get() == &node; });

  assert (found != mChildren.end());
  Ptr result = std::move(*found);
  result->mParent = nullptr;
  mChildren.erase(found);
  return result;
}

void SceneNode::onCommand(const Command& command, sf::Time dt) {
  if (command.category & getCategory())
    command.action(*this, dt);

  for (const Ptr& child : mChildren)
    child->onCommand(command, dt);
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  states.transform *= getTransform();

  drawCurrent(target, states);

  for (const Ptr& child : mChildren)
    child->draw(target, states);
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const {
  //override in derived classes
}

sf::Vector2f SceneNode::getWorldPosition() const {
  return getWorldTransform() * sf::Vector2f();
}

sf::Transform SceneNode::getWorldTransform() const {
  sf::Transform transform = sf::Transform::Identity;

  for (const SceneNode* node = this; node != nullptr; node = node->mParent)
    transform = node->getTransform() * transform;

  return transform;
}

void SceneNode::update(sf::Time dt) {
  updateCurrent(dt);
  updateChildren(dt);
}

void SceneNode::updateCurrent(sf::Time dt) {}

void SceneNode::updateChildren(sf::Time dt) {
  for (Ptr& child :mChildren)
    child->update(dt);
}

unsigned int SceneNode::getCategory() const {
  return Category::Scene;
}
