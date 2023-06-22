#include "Platform.h"
#include <iostream>
Platform::Platform()
{

}

Platform::~Platform()
{

}

bool Platform::platTexture()
{
  for (int i = 0; i < PLATFORM1; i++)
  {
    if (!plat_list_tex[i].loadFromFile("Data/Images/kenney_pixelplatformer/Tiles/tile_0002.png"))
    {
      std::cout << "Texture did not load.";
    }
  }
  return true;
}

void Platform::initPlat()
{
  for (int i = 0; i < PLATFORM1; i++)
  {
    plat_list[i].initializeSprite(plat_list_tex[i], "Data/Images/kenney_pixelplatformer/Tiles/tile_0151.png");
    plat_list[i].getSprite()->setPosition(plat_list[i].getSprite()->getGlobalBounds().width * i * 3, 670);
    plat_list[i].getSprite()->setScale(3.0f,3.0f);
  }
}

bool Platform::platTexture2()
{
  for (int i = 0; i < PLATFORM2; i++)
  {
    if (!plat_list_tex2[i].loadFromFile("Data/Images/kenney_pixelplatformer/Tiles/tile_0002.png"))
    {
      std::cout << "Texture did not load.";
    }
  }
  return true;
}

void Platform::initPlat2()
{
  for (int i = 0; i < PLATFORM2; i++)
  {
    plat_list2[i].initializeSprite(plat_list_tex2[i], "Data/Images/kenney_pixelplatformer/Tiles/tile_0151.png");
    plat_list2[i].getSprite()->setPosition(plat_list2[i].getSprite()->getGlobalBounds().width * i * 3 + 550, 450);
    plat_list2[i].getSprite()->setScale(3.0f,3.0f);
  }
}

bool Platform::platTexture3()
{
  for (int i = 0; i < PLATFORM3; i++)
  {
    if (!plat_list_tex3[i].loadFromFile("Data/Images/kenney_pixelplatformer/Tiles/tile_0002.png"))
    {
      std::cout << "Texture did not load.";
    }
  }
  return true;
}

void Platform::initPlat3()
{
  for (int i = 0; i < PLATFORM3; i++)
  {
    plat_list3[i].initializeSprite(plat_list_tex3[i], "Data/Images/kenney_pixelplatformer/Tiles/tile_0151.png");
    plat_list3[i].getSprite()->setPosition(plat_list3[i].getSprite()->getGlobalBounds().width * i * 3, 200);
    plat_list3[i].getSprite()->setScale(3.0f,3.0f);
  }
}

void Platform::platCollision(GameObject &girl, int &direction_y)
{
  for (int i = 0; i < PLATFORM1; i++)
  {
    if (plat_list[i].getSprite()->getGlobalBounds().intersects(
          girl.getSprite()->getGlobalBounds()))
    {
      direction_y = 0;
    }
  }
}

void Platform::platCollision2(GameObject &girl, int &direction_y)
{
  for (int i = 0; i < PLATFORM2; i++)
  {
    if (plat_list2[i].getSprite()->getGlobalBounds().intersects(
          girl.getSprite()->getGlobalBounds()))
    {
      direction_y = 0;
    }
  }
}

void Platform::platCollision3(GameObject &girl, int &direction_y)
{
  for (int i = 0; i < PLATFORM3; i++)
  {
    if (plat_list3[i].getSprite()->getGlobalBounds().intersects(
          girl.getSprite()->getGlobalBounds()))
    {
      direction_y = 0;
    }
  }
}

void Platform::render(sf::RenderWindow &windy)
{
  for (int i = 0; i < PLATFORM1; i++)
  {
    windy.draw(*plat_list[i].getSprite());
  }
}

void Platform::render2(sf::RenderWindow &windy)
{
  for (int i = 0; i < PLATFORM2; i++)
  {
    windy.draw(*plat_list2[i].getSprite());
  }
}

void Platform::render3(sf::RenderWindow &windy)
{
  for (int i = 0; i < PLATFORM3; i++)
  {
    windy.draw(*plat_list3[i].getSprite());
  }
}

