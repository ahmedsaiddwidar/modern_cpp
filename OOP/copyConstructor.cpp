/*
- copy constructor is a special constructor that create a new object by copying an existing object.

its syntax is => (classname(const classname &))
- it is used when initialize an object from other
myclass a;
myclass b = a; // copy constructor called

- it is used also when pasing an object be value
void func(myclass a); //  copy constructor called when you pass

- it is used also when returning an object by value
myclass getclass(){
    myclass temp;
    return temp;  // copy constructor OR move constructor may be called
}

- but what happens in the memory exactly??????

it copies all non static members in the source object inside into new object./
if you do not define one the compiler will give you a default shallow copy /
which copies the daya bit by bit including pointers(just addresses)
*/
// -----------------------------------------------------------------------------------
// Shallow Copy (default behavior):

// - Copies the pointer, not the data it points to.

// - Both objects now point to the same memory.

// class shallow{
//     public:
//     int *data;

//     shallow(int val){
//         data = new int (val);

//     }

//     ~shallow() {
//         delete data;
//     }
// };
// -----------------------------------------------------------------------------------

// class deep{
//     public:
//     int * data;

//     deep(int val){
//         data new int;
//     }

//     deep(const& deep other){
//         data = new int (*other.data);
//     }
//     ~deep(){
//         delete data;
//     }
// };
// ------------------------------------------------------------------------------------
// The compiler auto-generates a copy constructor if:

//     You don’t define any yourself.

//     It performs a member-wise copy (shallow).

// class Point {
// public:
//     int x, y;
//     // compiler-generated copy constructor does: x = other.x; y = other.y;
// };

// #include <iostream>
// #include<cstring>

// class person{
//     private:
//     char *name;

//     public:

//     person(const char* input){
//         name = new char[ (strlen(input) ) + 1];
//         strcpy(name,input);

//         std::cout<< "Constructor called for: " << name << std::endl;
//     }

//     person(const person& other){
//         name = new char[ (strlen(other.name) ) + 1];

//         strcpy(name,other.name);

//         std::cout << "Copy constructor called for: " << name << std::endl;
//     }

//     void show() {
//         std::cout << "Name: " << name << std::endl;
//     }

//     ~person() {
//         std::cout << "Destructor called for: " << name << std::endl;
//         delete[] name;
//     }
// };

// int main(){

//     person p1("ahmed");
//     person p2 = p1;

//     p1.show();
//     p2.show();
// //Destructor is called once per object — totally normal and good!
// //You created two objects, so you get two destructor calls.
// }

#include<iostream>
#include<functional>

template <typename T>

class processor{
    private:

    T value;
    std::function<void (T)>action;

    public:

    processor(T val, std::function<void (T)>func)
    :value(val), action(func){
        std::cout<<"parmatrized constructor is called\n";
    }

    processor(const processor& other)
    :value(other.value), action(other.action){
        std::cout<<"copy constructor is called\n";

    }
    //execute the stored lambda
    void run() const{
        action(value);
    }
};

int main(){

    processor<int> p1(42, [](int x){
        std::cout << "Lambda says: value is " << x << "\n";
    });

    p1.run();

    processor<int> p2 = p1;

    p2.run();
}
