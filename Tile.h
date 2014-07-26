#ifndef TILE_H
#define TILE_H

#include "gameObject.h"


class Tile : public GameObject
{
    public:
        Tile(sf::Texture texture, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable);
        Tile();
        virtual ~Tile();
    protected:
    private:
};

#endif // TILE_H
