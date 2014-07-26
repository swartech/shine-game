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
    protected:
    private:
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position, velocity;
        int depth;
        bool alive;
        bool collidable;
        sf::FloatRect boundingBox;
};

#endif // GAMEOBJECT_H
