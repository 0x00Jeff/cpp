/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 19:53:34 by afatimi           #+#    #+#             */
/*   Updated: 2023/12/30 20:10:37 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"FragTrap.hpp"

FragTrap::FragTrap ( void ): ClapTrap("default")
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap default created!" << std::endl;
}

FragTrap::FragTrap ( std::string _name ) : ClapTrap(_name)
{
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap " << name << " created!" << std::endl;
}

FragTrap::FragTrap ( FragTrap const & src ) : ClapTrap(src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

FragTrap & FragTrap::operator=( FragTrap const & src )
{
	std::cout << "Copy assignment operator called" << std::endl;
	this -> name = src.name;
	this -> hit_points = src.hit_points;
	this -> energy_points = src.energy_points;
	this -> attack_damage = src.attack_damage;
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "positive high fives request hh" << std::endl;
}

FragTrap::~FragTrap ()
{
	std::cout << "FragTrap " << name << " destroyed!" << std::endl;
}
