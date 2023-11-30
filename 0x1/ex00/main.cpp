#include"Zombie.hpp"

Zombie *newZombie( std::string name)
{
	Zombie* z;

	z = new Zombie();
	z -> set_name(name);
	return (z);
}

void randomChump( std::string name )
{
	Zombie z;

	z.set_name(name);
	z.annouce();
}

int main(void)
{
	Zombie z;
	z.set_name("kek");
	z.annouce();
	Zombie *z_ptr = newZombie("jeffy");
	z_ptr -> annouce();
	delete z_ptr;
	randomChump("jeffy");
}
