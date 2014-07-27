#include "LightOrb.h"
#include "ResourcePath.hpp"



LightOrb::LightOrb()
{
    //ctor
}

LightOrb::LightOrb(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive)
{
    this->sprite = sprite;
    this->position = position;
    this->sprite.move(position);
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
    this->collidable = true;
    this->luminosity = 10;
}

LightOrb::LightOrb(const LightOrb& other)
{
    this->texture = other.texture;
    this->sprite.setTexture(this->texture);
    this->position = other.position;
    this->sprite.move(position);
    this->velocity = other.velocity;
    this->depth = other.depth;
    this->alive = other.alive;
    this->collidable = other.collidable;
    this->luminosity = other.luminosity;
}

LightOrb::~LightOrb()
{
    //dtor
}
