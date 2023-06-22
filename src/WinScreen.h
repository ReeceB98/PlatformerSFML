#ifndef PLATFORMERSFML_WINSCREEN_H
#define PLATFORMERSFML_WINSCREEN_H
#include <SFML/Graphics.hpp>

class WinScreen
{
 private:
  sf::Text winning_text;
  sf::Font font;
  sf::Text play_option;
  sf::Text quit_option;
  int win_select = 0;
  int menu_select = 0;

 public:
  WinScreen();
  ~WinScreen();
  bool winText();
  void winSelect(int &game_state);
  void render(sf::RenderWindow &windy);
  void keyPressed(sf::Event& event, int &game_state, sf::RenderWindow& window);
};

#endif // PLATFORMERSFML_WINSCREEN_H
