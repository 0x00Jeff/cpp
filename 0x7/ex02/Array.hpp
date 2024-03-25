#include<iostream>
template <typename T>
class Array
{
	private:
		T		*_arr;
		size_t	_size;

	public:
		Array( void );
		Array( unsigned int n );

		Array( Array const & src );
		Array & operator=( Array const &);
		T& operator[](unsigned int i);
		T const & operator[](unsigned int i) const;

		// class template functionalities
		size_t const & size() const;

		~Array( void );
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);

template <typename T>
Array<T>::Array( void )
{
	std::cout << "created array" << std::endl;
	this -> _arr = new T(0);
	this -> _size = 0;
}

template <typename T>
Array<T>::Array( unsigned int n )
{
	std::cout << "created array of size " << n << std::endl;
	this -> _arr = new T(n);
	this -> _size = n;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= (this -> _size))
		throw std::out_of_range("index out of range!");
	return (this -> _arr[i]);
}

template <typename T>
T const & Array<T>::operator[](unsigned int i) const
{
	if (i < 0 || i >= (this -> _size))
		throw std::out_of_range("index out of range!");
	return (this -> _arr[i]);
}

template <typename T>
size_t const & Array<T>::size() const
{
	return (this -> _size);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr)
{
	size_t i;
	for(i = 0; i < arr.size(); i++)
		os << "arr[" << i << "] = " << arr[i] << std::endl;
	return os;
}

template <typename T>
Array<T>::~Array( void )
{
	std::cout << "deleted array of size " << this -> _size << std::endl;
	delete this -> _arr;
}
