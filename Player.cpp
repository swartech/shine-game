#include "Player.h"

inline Player::Player()
{
    this->luminosity = 0;
}

inline Player::Player(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->luminosity = 50;
}

inline Player::~Player()
{
    //virtual GameObject();
}


