#pragma once
#include<cstdbool>
#include<vector>

class Span
{
	private:
		std::vector<int> v;
		size_t size;
		size_t capacity;
		bool sorted;
		Span( void );

	public:
		Span( const unsigned int _n );
		Span( Span const & );

		// getters
		size_t getSize( void ) const;
		size_t getCapacity( void ) const;
		// class functionalities
		void addNumber( unsigned int number );
		void addNumber( std::vector<int>::iterator it, std::vector<int>::iterator ite );
		int shortestSpan( void );
		int longestSpan( void );
		// TODO : addNumber but with a range

		// exceptions
		class Span_Is_Full : public std::exception
		{
			virtual const char *what() const throw();
		};
		class Span_Has_Less_Then_Two_Elements : public std::exception
		{
			virtual const char *what() const throw();
		};

		Span & operator=( Span const & );

		~Span( void );
};
