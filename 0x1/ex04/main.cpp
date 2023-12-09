/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afatimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 02:00:13 by afatimi           #+#    #+#             */
/*   Updated: 2023/12/09 03:18:43 by afatimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>
#include<fstream>

std::string line_replace( std::string line, std::string s1, std::string s2 )
{
	size_t needle_index;
	std::string result;

	if (s1.find(s2) == std::string::npos)
		return (s1);
	while (s1.find(s2) != std::string::npos)
	{
		needle_index = s1.find(s2);
		result = line.substr(0, needle_index);
		result += s2;
 		result += line.substr(needle_index + s2.size(), std::string::npos);
	}
	return (result);
}

void replace_at_home( std::ifstream& ifs, std::ofstream& ofs, std::string old_string, std::string new_string)
{
	(void)new_string;
	(void)ofs;
	std::string line;
	while (ifs.good())
	{
		std::getline(ifs, line);
		std::cout << line << " -> " << line_replace(line, old_string, new_string) << std::endl;
		if (!ifs.good())
		   	std::cout << std::endl;
	}
}

int main(int argc, char *argv[])
{
	std::ifstream ifs;
	std::ofstream ofs;
	std::string old_string, new_string;
	std::string input, output;
	std::string line;

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

	replace_at_home(ifs, ofs, old_string, new_string);

	ifs.close();
	ofs.close();
}
