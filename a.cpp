#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

enum Direction
{
	LEFT,
	RIGHT
}

template < class Iterator >
void shift( const Iterator& begin, 
				const Iterator& end, 
				Direction dir = LEFT )  
{

	if(    ( ( begin    ) == end ) 
		 || ( ( begin -1 ) == end ) )
	{
		return;
	}

	if( dir == LEFT )
	{
		temp = *begin;	
	
		for( Iterator it = begin + 1; it != end; it++ )
		{
			*(it - 1) = *it;	
		}

   	*(end - 1) = temp;
	}

}


void fill_array( std::vector<int>& values )
{
	for( int &val : values )
	{
		val = rand()%100;
	}
}


template< typename T>
void show_vector( const std::vector<T> &values )
{

	for( const int &val : values )
	{
		std::cout << std::setw(2) << val << " ";
	}

	std::cout << std::endl;
}


int main()
{
	srand( time(NULL) );

	const size_t len = 10;

	std::vector<int> values( len );

	fill_array( values );

	show_vector( values );

	shift( values.begin(), values.end() );


	show_vector( values );

	return 0;
}

