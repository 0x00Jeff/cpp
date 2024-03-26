#pragma once
#include<algorithm>
#include<iterator>
#include<exception>

class Elem_Not_Found : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "Element not found";
		}
};

template <typename T>
void easyfind(T & container, int target)
{
	typename T::iterator found;
	found = std::find(container.begin(), container.end(), target);
	if (found == container.end())
		throw Elem_Not_Found();
}
