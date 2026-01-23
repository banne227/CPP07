//############################################################
//#                                                          #
//#   ██████╗ ██████╗ ███╗   ██╗                             #
//#   ██╔══██╗╚════██╗████╗  ██║                             #
//#   ██████╔╝ █████╔╝██╔██╗ ██║                             #
//#   ██╔══██╗██╔═══╝ ██║╚██╗██║                             #
//#   ██████╔╝███████╗██║ ╚████║                             #
//#   ╚═════╝ ╚══════╝╚═╝  ╚═══╝                             #
//#                                                          #
//#   File    : whatever.hpp                                 #
//#   Created : 2026-01-23 17:37                             #
//#   Updated : 2026-01-23 17:37                             #
//#                                                          #
//############################################################

#ifndef WHATEVER_HPP
#define WHATEVER_HPP


#include <iostream>
#include <string.h>

template <typename T> void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <typename T> T& min(T& a, T& b)
{
	if (a < b)
		return (a);
	return (b);
}

template <typename T> T& max(T& a, T& b)
{
	if (a > b)
		return (a);
	return (b);
}

#endif