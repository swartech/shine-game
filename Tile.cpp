#include "Tile.h"

Tile::Tile()
{
    
}

Tile::Tile(sf::Texture texture, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable)
{
    this->texture = texture;
    this->sprite.setTexture(texture);
    this->position = position;
    this->velocity = velocity;
    this->depth = depth;
    this->alive = alive;
    this->collidable = collidable;
}

Tile::~Tile()
{
    //delete this;
}
