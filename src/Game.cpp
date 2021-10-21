
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
  font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf");

  background_texture.loadFromFile("Data/Images/menu.jpg");
  menu_background.setTexture(background_texture);

  lvl1_texture.loadFromFile("Data/Images/lvl1.png");
  lvl1_background.setTexture(lvl1_texture);

  slingshot_texture.loadFromFile("Data/Images/Slingshot.png");
  slingshot.setTexture(slingshot_texture);
  slingshot.setPosition(300 ,800);

  //play text
  play_text.setString("> PLAY GAME");
  play_text.setFont(font);
  play_text.setCharacterSize(50);
  play_text.setFillColor(sf::Color(255,255,255));
  play_text.setPosition(250,100);

  //enter text
  enter_text.setString("> ENTER");
  enter_text.setFont(font);
  enter_text.setCharacterSize(50);
  enter_text.setFillColor(sf::Color(255,255,255));
  enter_text.setPosition(250,150);

  //quit text
  quit_text.setString("QUIT");
  quit_text.setFont(font);
  quit_text.setCharacterSize(50);
  quit_text.setFillColor(sf::Color(255,255,255));
  quit_text.setPosition(350,250);

  //return to menu text
  return_text.setString("RETURN");
  return_text.setFont(font);
  return_text.setCharacterSize(50);
  return_text.setFillColor(sf::Color(255,255,255));
  return_text.setPosition(350,300);

  //win/lost menu quit text
  menu_quit.setString("QUIT GAME");
  menu_quit.setFont(font);
  menu_quit.setCharacterSize(50);
  menu_quit.setFillColor(sf::Color(255,255,255));
  menu_quit.setPosition(350,250);

  //win/lose return text
  menu_return.setString("RETURN TO MENU");
  menu_return.setFont(font);
  menu_return.setCharacterSize(50);
  menu_return.setFillColor(sf::Color(255,255,255));
  menu_return.setPosition(350,300);

  //instructions menu text
  help_text.setString("INSTRUCTIONS");
  help_text.setFont(font);
  help_text.setCharacterSize(50);
  help_text.setFillColor(sf::Color(255,255,255));
  help_text.setPosition(350,200);

  //instructions text
  instr_text.setString("To play this game all your goal is to defeat the enemies\n"
                       "by flinging the birds into the enemies\nHold the left"
                       " mouse button to begin launching a bird\nrelease"
                       " the mouse button to launch the bird.");
  instr_text.setFont(font);
  instr_text.setCharacterSize(50);
  instr_text.setFillColor(sf::Color(255,255,255));
  instr_text.setPosition(350,200);

  //return to menu key text
  return_key_text.setString("To return to the main menu hit the *TAB* key\n"
                            "to pause the game hit the *P* key");
  return_key_text.setFont(font);
  return_key_text.setCharacterSize(50);
  return_key_text.setFillColor(sf::Color(255,255,255));
  return_key_text.setPosition(350,550);

  //pause text
  pause_text.setString("GAME PAUSED");
  pause_text.setFont(font);
  pause_text.setCharacterSize(50);
  pause_text.setFillColor(sf::Color(255,255,255));
  pause_text.setPosition(700,100);

  //win menu text
  win_text.setString("YOU WIN!");
  win_text.setFont(font);
  win_text.setCharacterSize(50);
  win_text.setFillColor(sf::Color(255,255,255));
  win_text.setPosition(700,100);

  //lose menu text
  lost_text.setString("YOU LOSE!");
  lost_text.setFont(font);
  lost_text.setCharacterSize(50);
  lost_text.setFillColor(sf::Color(255,255,255));
  lost_text.setPosition(700,100);

  //resume game text
  resume_text.setString("RESUME");
  resume_text.setFont(font);
  resume_text.setCharacterSize(50);
  resume_text.setFillColor(sf::Color(255,255,255));
  resume_text.setPosition(350,200);

  //score
  score_text.setString("score: " + std::to_string(score));
  score_text.setFont(font);
  score_text.setCharacterSize(50);
  score_text.setFillColor(sf::Color(255,255,255));
  score_text.setPosition(1500, 100);

  //bird number
  bird_num_text.setString("birds left: " + std::to_string(bird_num));
  bird_num_text.setFont(font);
  bird_num_text.setCharacterSize(50);
  bird_num_text.setFillColor(sf::Color(255,255,255));
  bird_num_text.setPosition(1000, 100);


  //creating birds
    bird = new GameObject();
    bird->initialiseSprite(bird->bird_texture,"Data/Images/kenney_animalpackredux/PNG/Round/duck.png");
    bird->getSprite()->setPosition(410, 830);
    bird->getSprite()->setScale(0.6,0.6);
    bird->getSprite()->setOrigin(bird->getSprite()->getGlobalBounds().width*0.5, bird->getSprite()->getGlobalBounds().height*0.5);


  //creating enemies
  for (int y = 0; y < 3; y++)
  {
    enemy[y] = new GameObject();
    enemy[y]->initialiseSprite(enemy[y]->enemy_texture,"Data/Images/kenney_animalpackredux/PNG/Square/pig.png");
    enemy[y]->getSprite()->setScale(0.6,0.6);


  }
  return true;
}

