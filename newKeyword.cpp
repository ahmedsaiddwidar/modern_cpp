new keyword
- the new keyword is used to dynamically allocate memory on the heap for variables, arrays, or objects during runtime. \
This allows for greater control over memory usage and is especially useful when the amount of memory required is not known at compile time.

int* ptr = new int; // Allocates memory for an integer
*ptr = 42;          // Sets the value of the allocated integer to 42

std::cout << *ptr << std::endl; // Output: 42

delete ptr; // Free the memory when done

-----------------------------------------------------------------

entity *ptr = new entity; // Allocates an array of 1 entity objects on the heap.

entity *ptr = new entity[5]; //Allocates an array of 5 entity objects on the heap.

-------------------------------------------------------------------

int* arr = new int[5]; // Allocates memory for an array of 5 integers

for (int i = 0; i < 5; ++i) {
    arr[i] = i * 2;    // Initializes array elements
}

for (int i = 0; i < 5; ++i) {
    std::cout << arr[i] << " "; // Output: 0 2 4 6 8
}
std::cout << std::endl;

delete[] arr; // Free the array memory when done

---------------------------------------------------------------------------
#include <iostream>

class myclass{
    public:
    int value;

    myclass(int val)
    : value(val)
    {}
};
int main(){
    myclass *obj = new myclass(10);

    delete obj;
}

*ptr = new int (21);

struct point{
    int x;
    int y;
};
point *ptr = new point(10,20);   // Allocates and initializes a Point object

*p = new int;

*p = 23;

int *arr = new int[5];          // Allocates an array of 5 ints

int *a = new int[5]{1,2,3,4,5};

class point{
    public:

    int x;
    int y;

    point() : x(2), y(4){}
};

    point *points = new point[3];   // Allocates an array of 3 Points, each with default values

auto ptr = new int(42);       // ptr is automatically deduced as `int*`


