#include"iter.hpp"

template <typename T>
void display_arr(T arr, size_t arr_len)
{
	size_t i;
	for(i = 0; i < arr_len; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template <typename T>
void add_one(T arr, size_t arr_len)
{
	size_t i;
	for(i = 0; i < arr_len; i++)
		arr[i] += 5;
}

void inc_elem(double &elem)
{
	elem++;
}

template <typename T>
void inc_elem_template(T &elem)
{
	elem++;
}

int main(void)
{
	double arr[] = {1.1,2.2,3.3,4.4};
	iter(arr, sizeof(arr) / sizeof(arr[0]), inc_elem);
	display_arr(arr, sizeof(arr) / sizeof(arr[0]));
	iter(arr, sizeof(arr) / sizeof(arr[0]), inc_elem_template<double>);
	display_arr(arr, sizeof(arr) / sizeof(arr[0]));
}
