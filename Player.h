#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"

class Player : public GameObject
{
    public:
        Player(sf::Texture spritesheet, sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool alive, bool collidable);
        Player();
        virtual ~Player();
        void update();
    
        sf::Texture spritesheet;
        int frameCount, currentFrame, luminosity;
    
    protected:
    private:

};

#endif // PLAYER_H
