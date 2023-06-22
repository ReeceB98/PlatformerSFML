#include "Score.h"
#include <iostream>
Score::Score()
{

}
Score::~Score()
{

}

bool Score::initScore()
{
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
  {
    std::cout << "Font did not load";
  }

  // Score text.
  score_text.setFont(font);
  score_text.setString("Score:");
  score_text.setPosition(800, 20);
  score_text.setFillColor(sf::Color::Yellow);
  score_text.setCharacterSize(30);

  // Score.
  score.setFont(font);
  score.setString(std::to_string(score_num));
  score.setPosition(890, 22);
  score.setFillColor(sf::Color::Yellow);
  score.setCharacterSize(30);

  return true;
}

void Score::scoreString()
{
  score.setString(std::to_string(score_num));
}

void Score::scoreUp()
{
  score_num++;
}

void Score::setScore()
{
  score_num = 0;
}

void Score::winScreen(int &game_state)
{
  if (score_num == 5)
  {
    game_state = 3;
  }
}

void Score::render(sf::RenderWindow& windy)
{
  windy.draw(score_text);
  windy.draw(score);
}
