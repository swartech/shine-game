#include "Player.h"

Player::Player()
{
    this->luminosity = 0;
}

Player::Player(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool alive, bool collidable)
{
    this->name = "Player";
    this->luminosity = 50;
    this->sprite = sprite;
    this->sprite.move(position);
    this->position = position;
    this->velocity = velocity;
    this->depth = 100;
    this->alive = alive;
    this->collidable = collidable;
}

Player::~Player()
{
    //virtual GameObject();
}


