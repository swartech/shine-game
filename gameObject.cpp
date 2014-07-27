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

sf::Sprite GameObject::getSprite()
{
    return this->sprite;
}

sf::Texture GameObject::getTexture()
{
    return this->texture;
}
sf::Vector2f GameObject::getPosition()
{
    return this->position;
}
sf::Vector2f GameObject::getVelocity()
{
    return this->velocity;
}
int GameObject::getDepth()
{
    return this->depth;
}
bool GameObject::isAlive()
{
    return this->alive;
}
bool GameObject::isCollidable()
{
    return this->collidable;
}
