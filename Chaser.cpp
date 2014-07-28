#include "Chaser.h"

Chaser::Chaser()
{
    //ctor
}

Chaser::Chaser(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity)
{
    this->name = "Chaser";
    this->sprite = sprite;
    this->sprite.move(position);
    this->position = position;
    this->velocity = velocity;
    this->depth = 100;
    this->alive = true;
    this->collidable = true;
}

Chaser::~Chaser()
{
    //dtor
}
