#include "Menu.h"
#include <iostream>

Menu::Menu()
{

}

Menu::~Menu()
{

}

bool Menu::menuText()
{
  // Loads a file to create a font for my text in menu.
  if (!font.loadFromFile("Data/Fonts/open-sans/OpenSans-Regular.ttf"))
  {
    std::cout << "Font did not load";
  }

  // These are my attributes for my menu title.
  menu_title.setFont(font);
  menu_title.setString("Platformer!");
  menu_title.setPosition(400, 10);
  menu_title.setFillColor(sf::Color::Yellow);
  menu_title.setCharacterSize(50);

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

  control_title.setFont(font);
  control_title.setString("Controls");
  control_title.setPosition(100, 400);
  control_title.setFillColor(sf::Color::Yellow);
  control_title.setCharacterSize(30);

  left_text.setFont(font);
  left_text.setString("Move Left = Left Arrow");
  left_text.setPosition(100, 450);
  left_text.setFillColor(sf::Color::Yellow);
  left_text.setCharacterSize(30);

  right_text.setFont(font);
  right_text.setString("Move Right = Right Arrow");
  right_text.setPosition(100, 500);
  right_text.setFillColor(sf::Color::Yellow);
  right_text.setCharacterSize(30);

  space_text.setFont(font);
  space_text.setString("Space = Jump");
  space_text.setPosition(100, 550);
  space_text.setFillColor(sf::Color::Yellow);
  space_text.setCharacterSize(30);

  return true;
}

void Menu::menuSelect(int &game_state)
{
  if (game_state == 0)
  {
    switch (menu_select)
    {
      case -1:
      {
        menu_select = 0;
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

void Menu::render(sf::RenderWindow& windy)
{
  windy.draw(menu_title);
  windy.draw(play_option);
  windy.draw(quit_option);
  windy.draw(control_title);
  windy.draw(left_text);
  windy.draw(right_text);
  windy.draw(space_text);
}

void Menu::keyPressed(sf::Event& event, int &game_state, sf::RenderWindow& window)
{
  if (game_state == 0)
  {
    if (event.key.code == sf::Keyboard::Up)
    {
      menu_select--;
    }

    if (event.key.code == sf::Keyboard::Down)
    {
      menu_select++;
    }

    if (event.key.code == sf::Keyboard::Enter)
    {
      if (menu_select == 0)
      {
        game_state = 1;
        menu_select = -1;
      }

      if (menu_select == 1)
      {
        window.close();
        menu_select = -1;
      }
    }
  }
}