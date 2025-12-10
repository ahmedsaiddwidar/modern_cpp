// 1- implicit casting -> is an automatic conversion that the compiler performs when it deems the conversion safe.\
// it Happens without any explicit syntax from the programmer.and also \
// Limited to conversions where no data is lost or when the conversion is known to be safe.

// Examples:

//     Converting an int to a double.
//     Upcasting in inheritance (e.g., converting a derived class pointer to a base class pointer).
//     Certain built-in type promotions (like float to double).

// int a = 10;
// double b = a; // implicitly casts int to double

// note that!! -> Can sometimes lead to unexpected behavior if conversions occur implicitly in ways the programmer did not anticipate.

// 2- expicit casting -> s a forced type conversion that requires the programmer to specify the type conversion explicitly.\
// Necessary when implicit conversion is not allowed or not safe, or when the programmer wants \
// to override the compiler's default conversion.Explicit casting carries more risk, \
// as the programmer is taking responsibility for the conversion's safety.

// Syntax:

//     C-style cast: (type)expression
//     C++ casts: static_cast, dynamic_cast, const_cast, reinterpret_cast

// double d = 3.14;
// int i = static_cast<int>(d);

// class Base { };
// class Derived : public Base { };

// Base* b = new Derived();
// Derived* d = static_cast<Derived*>(b); // explicit downcasting

// C++ Cast Types:

//     1- static_cast: For safe conversions, such as between numeric types, or upcasting and downcasting in class hierarchies (without virtual inheritance).
//     2- dynamic_cast: Used with pointers or references to classes, allowing safe downcasting in polymorphic hierarchies (requires runtime type checking).
//     3- const_cast: Adds or removes const or volatile qualifiers.
//     4- reinterpret_cast: For low-level casts, often for pointer manipulation; generally unsafe and used sparingly.

// 1. static_cast

// static_cast is used for safe, well-defined conversions. It's often used for:

//     Converting between numeric types.
//     Upcasting and downcasting within a class hierarchy (when there's no virtual inheritance).
//     Converting pointers or references of compatible types.

#include <iostream>

int main() {
    // Example 1: Numeric conversion
    double pi = 3.14159;
    int truncatedPi = static_cast<int>(pi); // truncates double to int
    std::cout << "truncatedPi: " << truncatedPi << std::endl;

    // Example 2: Upcasting in inheritance (safe cast)
    class Base { public: virtual ~Base() = default; };
    class Derived : public Base {};

    Derived derived;
    Base* basePtr = static_cast<Base*>(&derived); // upcast from Derived* to Base*
    
    return 0;
}

// 2. dynamic_cast

// dynamic_cast is used for safe downcasting within polymorphic \
// (i.e., classes with at least one virtual function) hierarchies. \
// It performs runtime type checking and returns nullptr if the cast fails for pointers or throws std::bad_cast for references.

// #include <iostream>
// #include <typeinfo>

// class Base {
// public:
//     virtual ~Base() = default; // must have a virtual function for dynamic_cast to work
// };

// class Derived : public Base {
// public:
//     void speak() { std::cout << "I am Derived!" << std::endl; }
// };

// int main() {
//     Base* basePtr = new Derived(); // actually points to a Derived object

//     // Safe downcast from Base* to Derived* using dynamic_cast
//     Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
//     if (derivedPtr) {
//         derivedPtr->speak(); // Safe to call Derived-specific methods
//     } else {
//         std::cout << "Failed to cast Base* to Derived*" << std::endl;
//     }

//     delete basePtr;
//     return 0;
// }

// 3. const_cast

// const_cast is used to add or remove const (or volatile) qualifiers from a variable. \
// It’s often used in legacy code or when interfacing with APIs that require non-const arguments but operate on const data.

// #include <iostream>

// void printValue(int& val) { // accepts a non-const reference
//     std::cout << "Value: " << val << std::endl;
// }

// int main() {
//     const int x = 10;
//     printValue(const_cast<int&>(x)); // removes const qualifier from x

//     return 0;
// }

//     Note: Modifying a const variable after removing const with const_cast results in undefined behavior \
//     unless the variable was initially non-const.

// 4. reinterpret_cast

// reinterpret_cast is used for low-level casting, often for pointer type conversions. \
// It can be risky because it allows converting between incompatible types and doesn’t guarantee that the converted type is meaningful.

// #include <iostream>

// int main() {
//     int number = 65;
    
//     // Reinterpret int* as char* (treats memory of an integer as a character)
//     char* charPtr = reinterpret_cast<char*>(&number);
//     std::cout << "Reinterpreted value: " << *charPtr << std::endl; // might print 'A' (ASCII 65)

//     // Converting between unrelated pointer types
//     struct Foo { int a; };
//     struct Bar { double b; };

//     Foo foo;
//     Bar* barPtr = reinterpret_cast<Bar*>(&foo); // Unsafe conversion
//     std::cout << "Reinterpreted barPtr->b: " << barPtr->b << std::endl; // meaningless output

//     return 0;
// }

//     Note: reinterpret_cast is often only safe for certain low-level uses, \
//     such as bit manipulation or interfacing with hardware. Misuse can lead to undefined behavior.