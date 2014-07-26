#include "gameObject.h"

GameObject::GameObject()
{
    this->alive = false;
}

GameObject::GameObject(sf::Texture texture, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->texture = texture;
    this->position = position;
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
    this->collidable = collidable;
    this->boundingBox = sprite.getGlobalBounds();
    this->sprite.setTexture(texture);
}

GameObject::~GameObject()
{
    //dtor
}

sf::FloatRect GameObject::GetBoundingBox()
{
    return this->boundingBox;
}
