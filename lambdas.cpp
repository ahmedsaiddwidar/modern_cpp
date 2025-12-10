lambdas : 
- they improve coed readaility and mainatanability
- often used with sort libraries functions instead of function name in for_each
- used in gui apps as it produces a concise way to handle events
- asynch programming and mulyithreading context for callbacks and handlers
- keep it short , explicit and readability
- the allocation in memory happens in run time and as any other features in C++ \
are fully  type-checked by the compiler so as type safety
(This feature ensures type safety, preventing bugs and unexpected \
behavior related to type mismatches.)

[capture-clauses](parameters) -> return-type {body};

1- [capture_list]: Specifies which variables from the surrounding scope \
are accessible inside the lambda.
2- (parameters): Defines the input arguments to the lambda, \
like a regular function.
3 - return_type (optional): Specifies the return type of the lambda. \
If omitted, the compiler deduces it automatically.
4- Function body: The code to execute when the lambda is called.

#include <iostream>

int main() {
    auto greet = []() { std::cout << "Hello, Lambda!" << std::endl; };
    greet(); // Call the lambda function
    return 0;
}

1- Capture List

The capture list allows a lambda to access variables from its surrounding scope.
Types of Captures:

    By Value (=): Captures variables by making a copy.

int x = 10;
auto lambda = [x]() { std::cout << x << std::endl; }; // x is copied
lambda();

By Reference (&): Captures variables by reference, allowing the lambda to modify them.

int x = 10;
auto lambda = [&x]() { x += 5; };
lambda();
std::cout << x; // Output: 15

Mixed Capture: Capture some variables by value and others by reference.

int x = 10, y = 20;
auto lambda = [x, &y]() { std::cout << x << ", " << y << std::endl; y += 5; };
lambda();

Default Capture (= or &): Captures all variables in the surrounding scope either by value or by reference.

int x = 10, y = 20;
auto byValue = [=]() { std::cout << x << ", " << y << std::endl; };
auto byRef = [&]() { x += 5; y += 5; };

2- Parameter List

Lambdas can have parameters like regular functions:

auto add = [](int a, int b) { return a + b; };
std::cout << add(2, 3); // Output: 5

3- Return Type

Lambdas can specify the return type explicitly using ->. If omitted, the compiler deduces the type.

auto multiply = [](int a, int b) -> double {
    return a * b * 1.0;
};
std::cout << multiply(2, 3); // Output: 6.0

4- Using Lambdas in STL Algorithms

Lambdas are commonly used with Standard Template Library (STL) algorithms for concise, inline function definitions.
Example: Using std::for_each

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    }); // Output: 1 2 3 4 5

    return 0;
}
5- Stateful Lambdas

Lambdas can store captured values and maintain state:
#include<iostream>

int main() {
    int counter = 0;

    auto increment = [counter]() mutable { 
        return ++counter; 
    };

    std::cout << increment() << std::endl; // Output: 1
    std::cout << increment() << std::endl; // Output: 2

    std::cout<< counter<<std::endl;
}

    mutable: Allows modifying captured variables (by value) inside the lambda.

6- Lambdas and Threads

Lambdas are often used with threading APIs like std::thread:

#include <iostream>
#include <thread>

int main() {
    std::thread t([]() {
        std::cout << "Hello from thread!" << std::endl;
    });
    t.join(); // Wait for the thread to finish
    return 0;
}
7- Capturing this (C++11 and Later)

Lambdas can capture the this pointer to access members of the enclosing class.
Example: Capturing this

#include <iostream>

class MyClass {
    int value;

public:
    MyClass(int v) : value(v) {}

    void printValue() {
        auto lambda = [this]() { std::cout << "Value: " << value << std::endl; };
        lambda();
    }
};

int main() {
    MyClass obj(10);
    obj.printValue(); // Output: Value: 10
    return 0;
}

8- Capturing by Value of *this (C++20)

C++20 allows capturing *this by value, capturing the object itself instead of just the pointer:

auto lambda = [*this]() { /* Access members by value */ };

9- Explicit Template Parameters for Lambdas (C++20)

C++20 allows lambdas to have explicit template parameters, making them more versatile:

auto add = []<typename T>(T a, T b) {
    return a + b;
};

std::cout << add(2, 3) << std::endl;       // Output: 5
std::cout << add(2.5, 3.5) << std::endl;   // Output: 6.0

