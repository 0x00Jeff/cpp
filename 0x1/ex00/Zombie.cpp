/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:28:11 by afatimi           #+#    #+#             */
/*   Updated: 2023/11/30 21:40:14 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Zombie.hpp"
#include<iostream>

Zombie::Zombie ( void )
{
	std::cout << "Zombie created!" << std::endl;
}

Zombie::~Zombie ( void )
{
	std::cout << "Zombie destroyed!" << std::endl;
}

void Zombie::annouce( void )
{
	std::cout << get_name() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name( void )
{
	return (this -> name);
}

void Zombie::set_name( std::string name )
{
	this -> name = name;
}
