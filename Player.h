#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"


class Player : public GameObject
{
    public:
        Player();
        Player( sf::Texture texture, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive, bool collidable);
        virtual ~Player();
    protected:
    private:
        int luminosity;
};

#endif // PLAYER_H
