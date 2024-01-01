/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 23:49:04 by afatimi           #+#    #+#             */
/*   Updated: 2024/01/01 23:49:20 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Dog.hpp"

Dog::Dog( void ) : AAnimal("Dog")
{
	std::cout << "default Dog Constructor called" << std::endl;
	this -> b = new Brain();
}

Dog::Dog ( Dog const & src ) : AAnimal(src)
{
	std::cout << "Copy constructor called" << std::endl;
	this -> b = new Brain(*(src.getBrain()));
}

Dog & Dog::operator=( Dog const & src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if ( this != &src)
	{
		if (this -> b)
			delete b;
		this -> b = new Brain(*(src.getBrain()));
	}
	return *this;
}

void Dog::makeSound( void ) const
{
	std::cout << "Bark Bark!" << std::endl;
}

Brain* Dog::getBrain( void ) const
{
	return (this -> b);
}

Dog::~Dog( void )
{
	std::cout << "Dog Destructor called" << std::endl;
	if (this->b)
		delete (this -> b);
}
