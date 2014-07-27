#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject(sf::Texture texture, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable);
        GameObject();
        virtual ~GameObject();
        sf::FloatRect GetBoundingBox();
        sf::Sprite getSprite();
        sf::Texture getTexture();
        sf::Vector2f getPosition();
        sf::Vector2f getVelocity();
        int getDepth();
        bool isAlive();
        bool isCollidable();
    protected:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position, velocity;
        int depth;
        bool alive;
        bool collidable;
        sf::FloatRect boundingBox;
    private:

};

#endif // GAMEOBJECT_H
