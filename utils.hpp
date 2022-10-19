#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include "_colors.hpp"

# define CCOUT(color, x) std::cout << color << x << CRESET << std::endl;
# define COUT(x) std::cout << x << std::endl;
# define EXCEPTION(x, y) public: class x : public std::exception { const char * what (void) const throw { return y; } }

#endif