void Game::update(float dt)
{

  enemy[0]->getSprite()->setPosition(1200, 700);
  enemy[1]->getSprite()->setPosition(1350, 800);
  enemy[2]->getSprite()->setPosition(1500, 900);

  for (int y = 0; y < 3; y++)
  {
    if (bird->getSprite()->getGlobalBounds().intersects(enemy[y]->getSprite()->getGlobalBounds()) and enemy[y]->visibility)
    {
      score += 1;
      bird_num -= 1;
      bird_num_text.setString("birds left: " + std::to_string(bird_num));
      score_text.setString("score: " + std::to_string(score));
      enemy[y]->visibility = false;
      bird->visibility = true;
      bird->getSprite()->setPosition(410, 830);
      flying = false;
    }

    if (bird->getSprite()->getPosition().y > window.getSize().y)
    {
     bird->getSprite()->setPosition(410, 830);
     bird->visibility = true;
     flying = false;
    }


    if (bird->getSprite()->getPosition().x > window.getSize().x)
    {
      bird->getSprite()->setPosition(410, 830);
      bird->visibility = true;
      bird_num -= 1;
      bird_num_text.setString("birds left: " + std::to_string(bird_num));
      flying = false;
    }
  }

  if ((bird->getSprite()->getPosition().x >=
       (window.getSize().x - bird->getSprite()->getGlobalBounds().width)) ||
      (bird->getSprite()->getPosition().x <= 0))
  {
    flying = false;
    bird->getSprite()->setPosition(410, 830);
    bird_num -= 1;
    bird_num_text.setString("birds left: " + std::to_string(bird_num));
  }

  if (in_gameplay && flying == true)
  {
   bird->getSprite()->move(0, 10);
  }


  if (bird_num == 0)
  {
    in_gameplay = false;
    in_lose_menu = true;
  }


  if (score == 3)
  {
    in_gameplay = false;
    in_win_menu = true;
    in_lose_menu = false;
  }

  if (in_lose_menu or in_win_menu or in_menu or in_instr_menu)
  {
    bird->getSprite()->move(0,0);
  }

  xpos = sf::Mouse::getPosition(window).x;

  ypos = sf::Mouse::getPosition(window).y;

  if (Clicked == true)
  {
    for (int x = 0; x < 4; x++)
    {
      bird->getSprite()->setPosition(xpos, ypos);
    }
  }


  if (flying == true)
  {
    for (int x = 0; x < 4; x++)
    {
      angle_y = angle_y + 1;
      speed = 5;
      bird->getSprite()->move(angle_x * speed * dt, angle_y * speed * dt);
    }
  }

  if (flying == false)
  {
    angle_x = -(bird->getSprite()->getPosition().x - 410);
    angle_y = -(bird->getSprite()->getPosition().y - 830);
  }

}

void Game::render()
{
  if (in_menu)
  {
    window.draw(menu_background);
    window.draw(quit_text);
    window.draw(enter_text);
  }
  if (in_instr_menu)
  {
    window.draw(instr_text);
    window.draw(return_key_text);
  }
  if (in_win_menu)
  {
    window.draw(win_text);
    window.draw(menu_return);
    window.draw(menu_quit);
  }
  if (in_lose_menu)
  {
    window.draw(lost_text);
    window.draw(menu_return);
    window.draw(menu_quit);
  }
  if (in_game_opt)
  {
    window.draw(play_text);
    window.draw(help_text);
    window.draw(return_text);
  }
  if (in_pause)
  {
    window.draw(pause_text);
    window.draw(return_text);
    window.draw(resume_text);
  }
  if (in_gameplay)
  {
    window.draw(lvl1_background);
    window.draw(slingshot);
    window.draw(score_text);
    window.draw(bird_num_text);
    for (int x = 0; x < 4; x++)
    {
      if (bird->visibility)
      {
        window.draw(*bird->getSprite());
      }
    }
    for (int y = 0; y < 3; y++)
    {
      if (enemy[y]->visibility)
      {
        window.draw(*enemy[y]->getSprite());
      }
    }
  }
}

void Game::mouseClicked(sf::Event event)
{
  if (in_gameplay)
  {
    //mouse drag sprite
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      Clicked = true;
    }
  }


}
void Game::mouseReleased(sf::Event event)
{
  if (event.mouseButton.button == sf::Mouse::Left)
  {
    Clicked = false;
    flying = true;
  }
}

