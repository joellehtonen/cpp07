#pragma once
#include <string>
#include <iostream>

template <typename T>void iter(T* array, size_t len, void (*function)(T& param))
{
	for (size_t i = 0; i < len; i++)
	{
		function(array[i]);
	}
};

template <typename T>void printBracket(T& param)
{
	std::cout << " [ " << param << " ] ";
};

