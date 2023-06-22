#include "LoseScreen.h"
LoseScreen::LoseScreen()
{

}
LoseScreen::~LoseScreen()
{

}

bool LoseScreen::loseText()
{
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
  {
    std::cout << "Font did not load";
  }

  losing_text.setFont(font);
  losing_text.setString("You Lose");
  losing_text.setPosition(500, 550);
  losing_text.setFillColor(sf::Color::Yellow);
  losing_text.setCharacterSize(30);

  play_option.setFont(font);
  play_option.setString("Play");
  play_option.setPosition(500, 100);
  play_option.setFillColor(sf::Color::Yellow);
  play_option.setCharacterSize(30);

  quit_option.setFont(font);
  quit_option.setString("Quit");
  quit_option.setPosition(500, 200);
  quit_option.setFillColor(sf::Color::Yellow);
  quit_option.setCharacterSize(30);

  return true;
}

void LoseScreen::loseSelect(int& game_state)
{
  if (game_state == 2)
  {
    switch (lose_select)
    {
      case -1:
      {
        win_select = 0;
        break;
      }

      case 0:
      {
        play_option.setString(">Play<");
        quit_option.setString("Quit");
        break;
      }
      case 1:
      {
        play_option.setString("Play");
        quit_option.setString(">Quit<");
        break;
      }

      case 2:
      {
        menu_select = 0;
        break;
      }
    }
  }
}

void LoseScreen::render(sf::RenderWindow& windy)
{
  windy.draw(losing_text);
  windy.draw(play_option);
  windy.draw(quit_option);
}

void LoseScreen::keyPressed(sf::Event& event, int& game_state, sf::RenderWindow& window)
{
  if (event.key.code == sf::Keyboard::Up)
  {
    lose_select--;
  }

  if (event.key.code == sf::Keyboard::Down)
  {
    lose_select++;
  }

  if (event.key.code == sf::Keyboard::Enter)
  {
    if (lose_select == 0)
    {
      game_state = 0;
      menu_select = -1;
    }

    if (lose_select == 1)
    {
      window.close();
      menu_select = -1;
    }
  }
}
