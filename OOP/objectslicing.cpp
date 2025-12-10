// Object slicing occurs when a derived object is assigned to a base object by value, \
// causing the "extra" parts of the derived class to be sliced off
#include<iostream>

class Base {
public:
    int x = 1;
    virtual void show() const {
        std::cout << "Base x = " << x << "\n";
    }
};

class Derived : public Base {
public:
    int y = 2;
    void show() const override {
        std::cout << "Derived x = " << x << ", y = " << y << "\n";
    }
};

void print(Base b) {  // Pass-by-value: causes slicing ,we should use & or pointer
    b.show();
}

int main() {
    Derived d;
    print(d);  // object slicing happens here!
}

// print() takes a Base by value → only the Base part is copied

// The Derived part (y and its show()) is sliced off

// Solution: Use references or pointers to avoid slicing.

// void print(const Base& b) {  // No slicing!
//     b.show();
// }