#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H


class gameObject
{
    public:
        gameObject();
        virtual ~gameObject();
    protected:
    private:
        sf::Sprite sprite;
        sf::Vector2f position, velocity;
        int depth;
        bool alive;
};

#endif // GAMEOBJECT_H
