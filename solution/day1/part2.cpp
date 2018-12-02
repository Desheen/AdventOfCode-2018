#include <iostream>
#include <string>
#include <fstream>
#include <numeric>
#include <vector>
#include <algorithm>


int 
main( int argc ,char**argv )
{
	
	std::string line;
	std::vector<int> v;
	std::vector<int> freq;
	std::ifstream file;
	file.open("input", std::ifstream::in);
	while(std::getline( file , line ))
	{
		v.push_back( std::stoi(line) );
	}
	file.close();
	bool found = false;
	int sum = 0;
	while( !found ){
		for( int i : v ){
			sum += i;
			if ( std::find(freq.begin(),freq.end(),sum) != freq.end() ) {
				found = true;
				break;
			}
			freq.push_back(sum);
		}
	}
	if(found) std::cout << sum <<std::endl;
	else std::cout << "Not found\n";
	return 0;
}