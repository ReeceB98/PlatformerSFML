
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  for(int i = 0; i < 5; i++)
  {
    coin_list[i].coinTexture();
    coin_list[i].initCoin();
    coin_list[i].coinAudio();
  }

  for(int i = 0; i < 30; i++)
  {
   platform1[i].platTexture();
   platform1[i].initPlat();
  }

  for(int i = 0; i < 10; i++)
  {
    platform2[i].platTexture2();
    platform2[i].initPlat2();
  }

  for(int i = 0; i < 10; i++)
  {
    platform3[i].platTexture3();
    platform3[i].initPlat3();
  }

  coin_list[0].coinPos(200,125);
  coin_list[1].coinPos(250,125);
  coin_list[2].coinPos(300,125);
  coin_list[3].coinPos(350,125);
  coin_list[4].coinPos(400,125);

  menu.menuText();

  lives1.initLives();

  losing.loseText();

  winning.winText();

  score1.initScore();

  // Player.
  // This will load a texture in a file to attach to my girl texture.

  //player.playerTexture();
  if (!girl_texture.loadFromFile("Data/Images/kenney_tooncharacters1/Female adventurer/Tilesheet/character_femaleAdventurer_sheet.png"))
  {
    std::cout << "Texture did not load.";
  }
  //player.initPlayer();
  girl.initializeSprite(girl_texture, "Data/Images/kenney_tooncharacters1/Female adventurer/Tilesheet/character_femaleAdventurer_sheet.png");
  girl.getSprite() ->setPosition(100, 540);
  girl.getSprite()->setScale(1, 1);
  girl_texture_rectangle = sf::IntRect(0,girl_texture.getSize().y / 5 * 4,girl_texture.getSize().x/9,girl_texture.getSize().y / 5);
  girl.getSprite()->setTextureRect(girl_texture_rectangle);

  // Background.
  if (!background_texture.loadFromFile("Data/Images/lvl1.png"))
  {
    std::cout << "background did not load \n";
  }
  background.initializeSprite(background_texture,"Data/Images/lvl1.png");

  if(!plat_edge.loadFromFile("Data/Images/kenney_pixelplatformer/Tiles/tile_0001.png"))
  {
    std::cout << "Did not load\n";
  }

  edge.initializeSprite(
    plat_edge,
    "Data/Images/kenney_pixelplatformer/Tiles/tile_0001.png");
  edge.getSprite()->setPosition(545, 450);
  edge.getSprite()->setScale(3,3);

  // Enemy.
  if (!enemy_texture.loadFromFile("Data/Images/kenney_tooncharacters1/Zombie/Tilesheet/character_zombie_sheet.png"))
  {
    std::cout << "Did not load\n";
  }

  enemy.initializeSprite(enemy_texture, "Data/Images/kenney_tooncharacters1/Zombie/Tilesheet/character_zombie_sheet.png");
  enemy.getSprite()->setPosition(800, 320);
  enemy.setSpeed(2);
  enemy.setDirection(0.5f,0);
  enemy_texture_rectangle = sf::IntRect(0,enemy_texture.getSize().y / 5 * 4,enemy_texture.getSize().x/9,enemy_texture.getSize().y / 5);
  enemy.getSprite()->setTextureRect(enemy_texture_rectangle);

  // Music.
  music.openFromFile("Data/Sound/Ship.ogg");
  music.setVolume(20);
  music.setLoop(true);
  music.play();

  // SFX.
  if (!jump_buffer.loadFromFile("Data/Sound/Jump.wav"))
  {
    std::cout << "Error";
  }
  jump.setBuffer(jump_buffer);

  if (!hit_buffer.loadFromFile("Data/Sound/Hit.wav"))
  {
    std::cout << "Error";
  }
  hit.setBuffer(hit_buffer);

  return true;
}

void Game::playerCollision()
{
  direction_y += 20;

    for (int i = 0; i < 30; i++)
    {
      platform1[i].platCollision(girl, direction_y);
    }

    for (int i = 0; i < 10; i++)
    {
      platform2[i].platCollision2(girl, direction_y);
    }

    for (int i = 0; i < 10; i++)
    {
      platform3[i].platCollision3(girl, direction_y);
    }
}

void Game::enemyCollision()
{
  lives1.lifeString();
  if (enemy.getSprite()->getGlobalBounds().intersects(girl.getSprite()->getGlobalBounds()))
  {
    girl.getSprite()->setPosition(100, 545);
    lives1.lifeDown();
    hit.play();
  }
  if (enemy.getSprite()->getPosition().x + enemy.getSprite()->getGlobalBounds().width > window.getSize().x)
  {
    enemy.setDirection(-0.5f,0);
    enemy.getSprite()->setScale(-1,1);
    enemy.getSprite()->setOrigin(enemy.getSprite()->getGlobalBounds().width,0);
  }

  if (enemy.getSprite()->getPosition().x < edge.getSprite()->getPosition().x)
  {
    enemy.setDirection(0.5f,0);
    enemy.getSprite()->setScale(1,1);
    enemy.getSprite()->setOrigin(0,0);
  }
}

