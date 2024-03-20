#include"Serializer.hpp"

int main(void)
{
	Data d;
	d.name = "jeffy";
	d.age = 69;

	uintptr_t ptr = Serializer::serialize(&d);
	Data *data_ptr = Serializer::deserialize(ptr);

	std::cout << &d << std::endl;
	std::cout << data_ptr << std::endl;

	std::cout << data_ptr -> name << std::endl;
	std::cout << data_ptr -> age << std::endl;
}
