#include<iostream>
template <typename arr_t, typename func_ptr_t>
void iter(arr_t arr, size_t size, func_ptr_t func_ptr)
{
	if (!func_ptr)
		return;
	size_t i;
	for(i = 0; i < size; i++)
		func_ptr(arr[i]);
}
