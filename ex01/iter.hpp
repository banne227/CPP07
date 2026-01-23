//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : iter.hpp                                     #
//#   Created : 2026-01-23 18:41                             #
//#   Updated : 2026-01-23 18:41                             #
//#                                                          #
//############################################################

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <stdexcept>
#include <string.h>

template <typename T> void iter(T* array, size_t length, void (*func)(T&))
{
	if (!array || length == 0 || !func)
		throw std::invalid_argument("Invalid argument(s) provided to iter function.");

	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

template <typename T> void iter(const T* array, size_t length, void (*func)(const T&))
{
	if (!array || length == 0 || !func)
		throw std::invalid_argument("Invalid argument(s) provided to iter function.");

	for (size_t i = 0; i < length; ++i)
	{
		func(array[i]);
	}
}

#endif