#include "gameObject.h"

GameObject::GameObject()
{
    this->alive = false;
}

GameObject::GameObject(std::string name, sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->name = name;
    this->sprite = sprite;
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

bool GameObject::compareDepth(const GameObject& a, const GameObject& b)
{
    return a.depth < b.depth;
}
