#ifndef LIGHTORB_H
#define LIGHTORB_H

#include "Tile.h"


class LightOrb : public Tile
{
    public:
        LightOrb(sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive);
        LightOrb();
        virtual ~LightOrb();
    
        int luminosity;
    protected:
    private:

};

#endif // LIGHTORB_H
