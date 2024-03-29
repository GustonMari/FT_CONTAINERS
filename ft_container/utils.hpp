#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "_colors.hpp"

# define CCOUT(color, x) std::cout << color << x << CRESET << std::endl;
# define COUT(x) std::cout << x << std::endl;
# define EXCEPTION(x, y) public: class x : public std::exception { const char * what (void) const throw { return y; } }
# define P_TAB(x) print_tab(x);
# define P_TABC(color, x) print_tab_color(x, color);
# define ENABLE_IF(x) typename ft::enable_if<!ft::is_integral<x>::value, x >::type
# define LOG( message ) logError( __LINE__, message );
# define BLACK 0
# define RED 1

void logError (int line, const std::string& message)
{
	std::cerr << "[" << line << "]" << message << std::endl;
}

template <typename T>
void print_tab(T & x)
{
	for (typename T::iterator it = x.begin();it != x.end(); it++) 
	{
		std::cout << *it << std::endl;
	}
}

template <typename T, typename Color>
void print_tab_color(T & x, Color & color)
{
	for (typename T::iterator it = x.begin();it != x.end(); it++) 
	{
		std::cout << color << *it << CRESET << std::endl;
	}
}

#endif