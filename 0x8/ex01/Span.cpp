/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 01:14:08 by afatimi           #+#    #+#             */
/*   Updated: 2024/04/03 01:27:41 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Span.hpp"
#include<iostream>
#include<climits>

Span::Span(){}

Span::Span( const unsigned int n ) : size(0), capacity(n), sorted(true)
{
	std::cout << "created a vector with size == " << n << std::endl;
}

Span::Span( Span const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Span & Span::operator=( Span const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
	{
		this -> v = src.v; // TODO : deep copy ? ask youssef about this!
		this -> size = src.getSize();
		this -> capacity = src.getCapacity();
	}
	return *this;
}

// getters
size_t Span::getSize( void ) const
{
	return (this -> size);
}

size_t Span::getCapacity( void ) const
{
	return (this -> capacity);
}

// class functionalities
void Span::addNumber(unsigned int number)
{
	if (this -> size == this -> capacity)
		throw Span_Is_Full();
	v.push_back(number);
	this -> size++;
	this -> sorted = false;
}

void addNumber( std::vector<int>::iterator it, std::vector<int>::iterator ite )
{
	(void)it;
	(void)ite;
	// TODO : impl
}

int Span::shortestSpan( void )
{
	if (this -> size < 2)
		throw Span_Has_Less_Then_Two_Elements();
	int smol_span = INT_MAX;

	std::vector<int> &v = this -> v;
	if (!this -> sorted)
	{
		sort(v.begin(), v.end(), std::greater<int>());;
		this -> sorted = true;
	}
	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();

	for (; (it + 1) != ite; it++)
	{
		if ((*it - *(it + 1)) < smol_span)
			smol_span = (*it - *(it + 1));
	}

	return (smol_span);
}

int Span::longestSpan( void )
{
	if (this -> size < 2)
		throw Span_Has_Less_Then_Two_Elements();
	std::vector<int> &v = this -> v;

	if (!this -> sorted)
	{
		sort(v.begin(), v.end(), std::greater<int>());
		this -> sorted = true;
	}

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();
	return (*it - *--ite);
}

// exceptions
const char *Span::Span_Is_Full::what() const throw()
{
	return "Span is full!";
}

const char *Span::Span_Has_Less_Then_Two_Elements::what() const throw()
{
	return "Span has less than two elements!";
}

Span::~Span( void )
{
	std::cout << "deleted vector" << std::endl;
}
