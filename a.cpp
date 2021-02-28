#include <iostream>
#include <vector>
#include <ctime>

//template< typename T>
//void shift( T& begin, T& end )  
//{
//	if( begin == end )
//		return;
//
//	auto temp = *begin;
//	if( end - 1 != begin )
//	{
//		temp = *(end - 1);	
//	}
//
//	for( T it = end - 1; it != begin; it-- )
//	{
//		*(it - 1) = *it;	
//	}
//
//   *begin = temp;
//}
//

//template < class Iterator, 
//	  		  class U = typename std::iterator_traits<Iterator>::value_type >
template < class Iterator >
void shift( Iterator begin, Iterator end )  
{
	if( begin == end )
		return;

	auto temp = *begin;
	if( end - 1 != begin )
	{
		temp = *(end - 1);	
	}

	for( Iterator it = end - 1; it != begin; it-- )
	{
		*(it - 1) = *it;	
	}

   *begin = temp;
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
		std::cout << val << " ";
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

