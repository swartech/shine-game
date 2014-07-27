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
    
        sf::Sprite sprite;
        sf::Texture texture;
        sf::Vector2f position, velocity;
        int depth;
        bool alive, collidable;
        sf::FloatRect boundingBox;
    protected:
    private:

};

#endif // GAMEOBJECT_H
