//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : main.cpp                                     #
//#   Created : 2026-01-28 09:31                             #
//#   Updated : 2026-01-28 09:31                             #
//#                                                          #
//############################################################

#include "iter.hpp"

template <typename T>
void increment(T &x)
{
    x++;
}

template <typename T>
void print(const T &x)
{
    std::cout << x << " ";
}

int main()
{
    // Test  int array
    int arr[] = {1, 2, 3, 4, 5};
    size_t len = 5;

    std::cout << "Original int array: ";
    iter(arr, len, print<int>);
    std::cout << std::endl;

    iter(arr, len, increment<int>);

    std::cout << "After increment: ";
	iter(arr, len, print<int>);
    std::cout << std::endl << std::endl;

    // Test const tab
    const int constArr[] = {10, 20, 30};

    std::cout << "Const int array: ";
    iter(constArr, 3, print<int>);
    std::cout << std::endl << std::endl;

    // Test  std::string
    std::string strArr[] = {"Hello", "World", "42"};

    std::cout << "String array: ";
    iter(strArr, 3, print<std::string>);
    std::cout << std::endl << std::endl;

    std::cout << "Attempting to call iter with zero length..." << std::endl;
    try 
    {
        iter(strArr, 0, print<std::string>);
    } 
    catch (const std::exception &e) 
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
	return 0;
}
