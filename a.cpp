#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

enum Direction
{
	LEFT,
	RIGHT
};

template < class Iterator >
void shift( const Iterator& begin, 
				const Iterator& end, 
				Direction dir = LEFT )  
{

	if(  ( begin    ) == end  )
		return;
   
	if(  ( begin -1 ) == end  )
		return;

	if( dir == LEFT )
	{

		auto temp = *begin;	
	
		for( Iterator it = begin + 1; it != end; it++ )
		{
			*( it - 1 ) = *it;	
		}

   	*( end - 1 ) = temp;

	}


	if( dir == RIGHT )
	{

		auto temp = *( end - 1 );

		for( Iterator it = end - 1; it != begin; it-- )
		{
			*it = *( it - 1 );
		}

		*begin = temp;

	}

}


void fill_array( std::vector<int>& values )
{
	srand( time(NULL) );
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


void show_string( const std::string &str )
{
	std::cout 	<< std::endl
					<< str
					<< std::endl;
}

void new_line()
{
	std::cout 	<< std::endl;
}


int main()
{
	const size_t len = 10;

	std::vector<int> values( len );

	fill_array( values );


/////////----LEFT_SHIFT----////////////////////////////

	show_string( "before LEFT shift: " );
	show_vector( values );

	shift( values.begin(), values.end(), LEFT );

	show_string( "after LEFT shift: " );
	show_vector( values );


/////////----RIGHT_SHIFT----//////////////////////////

	show_string( "before RIGHT shift: " );
	show_vector( values );

	shift( values.begin(), values.end(), RIGHT );

   show_string( "after RIGHT shift: " );
	show_vector( values );

	new_line();

	return 0;
}

