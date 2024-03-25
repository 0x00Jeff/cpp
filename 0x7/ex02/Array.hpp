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

		Array( Array<T> const & src );
		T& operator[](unsigned int i);
		T const & operator[](unsigned int i) const;
		Array & operator=(Array<T> const & src);

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
	this -> _arr = new T[n];
	this -> _size = n;
}

template <typename T>
T& Array<T>::operator[](unsigned int i)
{
	if (i >= (this -> _size))
		throw std::out_of_range("index out of range!");
	return (this -> _arr[i]);
}

template <typename T>
Array<T>::Array( Array<T> const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	this -> _arr = NULL;
	*this = src;
}

template <typename T>
Array<T> & Array<T>::operator=(Array<T> const & src)
{
	size_t i;
	size_t src_size;
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src )
	{
		if (this -> _arr)
			delete [] this -> _arr;

		src_size = src.size();
		this -> _arr = new T[src_size];
		this -> _size = src_size;

		for(i = 0; i < src_size; i++)
			this -> _arr[i] = src[i];
	}
	return *this;
}


template <typename T>
T const & Array<T>::operator[](unsigned int i) const
{
	if (i >= (this -> _size))
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
