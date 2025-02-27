#pragma once
#include <string>
#include <iostream>
#include <climits>

template <typename T>
void iter(T* array, size_t len, void (*function)(T& param))
{
	if (!array || !function)
		throw std::runtime_error("Pointer cannot be null");
	for (size_t i = 0; i < len; i++)
		function(array[i]);
};

template <typename T>
void iter(const T* array, size_t len, void (*function)(const T& param))
{
	if (!array || !function)
		throw std::runtime_error("Pointer cannot be null");
	for (size_t i = 0; i < len; i++)
		function(array[i]);
};
 
// FOR TESTS
template <typename T>
void printBracket(T& param)
{
	std::cout << " [ " << param << " ] ";
};

// FOR TESTS
template <typename T>
void printBracketNewline(T& param)
{
	std::cout << " [ " << param << " ] " << "\n";
};
