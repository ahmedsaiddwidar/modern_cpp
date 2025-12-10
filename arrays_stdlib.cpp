- is a safer, more flexible alternative to traditional C-style static arrays. \
It provides the benefits of static arrays with added type safety and better \
integration with the Standard Template Library (STL).

#include <array>

std::array<int, 5> numbers = {1, 2, 3, 4, 5};

/*
td::array is a container that encapsulates fixed-size arrays with the semantics of a C++ container. \
Introduced in C++11, it's a safer and more versatile replacement for built-in C-style arrays.

The best practice is to prefer std::array over C-style arrays whenever you need a fixed-size sequence of elements \
whose size is known at compile time.

*/


