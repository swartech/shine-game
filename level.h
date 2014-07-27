#include <iostream>
#include <vector>
#include <string>
#include <Tile.h>
#include <SFML/Graphics.hpp>

class Level
{
	private:
	public:
    Level(std::string fname, sf::Sprite lightOrbSprite, sf::Sprite blockSprite);
    
        //variables
        std::vector<Tile> tilemap;
};