#include "level.h"
#include <fstream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Image.hpp>
#include "LightOrb.h"
#include "Block.h"
#include "ResourcePath.hpp"

Level::Level(std::string fname, sf::Sprite lightOrbSprite, sf::Sprite blockSprite)
{
    sf::Image levelImage;
    levelImage.loadFromFile(fname);
    sf::Vector2u levelImageSize = levelImage.getSize();
    int tileWidth = 32;
    int tileHeight = 32;
    int currentX = 0;
    int currentY = 0;
    for (int i = 0; i < levelImageSize.x; ++i)
    {
        currentY = 0;
        for (int j = 0; j < levelImageSize.y; ++j)
        {
            sf::Color pixel =levelImage.getPixel(i, j);
            
            if (pixel == sf::Color(0, 0, 0))
            {
                //it's a platform block
                this->tilemap.push_back(Block(blockSprite, sf::Vector2f(currentX, currentY), sf::Vector2f(0, 0), true));
            }
            
            else if (pixel == sf::Color(255, 255, 255))
            {
                //it's a light orb
                this->tilemap.push_back(LightOrb(lightOrbSprite, sf::Vector2f(currentX, currentY), sf::Vector2f(0, 0), true));
            }
        
            currentY += tileHeight;
        }
        currentX += tileWidth;
        
    }
}