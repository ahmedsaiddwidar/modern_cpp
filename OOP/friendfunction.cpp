friend function is not a member of the class but has access to its private and protected members.

#include <iostream>

class Box {
private:
    double width;

public:
    Box(double w) : width(w) {}

    // Friend function declaration
    friend void printWidth(const Box& b);
};

// Friend function definition
void printWidth(const Box& b) {
    std::cout << "Width: " << b.width << "\n";
}

int main() {
    Box b(5.5);
    printWidth(b);
}

✅ Use Cases:

    Overloading <<, >>

    Binary operators where left operand isn’t a class

    Grant access without breaking encapsulation

Key Notes:

    Declare as friend inside the class

    Defined like a normal function

    Not inherited by derived classes