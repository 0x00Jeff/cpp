#pragma once
#include<iostream>


typedef struct Data 
{
	std::string name;
	int	age;
} Data;

class Serializer
{
	private:
		Serializer( void );
		Serializer( Serializer const & src );

		Serializer & operator=( Serializer const & );

		~Serializer( void );
	public:
		// class functionalities
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
