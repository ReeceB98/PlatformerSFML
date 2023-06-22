#ifndef PLATFORMERSFML_LOSESCREEN_H
#define PLATFORMERSFML_LOSESCREEN_H
#include <SFML/Graphics.hpp>
#include <iostream>

class LoseScreen
{
 private:
  sf::Font font;
  sf::Text losing_text;
  sf::Text play_option;
  sf::Text quit_option;
  int lose_select = 0;
  int win_select = 0;
  int menu_select = 0;

 public:
  LoseScreen();
  ~LoseScreen();
  bool loseText();
  void loseSelect(int &game_state);
  void render(sf::RenderWindow &windy);
  void keyPressed(sf::Event& event, int &game_state, sf::RenderWindow& window);
};

#endif // PLATFORMERSFML_LOSESCREEN_H
