#include "iter.hpp"
#include <cmath>
#include <stdexcept>
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"
#define BOLD "\033[1m"

static void multiplyByTwo(int& i)
{
	i *= 2;
}

static void capitalize(char& c)
{
	c = std::toupper(c);
}

static void nextChar(char& c)
{
	c = c + 1;
}

static void floorFloat(float& f)
{
	f = floor(f);
}

static void addOneHundrethDecimal(float& f)
{
	f += 0.001;
}

static void ceilFloat(float& f)
{
	f = ceil(f);
}


static void replaceFirstVowel(std::string& string)
{
	int pos = string.find_first_of("aeioyuAEIOYU");
	if (pos >= 0)
	{
		string.erase(pos, 1);
		string.insert(pos, "?");
	}
}

int main(void)
{

	int		intArray[] = {0, 1, 2, 3, 4, 5};
	size_t	len1 = sizeof(intArray) / sizeof(int);

	std::cout << RED << "---INT TEST---\n";
	::iter<int>(intArray, len1, printBracket<int>);
	std::cout << std::endl;
	::iter<int>(intArray, len1, multiplyByTwo);
	::iter<int>(intArray, len1, printBracket);
	std::cout << std::endl;
	::iter<int>(intArray, len1, multiplyByTwo);
	::iter<int>(intArray, len1, printBracket);
	std::cout << RESET << std::endl;

	std::cout << "\n---TEST WITH NULLPTRS---\n";
	::iter<int>(nullptr, len1, multiplyByTwo);
	::iter<int>(intArray, len1, nullptr);
	std::cout << RESET << std::endl;

	char charArray[] = {'a', 'b', 'c'};
	size_t	len2 = sizeof(charArray) / sizeof(char);

	std::cout << GREEN << "---CHAR TEST---\n";
	::iter<char>(charArray, len2, printBracket);
	std::cout << std::endl;
	::iter<char>(charArray, len2, capitalize);
	::iter<char>(charArray, len2, printBracket);
	std::cout << std::endl;
	::iter<char>(charArray, len2, nextChar);
	::iter<char>(charArray, len2, printBracketNewline);
	

	float floatArray[] = {1.3, 2.5, 3.9};
	size_t	len3 = sizeof(floatArray) / sizeof(float);

	std::cout << PURPLE << BOLD << "---FLOAT TEST---\n";
	::iter<float>(floatArray, len3, printBracket);
	std::cout << std::endl;
	::iter<float>(floatArray, len3, floorFloat);
	::iter<float>(floatArray, len3, printBracket);
	std::cout << std::endl;
	::iter<float>(floatArray, len3, addOneHundrethDecimal);
	::iter<float>(floatArray, len3, printBracket);
	std::cout << std::endl;
	::iter<float>(floatArray, len3, ceilFloat);
	::iter<float>(floatArray, len3, printBracket);
	std::cout << RESET << std::endl;

	std::string stringArray[] = {"hello", "world"};
	size_t	len4 = sizeof(stringArray) / sizeof(std::string);

	std::cout << CYAN << BOLD << "---STRING TEST---\n";
	::iter<std::string>(stringArray, len4, printBracket);
	std::cout << std::endl;
	::iter<std::string>(stringArray, len4, replaceFirstVowel);
	::iter<std::string>(stringArray, len4, printBracketNewline);
}