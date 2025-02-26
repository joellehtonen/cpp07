#pragma once
#include <string>
#include <iostream>

template <typename T>
void iter(T* array, int len, void (*function)(T& param))
{
	if (!array || len < 0)
	{
		std::cerr << "Error. Pointer cannot be null and size cannot be less than 0\n";
		return ;
	}
	for (int i = 0; i < len; i++)
	{
		function(array[i]);
	}
};

template <typename T>
void iter(T* array, int len, void (*function)(const T& param))
{
	if (!array || len < 0)
	{
		std::cerr << "Error. Pointer cannot be null and size cannot be less than 0\n";
		return ;
	}
	for (int i = 0; i < len; i++)
	{
		function(array[i]);
	}
};

// THESE ARE FOR TESTING
template <typename T>void printBracket(T& param)
{
	std::cout << " [ " << param << " ] ";
};

template <typename T>void printBracketNewline(T& param)
{
	std::cout << " [ " << param << " ] " << "\n";
};