void Game::update(float dt)
{
  if (game_state == 0)
  {
    score1.setScore();
    lives1.setLives();
    girl.getSprite()->setPosition(100, 545);
    direction_x = 0;

    menu.menuSelect(game_state);
    winning.winSelect(game_state);

    for (int i = 0; i < 5; i++)
    {
      coin_list[i].coinCollision(dt, girl, score_num, score, game_state, score1);
    }

  }

  if (game_state == 1)
  {
    enemy.getSprite()->move(enemy.getSpeed() * enemy.getDirection().x, 0);

    coin_list[0].coinCollision(dt, girl, score_num, score, game_state, score1);
    coin_list[1].coinCollision(dt, girl, score_num, score, game_state, score1);
    coin_list[2].coinCollision(dt, girl, score_num, score, game_state, score1);
    coin_list[3].coinCollision(dt, girl, score_num, score, game_state, score1);
    coin_list[4].coinCollision(dt, girl, score_num, score, game_state, score1);

    lives1.gameOver(game_state);

    score1.winScreen(game_state);

    girl.getSprite()->move(direction_x * dt, direction_y * dt);

    if (animation_clock.getElapsedTime().asSeconds() > 0.09)
    {
      girl_texture_rectangle.left += girl_texture.getSize().x / 9;
      if (girl_texture_rectangle.left > girl_texture.getSize().x / 9 * 7)
      {
        girl_texture_rectangle.left = 0;
      }
      girl.getSprite()->setTextureRect(girl_texture_rectangle);
      animation_clock.restart();
    }

    if (enemy_clock.getElapsedTime().asSeconds() > 0.09)
    {
      enemy_texture_rectangle.left += enemy_texture.getSize().x / 9;
      if (enemy_texture_rectangle.left > enemy_texture.getSize().x / 9 * 7)
      {
        enemy_texture_rectangle.left = 0;
      }
      enemy.getSprite()->setTextureRect(enemy_texture_rectangle);
      enemy_clock.restart();
    }
    playerCollision();
    enemyCollision();
  }

  if (game_state == 2)
  {
    losing.loseSelect(game_state);

  }

  if (game_state == 3)
  {
    winning.winSelect(game_state);
  }
}

void Game::render()
{
  if (game_state == 0)
  {
    window.draw(*background.getSprite());
    menu.render(window);
  }

  if (game_state == 1)
  {
    window.draw(*background.getSprite());
    lives1.render(window);
    score1.render(window);
    window.draw(*edge.getSprite());
    window.draw(*girl.getSprite());

    for (int i = 0; i < 30; i++)
    {
      platform1[i].render(window);
    }

    for (int i = 0; i < 10; i++)
    {
      platform2[i].render2(window);
    }

    for (int i = 0; i < 10; i++)
    {
      platform3[i].render3(window);
    }

    coin_list[0].render(window);
    coin_list[1].render(window);
    coin_list[2].render(window);
    coin_list[3].render(window);
    coin_list[4].render(window);

    window.draw(*enemy.getSprite());

  }

  if (game_state == 2)
  {
    window.draw(*background.getSprite());
    losing.render(window);
  }

  if (game_state == 3)
  {
    window.draw(*background.getSprite());
    winning.render(window);
  }
}

void Game::keyPressed(sf::Event event)
{
  if (game_state == 0)
  {
    menu.keyPressed(event, game_state, window);
  }


  if (game_state == 1)
  {
    if (event.key.code == sf::Keyboard::Left)
    {
      direction_x = -400;
      girl.getSprite()->setScale(-1,1);
      girl.getSprite()->setOrigin(girl.getSprite()->getGlobalBounds().width,0);

    }

    if (event.key.code == sf::Keyboard::Right)
    {
      direction_x = 400;
      girl.getSprite()->setScale(1,1);
      girl.getSprite()->setOrigin(0,0);
    }

    if (event.key.code == sf::Keyboard::Space)
    {
        direction_y -= 1100;
        jump.play();
    }

  }

  if (game_state == 2)
  {
    losing.keyPressed(event, game_state, window);
  }
  winning.keyPressed(event, game_state, window);
}

void Game::keyReleased(sf::Event event)
{
  if (game_state == 1)
  {
    if (event.key.code == sf::Keyboard::Left)
    {
      direction_x = 0;
    }

    if (event.key.code == sf::Keyboard::Right)
    {
      direction_x = 0;
    }
  }
}