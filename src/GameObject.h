
#ifndef ANGRYBIRDS_GAMEOBJECT_H
#define ANGRYBIRDS_GAMEOBJECT_H

#include <string>
#include <SFML/Graphics.hpp>
#include "Vector2.h"

class GameObject
{
 public:
  GameObject();
  ~GameObject();

  bool initialiseSprite(sf::Texture &texture, std::string filename);
  sf::Sprite* getSprite();


  sf::Texture bird_texture;
  sf::Texture enemy_texture;

  bool visibility = true;


  Vector2 direction = {0,0};

 private:
  sf::Sprite* sprite = nullptr;
};

#endif // ANGRYBIRDS_GAMEOBJECT_H


