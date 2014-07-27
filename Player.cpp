#include "Player.h"

Player::Player()
{
    this->luminosity = 0;
}

Player::Player(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->luminosity = 50;
    this->sprite = sf::Sprite(texture);
    this->position = position;
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
    this->collidable = collidable;
}

Player::~Player()
{
    //virtual GameObject();
}


