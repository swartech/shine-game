#include "level.h"
#include <fstream>

level::level(std::string fname)
{
	std::ifstream levelfile;
	
	levelfile.open(fname);

	if(levelfile.is_open()){
		std::string vline;
		while(!levelfile.eof()){
			std::getline(levelfile,vline);
			std::vector <char> linerec;
			for(std::string::iterator it = vline.begin(); it != vline.end(); ++it) {
				linerec.push_back(*it);
			}
			blocks.push_back(linerec);
		}
	}
	else {
		std::cout << "Could not load level. Unable to find file `" << fname << "'." << std::endl;
	}
	levelfile.close();
}

void level::readout()
{
	std::string message;
	message = "";
	for(std::vector< std::vector <char>>::iterator it = blocks.begin(); it !=blocks.end(); ++it){
		for(std::vector <char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
			message = message + (*it2) + "";
		}
		message = message + "\n";
	}
	std::cout << message;
}

void level::render()
{
	int width(0);
	for(std::vector< std::vector <char>>::iterator it = blocks.begin(); it !=blocks.end(); ++it){
		int height(0);
		for(std::vector <char>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2){
			
			height = height + 32;
		}
		width = width + 32;
	}
}