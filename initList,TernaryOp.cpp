initializer list 

- used to initialize class members in the constructor, in the same order as they are defined
class entity{
    public:
    int mX;
    int mY;
    entity(int xVal,int yVal)
    : mX(xVal),mY(yVal)
    {}
};

- It’s especially useful for initializing const members, references, and base class members, as well as for ensuring efficient initialization.

- Initializing Base Class Members: When a class inherits from a base class, \
the base class constructor must be called to initialize the base part of the derived object. \
An initializer list allows you to specify which base class constructor to call.

class Base {
public:
    Base(int x) { /* ... */ }
};

class Derived : public Base {
public:
    Derived(int x) : Base(x) {}  // Calls Base class constructor with x
};

---------------------------------------------------------------------------------------------------------------------------------

ternary operator

int a = 10;
int b = 20;
int max = (a > b) ? a : b;

std::cout << "The maximum value is: " << max << std::endl;