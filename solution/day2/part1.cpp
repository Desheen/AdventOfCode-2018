#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>



int
main( int argc , char**argv )
{
	std::ifstream file;
	std::vector<std::string> two;
	std::vector<std::string> three;
	file.open("input",std::ifstream::in);
	std::string line;
	while(std::getline(file,line))
	{
		std::map<char,int> freq;
		for( auto c : line )
		{
			if ( freq.find(c) == freq.end() )
				freq[c] = 1;
			else 
				++freq[c];
		}
		for( auto i : freq )
		{
			if ( i.second == 2 ){ 
				if ( std::find( two.begin() , two.end() , line ) == two.end() ) two.push_back(line);
				
			}
			if( i.second == 3 ){
				if ( std::find( three.begin() , three.end() , line ) == three.end() ) three.push_back(line);
			}
		}

	}
	file.close();
	std::cout << two.size() << " * " << three.size() << " = " << two.size()*three.size() << std::endl;
	
	return 0;
}