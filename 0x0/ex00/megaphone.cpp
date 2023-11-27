#include <iostream>

void	print_upper(std::string str)
{
	int		i;

	i = 0;
	if (str.empty())
	{
		std::cout << "empty string !" << std::endl;
		return ;
	}
	while (str[i])
		std::cout << (char) toupper(str[i++]);
}

int	main(int argc, char **argv)
{
	int	i;
	std::string arg;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		arg = argv[i++];
		print_upper(arg);
	}
	std::cout << std::endl;
}
