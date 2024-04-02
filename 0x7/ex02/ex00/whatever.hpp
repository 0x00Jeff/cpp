/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 23:38:04 by afatimi           #+#    #+#             */
/*   Updated: 2024/03/26 22:04:37 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

template <typename T>
void swap(T &a, T &b)
{
	//std::cout << "swap calling the normal template! :(" << std::endl;
	T tmp = a;
	a = b;
	b = tmp;
}

template <>
inline void swap(int &a, int &b)
{
	//std::cout << "swap calling the specialized template!" << std::endl;
	if (a == b)
		return;
	a ^= b;
	b ^= a;
	a ^= b;
}


template <typename T>
T max(T a, T b)
{
	//std::cout << "max calling the normal template! :(" << std::endl;
	return (a >= b ? a : b);
}

template <>
inline int max(int a, int b)
{
	//std::cout << "max calling the specialized template!" << std::endl;
	return (a * (a >= b) + b * (b > a));
}


template <typename T>
T  min(T const &a, T const &b)
{
	//std::cout << "min calling the normal template! :(" << std::endl;
	return (a <= b ? a : b);
}

template <>
inline int min(int const &a, int const &b)
{
	//std::cout << "min calling the specialized template!" << std::endl;
	return (b * (a >= b) + a * (b > a));
}
