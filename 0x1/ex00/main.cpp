#include"Zombie.hpp"

Zombie *newZombie( std::string name);
void randomChump( std::string name );

int main(void)
{
	Zombie z;
	z.set_name("kek");
	z.annouce();
	Zombie *z_ptr = newZombie("jeff");
	z_ptr -> annouce();
	delete z_ptr;
	randomChump("jeffy");
}
