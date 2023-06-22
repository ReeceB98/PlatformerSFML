#ifndef PLATFORMERSFML_SCORE_H
#define PLATFORMERSFML_SCORE_H
#include <SFML/Graphics.hpp>

class Score
{
 private:
  sf::Font font;
  sf::Text score_text;
  sf::Text score;
  int score_num = 0;
 public:
  Score();
  ~Score();
  bool initScore();
  void scoreString();
  void scoreUp();
  void setScore();
  void winScreen(int &game_state);
  void render(sf::RenderWindow &windy);
};

#endif // PLATFORMERSFML_SCORE_H
