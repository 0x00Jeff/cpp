#include"Animal.hpp"
#include"WrongAnimal.hpp"
#include"Cat.hpp"
#include"WrongCat.hpp"
#include"Dog.hpp"

int main()
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	const WrongAnimal* wrong_animal = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();
	const WrongAnimal* wrong_catto = new WrongCat();

	std::cout << std::endl;

	std::cout << animal->getType() << " " << std::endl;
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	std::cout << wrong_animal->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	std::cout << wrong_catto->getType() << " " << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	cat->makeSound(); //will output the cat sound!
	dog->makeSound();
	wrong_animal->makeSound();
	wrong_cat->makeSound();
	wrong_catto->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	delete wrong_animal;
	delete wrong_cat;
	delete wrong_catto;

	return 0;
}
