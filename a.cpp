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

	Iterator temp;	

	if( dir == LEFT )
	{

		*temp = *begin;	
	
		for( Iterator it = begin + 1; it != end; it++ )
		{
			*( it - 1 ) = *it;	
		}

   	*(end - 1) = *temp;

	}


	if( dir == RIGHT )
	{

		*temp = *end;

		for( Iterator it = end - 1; it != begin; it-- )
		{
			*it = *( it - 1 );
		}
		*begin = *temp;

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


int main()
{
	const size_t len = 10;

	std::vector<int> values( len );

	fill_array( values );

/////////----LEFT_SHIFT----////////////////////////////

	std::cout << "before LEFT shift: " << std::endl;
	show_vector( values );

	shift( values.begin(), values.end(), LEFT );


	std::cout << "after LEFT shift: " << std::endl;
	show_vector( values );

/////////----RIGHT_SHIFT----//////////////////////////

	std::cout << "before RIGHT shift: " << std::endl;
	show_vector( values );
	
	shift( values.begin(), values.end(), RIGHT );
	
	std::cout << "after RIGHT shift: " << std::endl;
	show_vector( values );
	
	return 0;
}