void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::W)
  {
    if (option > 0)
    {
      option -= 1;
    }
  }

  int game_choice = 1;

  if (in_game_opt == true)
  {
    game_choice = 2;
  }

  if (in_lose_menu == true)
  {
    game_choice = 1;
  }

  if (in_pause == true)
  {
    game_choice = 1;
  }

  if (in_win_menu == true)
  {
    game_choice = 1;
  }

  if (event.key.code == sf::Keyboard::S)
  {
    if (option < game_choice)
    {
      option += 1;
    }
  }

  //main menu
  if (in_menu == true)
  {
    switch (option)
    {
      case 0:
        enter_text.setString("> ENTER");
        quit_text.setString("QUIT");
        break;
      case 1:
        enter_text.setString("ENTER");
        quit_text.setString("> QUIT");
        break;
      default:
        break;
    }

    if (event.key.code == sf::Keyboard::Enter and opt_diff)
    {
      opt_diff = false;
      switch (option)
      {
        case 0:
          in_menu = false;
          in_game_opt = true;
          in_win_menu = false;
          in_lose_menu = false;
          break;
        case 1:
          window.close();
          break;
        default:
          break;
      }
    }
  }

  //pause menu
  if (in_pause)
  {
    switch (option)
    {
      case 0:
        resume_text.setString("> RESUME");
        return_text.setString("RETURN");
        break;
      case 1:
        resume_text.setString("RESUME");
        return_text.setString("> RETURN");
        break;
      default:
        break;
    }

    if (event.key.code == sf::Keyboard::Enter and opt_diff)
    {
      opt_diff = false;
      switch (option)
      {
        case 0:
          in_pause = false;
          in_gameplay = true;
          break;
        case 1:
          in_menu = true;
          in_pause = false;
          break;
        default:
          break;
      }
    }
  }

  //win menu
  if (in_win_menu)
  {
    switch (option)
    {
      case 0:
        menu_quit.setString("> QUIT GAME");
        menu_return.setString("RETURN TO MENU");
        break;
      case 1:
        menu_quit.setString("QUIT GAME");
        menu_return.setString("> RETURN TO MENU");
        break;
      default:
        break;
    }

    if (event.key.code == sf::Keyboard::Enter and opt_diff)
    {
      opt_diff = false;
      switch (option)
      {
        case 0:
          window.close();
          break;
        case 1:
          in_menu = true;
          in_win_menu = false;
          in_lose_menu = false;
          in_gameplay = false;
          flying = false;
          Clicked = false;
          bird->getSprite()->setPosition(410, 830);
          break;
        default:
          break;
      }
    }
  }

  //lose menu
  if (in_lose_menu)
  {
    switch (option)
    {
      case 0:
        menu_quit.setString("> QUIT GAME");
        menu_return.setString("RETURN TO MENU");
        break;
      case 1:
        menu_quit.setString("QUIT GAME");
        menu_return.setString("> RETURN TO MENU");
        break;
      default:
        break;
    }

    if (event.key.code == sf::Keyboard::Enter and opt_diff)
    {
      opt_diff = false;
      switch (option)
      {
        case 0:
          window.close();
          break;
        case 1:
          in_menu = true;
          in_lose_menu = false;
          in_win_menu = false;
          in_instr_menu = false;
          in_gameplay = false;
          in_game_opt = false;
          in_pause = false;
          flying = false;
          Clicked = false;
          break;
        default:
          break;
      }
    }
  }


  //options menu
  if (in_game_opt)
  {
    switch (option)
    {
      case 0:
        play_text.setString("> PLAY GAME");
        help_text.setString("INSTRUCTIONS");
        return_text.setString("RETURN");
        break;
      case 1:
        play_text.setString("PLAY GAME");
        help_text.setString("> INSTRUCTIONS");
        return_text.setString("RETURN");
        break;
      case 2:
        play_text.setString("PLAY GAME");
        help_text.setString("INSTRUCTIONS");
        return_text.setString("> RETURN");
        break;
      default:
        break;
    }

    if (event.key.code == sf::Keyboard::Enter and opt_diff)
    {
      opt_diff = false;
      switch (option)
      {
        case 0:
          in_menu = false;
          in_game_opt = false;
          in_instr_menu = false;
          in_gameplay = true;
          score = 0;
          bird_num = 4;
          for (int y = 0; y < 3; y++)
          {
            enemy[y]->visibility = true;
            enemy[y]->getSprite()->setPosition(y*250+ 1200, 800);
          }
          break;
        case 1:
          in_menu = false;
          in_game_opt = false;
          in_instr_menu = true;
          break;
        case 2:
          in_menu = true;
          in_game_opt = false;
          in_instr_menu = false;
          break;
        default:
          break;
      }
    }
  }



  //quit game key
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
  {
    window.close();
  }

  //lost menu test key
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
  {
    in_lose_menu = true;
    in_gameplay = false;
  }

  //win menu test key
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::J))
  {
    in_win_menu = true;
    in_gameplay = false;
  }

  //TAB game key
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
  {
    in_menu = false;
    in_instr_menu = false;
    in_game_opt = true;
    in_pause = false;
    in_gameplay = false;
    in_win_menu = false;
    in_lose_menu = false;
  }

  if (in_gameplay)
  {
    //pause menu key
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
    {
      in_menu = false;
      in_instr_menu = false;
      in_game_opt = false;
      in_gameplay = false;
      in_pause = true;
    }
  }
}

void Game::keyReleased(sf::Event event)
{
  opt_diff = true;
}
