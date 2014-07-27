#include <iostream>
#include <vector>
#include <string>

class level
{
	private:
		std::vector< std::vector<char> > blocks;
	public:
		level(std::string fname);
		void readout();
		void render();
};