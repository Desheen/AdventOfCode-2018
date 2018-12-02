#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


int 
main( int argc ,char**argv )
{
	std::ifstream file;
	file.open("input", std::ifstream::in);
	std::string line;
	std::string line2;
	int frequency = 0;
	int temp;
	while(std::getline( file , line )){
		char op = line[0];
		if ( op == '+' ) {
			line2 = line.substr(1,line.size());
			temp = std::stoi(line2);
			frequency += temp;
		} else if ( op == '-') {
			line2 = line.substr(1,line.size());
			temp = std::stoi(line2);
			frequency -= temp;
		}

	}
	std::cout << frequency << std::endl;
	file.close();
	return 0;
}