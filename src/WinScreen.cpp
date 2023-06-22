#include "WinScreen.h"
#include <iostream>

WinScreen::WinScreen()
{

}

WinScreen::~WinScreen()
{

}

bool WinScreen::winText()
{
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
  {
    std::cout << "Font did not load";
  }
  winning_text.setFont(font);
  winning_text.setString("You Win!");
  winning_text.setPosition(500, 550);
  winning_text.setFillColor(sf::Color::Yellow);
  winning_text.setCharacterSize(30);

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

void WinScreen::winSelect(int& game_state)
{
  if (game_state == 3)
  {
    switch(win_select)
    {
      case -1:
      {
        win_select = -1;
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
        win_select = 0;
        break;
      }

    }
  }
}

void WinScreen::render(sf::RenderWindow& windy)
{
  windy.draw(winning_text);
  windy.draw(play_option);
  windy.draw(quit_option);
}

void WinScreen::keyPressed(sf::Event& event, int& game_state, sf::RenderWindow& window)
{
  if (game_state == 3)
  {
    if (event.key.code == sf::Keyboard::Up)
    {
      win_select--;
    }

    if (event.key.code == sf::Keyboard::Down)
    {
      win_select++;
    }

    if (event.key.code == sf::Keyboard::Enter)
    {
      if (win_select == 0)
      {
        game_state = 0;
        menu_select = -1;
      }

      if (win_select == 1)
      {
        window.close();
        menu_select = -1;
      }
    }
  }
}