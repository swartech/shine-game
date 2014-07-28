#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class GameObject
{
    public:
        GameObject(std::string name, sf::Sprite sprite, sf::Vector2f position, sf::Vector2f velocity, int depth, bool alive, bool collidable);
        GameObject();
        virtual ~GameObject();
    
        static bool compareDepth(const GameObject& a, const GameObject& b);
    
        std::string name;
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
