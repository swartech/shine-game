#include "gameObject.h"

GameObject::GameObject()
{
    this->alive = false;
}

GameObject::GameObject(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive)
{
    this->sprite = sprite;
    this->position = position;
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
}

GameObject::~GameObject()
{
    //dtor
}
