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
//#   Created : 2026-01-28 09:32                             #
//#   Updated : 2026-01-28 09:32                             #
//#                                                          #
//############################################################

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    std::cout << "=== Array Tests ===" << std::endl;
    std::cout << "\n[1] Creating Array<int> of size " << MAX_VAL << "..." << std::endl;
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    
    std::cout << "[2] Filling array with random values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    std::cout << "    First 5 values: " << numbers[0] << ", " << numbers[1] << ", " 
              << numbers[2] << ", " << numbers[3] << ", " << numbers[4] << std::endl;
    
    //SCOPE
    {
        std::cout << "[3] Testing copy constructor and assignment..." << std::endl;
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        std::cout << "    ✓ Copy successful" << std::endl;
    }

    std::cout << "[4] Verifying array integrity after copy..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    std::cout << "    ✓ All " << MAX_VAL << " values verified!" << std::endl;
    
    std::cout << "[5] Testing exception: negative index..." << std::endl;
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "    Exception caught: " << e.what() << '\n';
    }
    
    std::cout << "[6] Testing exception: out of bounds..." << std::endl;
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "    Exception caught: " << e.what() << '\n';
    }

    std::cout << "[7] Modifying array values..." << std::endl;
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    std::cout << "    New first 5 values: " << numbers[0] << ", " << numbers[1] << ", " 
              << numbers[2] << ", " << numbers[3] << ", " << numbers[4] << std::endl;
    
    delete [] mirror;//
    std::cout << "\n✅ All tests passed successfully!\n" << std::endl;
    return 0;
}