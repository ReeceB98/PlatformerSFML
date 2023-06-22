#include "Lives.h"
#include <iostream>
Lives::Lives()
{

}
Lives::~Lives()
{

}

bool Lives::initLives()
{
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
  {
    std::cout << "Font did not load";
  }
  // Lives text.
  lives_text.setFont(font);
  lives_text.setString("Lives:");
  lives_text.setPosition(0, 20);
  lives_text.setFillColor(sf::Color::Yellow);
  lives_text.setCharacterSize(30);

  // Lives.
  life.setFont(font);
  life.setString(std::to_string(lives));
  life.setPosition(80, 22);
  life.setFillColor(sf::Color::Yellow);
  life.setCharacterSize(30);
  return true;
}

void Lives::lifeString()
{
  life.setString(std::to_string(lives));
}

void Lives::lifeDown()
{
  lives--;
}

void Lives::setLives()
{
  lives = 3;
}

void Lives::gameOver(int &game_state)
{
  if (lives == 0)
  {
    game_state = 2;
  }
}

void Lives::render(sf::RenderWindow &windy)
{
  windy.draw(lives_text);
  windy.draw(life);
}
