#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Coin.h"
#include "Menu.h"
#include "Platform.h"
#include "WinScreen.h"
#include "LoseScreen.h"
#include "Lives.h"
#include "Score.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void playerCollision();
  void enemyCollision();

 private:
  sf::RenderWindow& window;

  // Helps to change between different screens in my game.
  int game_state = 0;

  // All Texts set in my game.
  sf::Font font;


  // Player sprite.
  sf::Texture girl_texture;
  GameObject girl;
  sf::IntRect girl_texture_rectangle;

  // Background.
  sf::Texture background_texture;
  GameObject background;

  // Player movement.
  int direction_x = 0;
  int direction_y = 0;

  // Animations.
  sf::Clock animation_clock;
  sf::Clock enemy_clock;

  // Enemy.
  GameObject enemy;
  sf::Texture enemy_texture;
  sf::IntRect enemy_texture_rectangle;

    // Score Values.
  sf::Text score;
  int score_num = 0;

  // Audio&SFX.
  sf::SoundBuffer jump_buffer;
  sf::Sound jump;
  sf::SoundBuffer hit_buffer;
  sf::Sound hit;
  sf::Music music;

  Coin coin_list[5];

  sf::Texture plat_edge;
  GameObject edge;

  Menu menu;

  Platform platform1 [30];
  Platform platform2 [10];
  Platform platform3 [10];

  WinScreen winning;
  LoseScreen losing;

  Lives lives1;

  Score score1;

};

#endif // PLATFORMER_GAME_H
