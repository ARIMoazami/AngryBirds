
#ifndef ANGRYBIRDS_GAME_H
#define ANGRYBIRDS_GAME_H

#include "GameObject.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void mouseReleased(sf::Event event);

 private:
  sf::RenderWindow& window;


  sf::Font font;

  //main menu
  bool in_menu = true;
  bool opt_diff = true;
  int option = 0;
  sf::Text enter_text;
  sf::Text quit_text;
  sf::Sprite menu_background;
  sf::Texture background_texture;

  //instruction menu
  bool in_instr_menu = false;
  sf::Text instr_text;
  sf::Text return_key_text;

  //game option menu
  bool in_game_opt = false;
  sf::Text play_text;
  sf::Text return_text;
  sf::Text help_text;

  //win menu
  bool in_win_menu = false;
  sf::Text win_text;
  sf::Text menu_return;
  sf::Text menu_quit;

  //lose menu
  bool in_lose_menu = false;
  sf::Text lost_text;

  //gameplay
  sf::Sprite lvl1_background;
  sf::Texture lvl1_texture;
  bool in_gameplay = false;
  sf::Sprite slingshot;
  sf::Texture slingshot_texture;
  int score = 0;
  sf::Text score_text;
  bool Clicked = false;
  bool flying = false;

  //pause menu
  bool in_pause = false;
  sf::Text pause_text;
  sf::Text resume_text;

  GameObject* bird;
  GameObject* enemy[3];

  sf::Text bird_num_text;

  int xpos;
  int ypos;

  int bird_num = 4;

  float speed;

  bool released = false;

  float angle_x;
  float angle_y;



};

#endif // ANGRYBIRDS_GAME_H
