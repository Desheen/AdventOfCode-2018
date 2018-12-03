#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>

std::vector<short> match( std::string& s1 , std::string& s2) {

	std::vector<short> v;
	for( int i = 0 ; i < s1.size() ; ++i)
	{
		if( s1[i] != s2[i] ) 
		{
			v.push_back(i);
		}

	}
	return v;
}

int
main( int argc , char**argv )
{
	std::ifstream file;
	file.open("input",std::ifstream::in);
	std::string line;
	std::vector<std::string> data;
	while(std::getline(file,line))
	{
		data.push_back(line);
	}

	for( auto itr1 : data )
	{
		for( auto itr2 : data)
		{
			auto c = match(itr1,itr2);
			if( c.size() == 1 ) {
				std::cout << itr1 << std::endl;
			}
		}
	}
	return 0;
}