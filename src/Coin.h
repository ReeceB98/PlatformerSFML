#ifndef PLATFORMERSFML_COIN_H
#define PLATFORMERSFML_COIN_H
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "GameObject.h"
#include "Score.h"

class Coin
{
 private:
  static const int COINS = 1;
  sf::Texture coin_list_tex [COINS];
  GameObject coins_list [COINS];
  sf::SoundBuffer coin_buffer;
  sf::Sound coin;

 public:
  Coin();
  bool coinTexture();
  void initCoin();
  void coinPos(float x, float y);
  void coinCollision(float dt, GameObject &girl, int &score_num, sf::Text &score, int &game_state, Score &score1);
  void render(sf::RenderWindow &windy);
  void coinAudio();
};

#endif // PLATFORMERSFML_COIN_H
