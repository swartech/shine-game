#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"


class Player : public GameObject
{
    public:
        Player();
        Player( sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive );
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
