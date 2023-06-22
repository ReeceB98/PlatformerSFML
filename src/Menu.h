#ifndef PLATFORMERSFML_MENU_H
#define PLATFORMERSFML_MENU_H
#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Menu
{
 private:
  sf::Font font;
  sf::Text menu_title;
  sf::Text play_option;
  sf::Text quit_option;
  sf::Text control_title;
  sf::Text left_text;
  sf::Text right_text;
  sf::Text space_text;
  int menu_select = 0;
 public:
  Menu();
  ~Menu();
  bool menuText();
  void menuSelect(int &game_state);
  void render(sf::RenderWindow &windy);
  void keyPressed(sf::Event& event, int &game_state, sf::RenderWindow& window);
};

#endif // PLATFORMERSFML_MENU_H
