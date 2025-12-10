/*
delegation generally refers to delegating tasks from one function or object to another. \
There are two main contexts where the term "delegation" is commonly used:
1- constructor delegator
2- object delegetaion(forwarding)
*/


// 1- constructor delegator

// class MyClass {
//     int a, b;

// public:
//     MyClass() : MyClass(0, 0) { // Delegating constructor
//         std::cout << "Default constructor\n";
//     }

//     MyClass(int x, int y) : a(x), b(y) {
//         std::cout << "Parameterized constructor\n";
//     }
// };

// 2- object delegetaion(forwarding)

// class Engine {
// public:
//     void start() {
//         std::cout << "Engine started\n";
//     }
// };

// class Car {
//     Engine engine;

// public:
//     void start() {
//         engine.start(); // Delegation to the engine
//     }
// };
/*
->what are the practicale uses of delegation?
- avoid code duplication: If several constructors share some initialization logic, \
lets you write it once.
- You ensure that all objects are properly initialized through one constructor and \
Fewer bugs, easier debugging. 
- Many design patterns depend heavily on delegating behavior to another class or method.
- Complex classes can build simpler components by delegating work to helper constructors or objects.
*/
#include<iostream>

class user{
    std::string name;
    unsigned int age;

    public:
    user(std::string m_name, unsigned int m_age)
    : name(m_name), age(m_age){}

    user() : user("ahmed", 26){
        std::cout<<"the default name and age are both set"<<std::endl;
    }

    void print() {
        std::cout << name << ", Age: " << age << std::endl;
    }

};

int main(){

    user u1("mahmoud", 38);
    user u2;

    u1.print();
    u2.print();
}