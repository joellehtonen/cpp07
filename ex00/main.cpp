#include "whatever.hpp"
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

int main( void ) {

	{
		std::cout << "\n---TEST #1 (from the subject)---\n";
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	{
		std::cout << "\n---TEST #2---\n";
		std::cout << "\nwith doubles\n";
		double 	a = 1.001;
		double	b = 2.001;
		std::cout << "BEFORE swap: a = " << a << ", b = " << b << std::endl;
		::swap(a, b);
		std::cout << "AFTER swap: a = " << a << ", b = " << b << std::endl;
		std::cout << "min = " << ::min(a, b) << std::endl;
		std::cout << "max = " << ::max(a, b) << std::endl;

		std::cout << "\n---TEST #3---\n";
		std::cout << "\nwith double pointers\n";
		double* a1 = new double(1.1);
		double*	b1 = new double(1.2); 
		std::cout << "memory location of the pointers themselves\n";
		std::cout << "a = " << RED << &a1 << RESET << ", b = " << GREEN << &b1 << RESET << std::endl;
		std::cout << "memory they are pointing to\n";
		std::cout << "a = " << RED << a1 << RESET << ", b = " << GREEN << b1 << RESET << std::endl;
		std::cout << "content in that memory\n";
		std::cout << "a = " << RED << *a1 << RESET << ", b = " << GREEN << *b1 << RESET << std::endl;
		::swap(a1, b1);
		std::cout << "\nSWAP\n\n";
		std::cout << "memory location of the pointers themselves\n";
		std::cout << "a = " << RED << &a1 << RESET << ", b = " << GREEN << &b1 << RESET << std::endl;
		std::cout << "memory they are pointing to\n";
		std::cout << "a = " << GREEN << a1 << RESET << ", b = " << RED << b1 << RESET << std::endl;
		std::cout << "content in that memory\n";
		std::cout << "a = " << GREEN << *a1 << RESET << ", b = " << RED << *b1 << RESET << std::endl;
		std::cout << "min = " << RED << ::min(*a1, *b1) << RESET << std::endl;
		std::cout << "max = " << GREEN << ::max(*a1, *b1) << RESET << std::endl;
		delete a1;
		delete b1;

		std::cout << "\n---TEST #4---\n";
		std::cout << "\nwith 'double' double pointers\n";
		double**	a2 = new double*;
		double**	b2 = new double*; 
		*a2 = new double(2.1);
		*b2 = new double(-2.2);
		std::cout << "memory locations of the double pointers themselves\n";
		std::cout << "a = " << BLUE << &a2 << RESET << ", b = " << CYAN << &b2 << RESET << std::endl;
		std::cout << "memory they are pointing to\n";
		std::cout << "a = " << BLUE << a2 << RESET << ", b = " << CYAN << b2 << RESET << std::endl;
		std::cout << "content in that memory (another pointer)\n";
		std::cout << "a = " << BLUE << *a2 << RESET << ", b = " << CYAN << *b2 << RESET << std::endl;
		std::cout << "content in that memory (value pointed to by the second pointer)\n";
		std::cout << "a = " << BLUE << **a2 << RESET << ", b = " << CYAN << **b2 << RESET << std::endl;
		::swap(a2, b2);
		std::cout << "\nSWAP\n\n";
		std::cout << "memory location of the double pointers themselves\n";
		std::cout << "a = " << BLUE << &a2 << RESET << ", b = " << CYAN << &b2 << RESET << std::endl;
		std::cout << "memory they are pointing to\n";
		std::cout << "a = " << CYAN << a2 << RESET << ", b = " << BLUE << b2 << RESET << std::endl;
		std::cout << "content in that memory (another pointer)\n";
		std::cout << "a = " << CYAN << *a2 << RESET << ", b = " << BLUE << *b2 << RESET << std::endl;
		std::cout << "content in that memory (value pointed to by the second pointer)\n";
		std::cout << "a = " << CYAN << **a2 << RESET << ", b = " << BLUE << **b2 << RESET << std::endl;
		std::cout << "min = " << CYAN << ::min(**a2, **b2) << RESET << std::endl;
		std::cout << "max = " << BLUE << ::max(**a2, **b2) << RESET << std::endl;
		delete *a2;
		delete *b2;
		delete a2;
		delete b2;
	}
}