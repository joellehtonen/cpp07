#include "iter.hpp"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"

static void multiplyByTwo(int& i)
{
	i *= 2;
}

static void capitalize(char& c)
{
	c = std::toupper(c);
}

int main(void)
{
	int		intArray[] = {0, 1, 2, 3, 4, 5};
	size_t	len1 = sizeof(intArray) / sizeof(int);

	std::cout << RED;
	::iter<int>(intArray, len1, printBracket<int>);
	std::cout << std::endl;
	::iter<int>(intArray, len1, multiplyByTwo);
	::iter<int>(intArray, len1, printBracket);
	std::cout << std::endl;
	::iter<int>(intArray, len1, multiplyByTwo);
	::iter<int>(intArray, len1, printBracket);
	std::cout << RESET << std::endl;

	char charArray[] = {'a', 'b', 'c'};
	size_t	len2 = sizeof(charArray) / sizeof(char);

	std::cout << GREEN;
	::iter<char>(charArray, len2, printBracket);
	std::cout << std::endl;
	::iter<char>(charArray, len2, capitalize);
	::iter<char>(charArray, len2, printBracket);
	std::cout << RESET << std::endl;
}