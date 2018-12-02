#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <vector>

int 
main( int argc ,char**argv )
{
	
	std::string line;
	std::vector<int> v;
	std::ifstream file;
	file.open("input", std::ifstream::in);
	while(std::getline( file , line ))
	{
		v.push_back( std::stoi(line) );
	}
	file.close();
	
	std::cout << std::accumulate(v.begin(), v.end() , 0) << std::endl;
	return 0;
}