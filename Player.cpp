#include "Player.h"

Player::Player()
{
    this->luminosity = 0;
}

Player::Player(sf::Texture spritesheet, sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool alive, bool collidable)
{
    this->spritesheet = spritesheet;
    this->currentFrame = 0;
    this->frameCount = 36;
    this->width = 32;
    this->height = 128;
    this->name = "Player";
    this->luminosity = 50;
    this->sprite = sprite;
    this->sprite.move(position);
    this->position = position;
    this->velocity = velocity;
    this->depth = 100;
    this->alive = alive;
    this->collidable = collidable;
}

Player::~Player()
{
    //virtual GameObject();
}

void Player::update()
{
    this->position += this->velocity;
    //go to the next frame of the animation
    this->currentFrame = (this->currentFrame + 1) % this->frameCount;
    this->sprite.setTexture(this->spritesheet);
    this->sprite.setTextureRect(sf::IntRect(this->width * this->currentFrame, 0, this->width, this->height));
    this->sprite.setPosition(this->position);
}


