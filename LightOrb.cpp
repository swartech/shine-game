#include "LightOrb.h"
#include "ResourcePath.hpp"

LightOrb::LightOrb()
{
    //ctor
}

LightOrb::LightOrb(sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive)
{
    sf:: Texture texture;
    texture.loadFromFile(resourcePath() + "lightOrb.png");
    this->texture = texture;
    this->sprite.setTexture(texture);
    this->position = position;
    this->sprite.move(position);
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
    this->collidable = true;
    this->luminosity = 10;
}

LightOrb::~LightOrb()
{
    //dtor
}
