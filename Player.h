#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"


class Player : public GameObject
{
    public:
        Player();
    Player(sf::Texture spritesheet, sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool alive, bool collidable);
        ~Player();
        void update();
    
        std::string name;
        sf::Sprite sprite;
        sf::Texture spritesheet;
        sf::Vector2f position, velocity;
        int width, height, depth, frameCount, currentFrame, luminosity;
        bool alive;
        bool collidable;
        sf::FloatRect boundingBox;
    
    protected:
    private:

};

#endif // PLAYER_H
