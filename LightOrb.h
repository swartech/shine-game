#ifndef LIGHTORB_H
#define LIGHTORB_H

#include "Tile.h"


class LightOrb : public Tile
{
    public:
        LightOrb(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive);
        LightOrb();
        LightOrb(const LightOrb& other);
        virtual ~LightOrb();
    
        int luminosity;
    protected:
    private:

};

#endif // LIGHTORB_H
