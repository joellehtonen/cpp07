#pragma once
#include <string>
#include <iostream>
#include <exception>

template <typename T>
class Array {
	private:
		T* 				_array;
		unsigned int	_size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array& operator=(const Array& copy);
		~Array();

		unsigned int size();

		T& operator[](unsigned int index);

		class IndexOutOfBounds : public std::exception{
			public:
				virtual const char* what() const noexcept override;
		};
};