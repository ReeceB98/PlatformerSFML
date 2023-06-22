#ifndef PLATFORMERSFML_LIVES_H
#define PLATFORMERSFML_LIVES_H
#include <SFML/Graphics.hpp>

class Lives
{
 private:
  sf::Font font;
  sf::Text lives_text;
  sf::Text life;
  int lives = 3;
 public:
  Lives();
  ~Lives();
  bool initLives();
  void lifeString();
  void lifeDown();
  void setLives();
  void gameOver(int &game_state);
  void render(sf::RenderWindow &windy);
};

#endif // PLATFORMERSFML_LIVES_H
