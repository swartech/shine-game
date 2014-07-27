#ifndef LIGHTORB_H
#define LIGHTORB_H

#include "Tile.h"


class LightOrb : public Tile
{
    public:
        LightOrb(sf::Texture texture, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable);
        LightOrb();
        virtual ~LightOrb();
    protected:
        int luminosity;
    private:

};

#endif // LIGHTORB_H
