#include "Array.hpp"
#include "Array.tpp"
#define NDEBUG
#include <cassert>

int main(void)
{
	std::cout << "\nTEST #1 - Construction with no parameter: Creates an empty array." << std::endl;
    Array<std::string> noParam;
    assert(noParam.size() == 0);

    std::cout << "\nTEST #2 - Construction with an unsigned int n as a parameter: ";
    std::cout << "Creates an array of n elements initialized by default" << std::endl;
    Array<std::string> origStringArray(11);
    assert(origStringArray.size() == 11);

    // std::cout << "\nTEST #2.5 - Tip: Try to compile int * a = new int(); then display *a." << std::endl;
    // int* a = new int();
    // std::cout << *a << std::endl;

    std::cout << "\nTEST #3 - Construction by copy and assignment operator." << std::endl;
    Array<std::string> copyStringArray(origStringArray);
    Array<std::string> newStringArray;
    newStringArray = copyStringArray;
    assert(copyStringArray.size() == 11);
    assert(newStringArray.size() == 11);

    std::cout << "\nTEST #4 - In both cases, modifying either the original array or its copy after copying musn't affect the other array." << std::endl;
    std::cout << "TEST #4.5 - Elements can be accessed through the subscript operator: [ ]." << std::endl;
    std::cout << "origStringArray[1] = " << origStringArray[1] << std::endl;
    std::cout << "newStringArray[1] = " << newStringArray[1] << std::endl;
    origStringArray[1] = "Bilbo Baggins";
    std::cout << "origStringArray[1] = " << origStringArray[1] << std::endl;
    std::cout << "newStringArray[1] = " << newStringArray[1] << std::endl;
    assert(origStringArray[1] == "Bilbo Baggins");
    assert(newStringArray[1] == "");

    std::cout << "\nTEST #5 - When accessing an element with the [ ] operator, if its index is out of bounds, an std::exception is thrown." << std::endl;
    try {
        std::cout << newStringArray[13] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\nTEST #6 - A member function size() that returns the number of elements in the array." << std::endl;
    std::cout << "size of newStringArray = " << newStringArray.size() << std::endl;
} 

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }