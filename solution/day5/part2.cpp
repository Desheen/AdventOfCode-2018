#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <cctype>

bool reacting( std::string& line ) {
	for( int i = 0  ; i < line.length() ; ++i )
	{
		if( std::abs( line[i] - line[i+1] ) == 32 ) {
			auto itr = line.begin() + i;
			line.erase(itr);
			line.erase(itr);
			return true;
		}
	}
	return false;
}
std::string removeLetter(std::string line, char toRemove)
{
	for( int i = 0 ; i < line.length() ; ++i )
	{
		if( toupper(line[i]) == toRemove )
		{
			auto itr = line.begin() +i ;
			line.erase(itr);
		}
	}
	return line;
}

int
main ( int argc , char**argv )
{
	std::ifstream file; file.open("input",std::ifstream::in); std::string line; std::getline(file,line); file.close();
	std::cout << " Original Line Length = : " << line.length() << std::endl;
	int min = 50000;
	for( int i = 65 ; i <= 90 ; ++i )
	{
		std::string lineTemp = line;
		lineTemp.erase( std::remove(lineTemp.begin(), lineTemp.end(), static_cast<char>(i) ),
               lineTemp.end());
		lineTemp.erase( std::remove(lineTemp.begin(), lineTemp.end(), static_cast<char>(i+32) ),
               lineTemp.end());
		//std::cout << lineTemp << std::endl;
		bool cont = true;
		while( cont ) { cont = reacting(lineTemp); }
		std::cout << "[+] " << i << " Done Line = : " << lineTemp.length() << std::endl;
		if( lineTemp.length() < min ) min = lineTemp.length();
	}

	std::cout << "Min : " << min << std::endl;
	return 0;
}
