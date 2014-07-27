#include "Player.h"

Player::Player()
{
    this->luminosity = 0;
}

Player::Player(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->luminosity = 50;
}

Player::~Player()
{
    //virtual GameObject();
}


