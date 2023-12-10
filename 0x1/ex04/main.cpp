/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:00:13 by afatimi           #+#    #+#             */
/*   Updated: 2023/12/10 19:02:21 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<fstream>
#include<sstream>

std::string replace_at_home( std::string buffer, std::string s1, std::string s2 )
{
	size_t needle_index;
	std::string result;
	std::string rest;

	if (buffer.find(s1) == std::string::npos || buffer.empty() || s1.empty() || s2.empty())
		return (buffer);
	if (buffer.find(s1) != std::string::npos)
	{
		needle_index = buffer.find(s1);
		result = buffer.substr(0, needle_index);
		result += s2;
 		rest = buffer.substr(needle_index + s1.size(), std::string::npos);
	}
	else
		result = buffer;
	return (result + replace_at_home(rest, s1, s2));
}

int main(int argc, char *argv[])
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string old_string, new_string;
	std::string input, output;
	std::stringstream file_buff;

	if (argc != 4)
	{
		std::cerr << "Usage: input old_string new_string" << std::endl;
		return (-1);
	}

	input = argv[1];
	output = input + ".replace";
	old_string = argv[2];
	new_string = argv[3];

	ifs.open(input.c_str(), std::ifstream::in);
	if (!ifs.is_open())
	{
		std::cerr << "couldn't open " << input << std::endl;
		return (-1);
	}

	ofs.open(output.c_str(), std::ofstream::out);
	if (!ofs.is_open())
	{
		std::cerr << "couldn't open " << output << std::endl;
		ifs.close();
		return (-1);
	}

	file_buff << ifs.rdbuf();
	ofs << replace_at_home(file_buff.str(), old_string, new_string);

	ifs.close();
	ofs.close();
	return (0);
}
