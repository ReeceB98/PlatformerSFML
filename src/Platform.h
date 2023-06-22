#ifndef PLATFORMERSFML_PLATFORM_H
#define PLATFORMERSFML_PLATFORM_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Platform
{
 private:
  static const int PLATFORM1 = 30;
  sf::Texture plat_list_tex [PLATFORM1];
  GameObject plat_list [PLATFORM1];
  static const int PLATFORM2 = 10;
  sf::Texture plat_list_tex2 [PLATFORM2];
  GameObject plat_list2 [PLATFORM2];
  static const int PLATFORM3 = 10;
  sf::Texture plat_list_tex3 [PLATFORM3];
  GameObject plat_list3 [PLATFORM3];
 public:
  Platform();
  ~Platform();
  bool platTexture();
  void initPlat();
  bool platTexture2();
  void initPlat2();
  bool platTexture3();
  void initPlat3();
  void platCollision(GameObject &girl, int &direction_y);
  void platCollision2(GameObject &girl, int &direction_y);
  void platCollision3(GameObject &girl, int &direction_y);
  void render(sf::RenderWindow &windy);
  void render2(sf::RenderWindow &windy);
  void render3(sf::RenderWindow &windy);
};

#endif // PLATFORMERSFML_PLATFORM_H
