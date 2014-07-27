#include <iostream>
#include <vector>
#include <string>
#include <Tile.h>

class Level
{
	private:
	public:
		Level(std::string fname);
    
        //variables
        std::vector<Tile> tilemap;
};