#include<iostream>

void print_upper(char *str)
{
	int		i = 0;
	char	c;

	if (!str)
		return;

	while (str[i])
	{
		c = str[i++];
		if (islower(c))
			c = (char)toupper(c);
		std::cout << c;
	}
}

int main(int argc, char **argv)
{
	int		i;

	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	i = 1;
	std::cin.width(0x100);
	while (i < argc)
		print_upper(argv[i++]);
	std::cout << std::endl;
}
