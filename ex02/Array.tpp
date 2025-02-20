#include "Array.hpp"

template <typename T>
Array<T>::Array() {
	this->_array = new T[0];
	this->_size = 0;
	std::cout << "Default constructor called" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) {
	this->_array = new T[n];
	this->_size = n;
	std::cout << "Param constructor called" << std::endl;
}

template <typename T>
Array<T>::~Array() {
	delete[] this->_array;
	std::cout << "Destructor called" << std::endl;
}

template <typename T>
Array<T>::Array(const Array& copy) {
	this->_array = new T[copy._size];
	this->_size = copy._size;
	for (unsigned int i = 0; i < _size; i++)
		this->_array[i] = copy._array[i];
	std::cout << "Copy constructor called" << std::endl;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	if (this != &copy)
	{
		if (this->_array)
			delete[] this->_array;
		this->_array = new T[copy._size];
		this->_size = copy._size;
		for (unsigned int i = 0; i < _size; i++)
			this->_array[i] = copy._array[i]; 
		std::cout << "Copy assignment constructor called" << std::endl;
	}
	return *this;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= this->_size)
		throw IndexOutOfBounds();
	else
		return (this->_array[index]);
}

template <typename T>
unsigned int Array<T>::size(void)
{
	return this->_size;
}

template <typename T>
const char* Array<T>::IndexOutOfBounds::what() const noexcept {
	return ("Error. Index is out of bounds");
}