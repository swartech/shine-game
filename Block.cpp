//
//  Block.cpp
//  shine-game
//
//  Created by Sam Whelan on 27/07/2014.
//  Copyright (c) 2014 samwhelan. All rights reserved.
//

#include "Block.h"
#include "ResourcePath.hpp"

Block::Block()
{
    //ctor
}

Block::Block(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, bool alive)
{
    this->name = "Block";
    this->sprite = sprite;
    this->sprite.move(position);
    this->position = position;
    this->velocity = velocity;
    this->depth = 50;
    this->alive = alive;
    this->collidable = true;

}

Block::~Block()
{
    //dtor
}

