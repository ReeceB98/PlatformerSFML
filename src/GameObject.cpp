#include <SFML/Graphics.hpp>
#include "GameObject.h"

bool GameObject::initializeSprite(sf::Texture& texture, sf::String filename)
{
  sprite = new sf::Sprite(texture);
  return true;
}

sf::Sprite* GameObject::getSprite()
{
  return sprite;
}

int GameObject::getSpeed() const
{
  return speed;
}

void GameObject::setSpeed(int speed)
{
  GameObject::speed = speed;
}

const Vector2& GameObject::getDirection() const
{
  return direction;
}
void GameObject::setDirection(float x, float y)
{
  GameObject::direction.x = x;
  GameObject::direction.y = y;
}