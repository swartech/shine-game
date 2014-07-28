#ifndef CHASER_H
#define CHASER_H

#include "gameObject.h"


class Chaser : public GameObject
{
    public:
        Chaser(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity);
        Chaser();
        virtual ~Chaser();
    protected:
    private:
};

#endif // CHASER_H
