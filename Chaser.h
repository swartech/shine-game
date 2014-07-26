#ifndef CHASER_H
#define CHASER_H

#include "gameObject.h"


class Chaser : public GameObject
{
    public:
        Chaser(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable);
        Chaser();
        virtual ~Chaser();
    protected:
    private:
};

#endif // CHASER_H
