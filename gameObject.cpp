#include "gameObject.h"

gameObject::gameObject()
{
    this.alive = false;
}

gameObject::gameObject(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive)
{
    this.sprite = sprite;
    this.position = position;
    this.velocity = velocity;
    this.depth = depth;
    this.alive = alive;
}

gameObject::~gameObject()
{
    //dtor
}
