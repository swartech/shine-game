//
//  Block.h
//  shine-game
//
//  Created by Sam Whelan on 27/07/2014.
//  Copyright (c) 2014 samwhelan. All rights reserved.
//

#ifndef __shine_game__Block__
#define __shine_game__Block__

//#include "GameObject.h"
#include "Tile.h"

class Block : public Tile
{
public:
    Block(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, bool alive);
    Block();
    virtual ~Block();
    
};



#endif /* defined(__shine_game__Block__) */
