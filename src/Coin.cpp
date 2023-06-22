#include "Coin.h"
#include <iostream>

Coin::Coin()
{

}

void Coin::initCoin()
{
  for (int i = 0; i < COINS; i++)
  {
    coins_list[i].initializeSprite(coin_list_tex[i], "Data/Images/kenney_pixelplatformer/Tiles/tile_0151.png");
    coins_list[i].getSprite()->setScale(4.0f,4.0f);
  }
}
bool Coin::coinTexture()
{
  for (int i = 0; i < COINS; i++)
  {
    if (!coin_list_tex[i].loadFromFile("Data/Images/kenney_pixelplatformer/Tiles/tile_0151.png"))
    {
      std::cout << "Text did not load\n";
    }
  }
  return true;
}

void Coin::coinPos(float x, float y)
{
  for (int i = 0; i < COINS; i++)
  {
    coins_list[i].getSprite()->setPosition(x + coins_list[i].getSprite()->getGlobalBounds().width * i, y);
  }
}

void Coin::coinAudio()
{
  for (int i = 0; i < COINS; i++)
  {
    if (!coin_buffer.loadFromFile("Data/Sound/Coin.wav"))
    {
      std::cout << "Error";
    }
  }
  coin.setBuffer(coin_buffer);
}

void Coin::coinCollision(float dt, GameObject &girl, int &score_num, sf::Text &score, int &game_state, Score &score1)
{
  score1.scoreString();
  for (int i = 0; i < COINS; i++)
  {
    if (coins_list[i].visibility)
    {
      if (girl.getSprite()->getGlobalBounds().intersects(
            coins_list[i].getSprite()->getGlobalBounds()))
      {
        coins_list[i].visibility = false;
        score1.scoreUp();
        coin.play();
      }
    }
  }
  if (game_state == 0)
  {
    for (int i = 0; i < COINS; i++)
    {
      coins_list[i].visibility = true;
    }
  }
}
void Coin::render(sf::RenderWindow &windy)
{
  if (coins_list->visibility)
  {
    for (int i = 0; i < COINS; i++)
    {
      windy.draw(*coins_list[i].getSprite());
    }
  }
}

