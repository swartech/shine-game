#ifndef PLAYER_H
#define PLAYER_H

#include "gameObject.h"


class Player : public GameObject
{
    public:
        Player();
        Player(sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, bool alive, bool collidable);
        ~Player();
    
        int luminosity;
        std::string name;
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position, velocity;
        int depth;
        bool alive;
        bool collidable;
        sf::FloatRect boundingBox;
    
    protected:
    private:

};

#endif // PLAYER_H
