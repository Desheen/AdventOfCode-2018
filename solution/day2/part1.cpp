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
			//std::cout << i.first << " : " << i.second << " ";
			if ( i.second == 2 ){ 
				if ( std::find( two.begin() , two.end() , line ) == two.end() ) two.push_back(line);
				
			}
			if( i.second == 3 ){
				if ( std::find( three.begin() , three.end() , line ) == three.end() ) three.push_back(line);
			}
		}
		//std::cout << "\n";
	}
	file.close();
	
	/*std::sort(two.begin() , two.end() );
	auto lastOfTwo = std::unique(two.begin() , two.end() );
	two.erase( lastOfTwo, two.end());
	std::sort(three.begin() , three.end() );
	auto lastOfThree = std::unique(three.begin() , three.end() );
	three.erase( lastOfThree, three.end());
	std::cout << "Two: " ;
	for( char i : two ) std::cout << i << " ";
	std::cout << "Size : " << two.size() << std::endl;
	std::cout << "Three: " ;
	for( char i : three ) std::cout << i << " ";
	std::cout << "Size : " << three.size() << std::endl;
	std::cout << "\n------------------\n";
	*/
	std::cout << two.size() << " * " << three.size() << " = " << two.size()*three.size() << std::endl;
	
	return 0;
}