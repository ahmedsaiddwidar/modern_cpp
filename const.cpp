constants 
- with variables means the var is not modifiable
- with pointers
1- before * means the context is not modifiable

const int* ptr = &x; // ptr points to a constant int; *ptr cannot be modified

int y = 10;
ptr = &y;            // ptr can point to another variable
*ptr = 15;           // Error: cannot modify the value through ptr

2- after * means the pointer will not  move

int z = 20;
int* const ptr2 = &z; // ptr2 is a constant pointer to an int

*ptr2 = 25;           // Allowed: modifying the value through the pointer
int w = 30;
ptr2 = &w;            // Error: cannot change the address that ptr2 points to

3 - before and after 
const int* const ptr3 = &x;

- with classes methods used with get and print functions which means this function will mot attempt to modify any member variables

class MyClass {
private:
    int value;

public:
    int getValue() const { // const after the method name
        return value;      // Allowed: only reading the member variable
    }

    void setValue(int val) {
        value = val;       // Allowed: modifying the member variable
    }
};