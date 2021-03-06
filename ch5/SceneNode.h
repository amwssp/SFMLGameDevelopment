//SceneNode.h

#ifndef SCENENODE_H
#define SCENENODE_H


#include "Command.h"

#include <memory>

#include <SFML/Graphics.hpp>

#include "Type.h"

struct Command;  //forward declaration

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
 public:
  typedef std::unique_ptr<SceneNode> Ptr;

 public:
  SceneNode();
  void attachChild(Ptr child);
  Ptr detachChild(const SceneNode& node);
  void update(sf::Time dt);

  sf::Vector2f getWorldPosition() const;
  sf::Transform getWorldTransform() const;

  void onCommand(const Command& command, sf::Time dt);
  
 private:
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
  virtual void updateCurrent(sf::Time dt);
  void updateChildren(sf::Time dt);

  virtual unsigned int getCategory() const;
  
 private:
  std::vector<Ptr> mChildren;
  SceneNode *mParent;
};

#endif
