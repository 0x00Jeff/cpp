#include"AAnimal.hpp"
#include"WrongAnimal.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"
#include"Dog.hpp"

#define ANIMALS_NUM 10
#define ANIMALS_HALF (ANIMALS_NUM >> 1)

void check_leaks()
{
	system("leaks Animals");
}

int main()
{
	atexit(check_leaks);
	const AAnimal *(animals[ANIMALS_NUM]);

	for(int i = 0; i < ANIMALS_HALF; i++)
		animals[i] = new Cat();
	std::cout << std::endl;

	for(int i = 0; i < ANIMALS_HALF; i++)
		animals[ANIMALS_HALF + i] = new Dog();
	std::cout << std::endl;

	for(int i = 0; i < ANIMALS_NUM; i++)
		delete animals[i];
}
