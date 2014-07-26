#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject(sf::Sprite sprite, sf::Vector2f position,  sf::Vector2f velocity, int depth, bool alive);
        GameObject();
        virtual ~GameObject();
    protected:
    private:
        sf::Sprite sprite;
        sf::Vector2f position, velocity;
        int depth;
        bool alive;
};

#endif // GAMEOBJECT_H
