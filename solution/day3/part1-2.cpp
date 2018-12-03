#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#define size 1000

struct fabric {
	int left_space = 0;
	int top_space = 0;
	int id = 0;
	int x = 0;
	int y = 0;
};


struct fabric* extract_info(std::string line ){
	struct fabric *a = new fabric();
	std::stringstream ss{line};
	std::string s;
	ss >> s;
	a->id = std::stoi(s.substr(1,s.length()));
	ss >> s;
	ss >> s;
	auto itr = s.find(",");
	int left_space = std::stoi(s.substr(0,itr));
	int top_space = std::stoi(s.substr(itr+1,s.length() -1 ));
	ss >> s;
	itr = s.find("x");
	int x = std::stoi(s.substr(0,itr));
	int y = std::stoi(s.substr(itr+1,s.length()));
	a->left_space = left_space;
	a->top_space = top_space;
	a->x = x;
	a->y = y;
	return a;
}


int 
main( int argc ,char**argv )
{
	char rectangle [size][size];


	for( int row = 0 ; row < size ;++row )
	{
		for( int column = 0 ; column < size ; ++column )
		{
			rectangle[row][column] = '0';
		}
	}

	


	std::ifstream file;
	file.open("input",std::ifstream::in);
	std::vector<std::string> lines;
	std::string line;
	while(std::getline(file,line))
	{
		lines.push_back(line);
		fabric *a = extract_info(line);
		//std::cout << a->id << " : " << a->left_space << " , " << a->top_space << " : " << a->x << " x " << a->y << std::endl;
		for( int row = a->left_space ; row < (a->left_space + a->x) ; ++row  )
		{

			for( int column = a->top_space ; column < ( a->top_space + a->y ) ; ++column )
			{
				if ( rectangle[row][column] == '0' )
					rectangle[row][column] = 'A';
				else if ( rectangle[row][column] == 'A' ) {
					rectangle[row][column] = 'X';
				}

			}
		}
		delete a;
	}

	bool allA;
	int id = 0 ;
	for( std::string i : lines)
	{
		fabric *a = extract_info(i);
		allA = true;
		for( int row = a->left_space ; row < (a->left_space + a->x) ; ++row  )
		{

			for( int column = a->top_space ; column < ( a->top_space + a->y ) ; ++column )
			{
				if ( rectangle[row][column] == 'X' ) {
					allA = false;
					break;
				}

			}
		}
		if( allA ) {
			id = a->id;
			std::cout << "Part 2 : " << id << std::endl;
		}
		delete a;
	}
	int counter = 0;
	for( int row = 0 ; row < size ;++row )
	{
		for( int column = 0 ; column < size ; ++column )
		{
			
			if(rectangle[row][column] == 'X')
				++counter;
		}
	}

	std::cout << "Part 1 : " << counter  << std::endl;
	return 0;
}