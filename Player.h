#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"


class Player : public GameObject
{
    public:
        inline Player();
        inline Player(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable);
        inline ~Player();
    protected:
        int luminosity;
    private:

};

#endif // PLAYER_H
