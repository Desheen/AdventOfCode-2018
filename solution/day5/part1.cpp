#include <iostream>
#include <fstream>
#include <vector>

bool isTherePolymers( std::string& line ) {
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

int
main ( int argc , char**argv )
{
	std::ifstream file; file.open("input",std::ifstream::in); std::string line; std::getline(file,line); file.close();
	//std::string line2 = "yZzY";
	std::cout << "Line Length = : " << line.length() << std::endl;
	bool cont = true;

	while( cont ) {
		cont = isTherePolymers(line);
		std::cout << "Line Length = : " << line.length() << std::endl;
	}
	std::cout << "[+] Done Line = : " << line.length() << std::endl;
	return 0;
}
