#ifndef PLATFORMERSFML_GAMEOBJECT_H
#define PLATFORMERSFML_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
 public:

  bool initializeSprite(sf::Texture &texture, sf::String filename);
  sf::Sprite* getSprite();
  int getSpeed() const;
  void setSpeed(int speed);
  const Vector2& getDirection() const;
  void setDirection(float x, float y);
  bool visibility = true;

 private:
  sf::Sprite* sprite = nullptr;
  int speed = 0;
  Vector2 direction {0,0};
};

#endif // PLATFORMERSFML_GAMEOBJECT_H
