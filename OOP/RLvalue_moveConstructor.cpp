// * L-value is the left value which has a name and memory location 

// int x = 10;
// x = 4; make sense it is already in the memory 


// r-value is the right value and it is a temporary value has no name and no memory location and can not be assigned to

// int y = 10 + 5; the right side of = is the R-value
// 30 = y; ERROR: 30 is an r-value, cannot assign to it

// to be able to capture the right value (temporary values) we need the R-Value Reference &&r

// int &&r = 10; bind r-value reference to temporary 10

// but Why Do We Need Move Constructors?

// if we have 
// class Person {
//     std::string name;
// public:
//     Person(std::string n) : name(n) {}
// };

// and simply do this 

// Person p1("Ahmed");
// Person p2 = std::move(p1);  


// Even though p1 is no longer needed, it still copies the string, which is wasteful.

// So we use the move constructor to "steal" the internal data instead of copying.

// Person(Person&& other) noexcept {
//     this->name = std::move(other.name);
// }

//     Person&& → r-value reference

//     std::move(...) → converts l-value to r-value

//     noexcept → tells compiler: "This won't throw" (helps optimization)
#include<iostream>
#include<string>

class person{
    std::string name;

    public:

    person(std::string m_name)
    :name(m_name){
        std::cout << "Constructor called for " << name << "\n";
    }

    person(const person& other){
        name = other.name;
        std::cout << "Copy constructor called for " << name << "\n";
    }

        person(const person&& other) noexcept{
        name = std::move(other.name);
        std::cout << "Move constructor called\n";        
    }

    void greet() const {
        std::cout << "Hi, I'm " << name << "\n";
    }

};

int main(){

    person p1("ahmed");

    person p2 = p1;

    person p3 = std::move(p1);

    p2.greet();
    p3.greet();
}
//p1 becomes empty after move. It's still valid but no longer holds the name.
┌──────┐       ┌──────┐       ┌──────┐
│ p1   │ —X→   │ "Ahmed" │   // moved-from
│ p2   │ ───→  │ "Ahmed" │
│ p3   │ ───→  │ "Ahmed" │
└──────┘       └──────┘       └──────┘
//p1 has released its ownership to p3.

 Common Pitfalls
Pitfall	Fix/Explanation
Forgetting std::move() ->	Defaults to copy
Modifying object after move ->	It's in "valid but unspecified" state
Returning local object by value ->	RVO applies → move constructor may be skipped

Advanced Tip: Rule of 5

If you define any of these, you should usually define all:

    Destructor

    Copy constructor

    Copy assignment

    Move constructor

    Move assignment


Person(const Person&);
Person& operator=(const Person&);
Person(Person&&);
Person& operator=(Person&&);
~Person();

#include <vector>
#include <iostream>

std::vector<int> createVector() {
    std::vector<int> v = {1, 2, 3};
    std::cout << "Returning vector...\n";
    return v;  // Move will happen here
}

int main() {
    std::vector<int> data = createVector(); // Move constructor
}

Compiler uses move constructor instead of copying — super efficient!

R-value -> 	Temporary object, no name
R-value reference-> 	T&&, lets us bind to r-values
Move constructor-> 	Transfers ownership,-> avoids expensive copy
std::move()-> 	Converts l-value to r-value
Rule of 5-> 	Best practice when managing resources manually