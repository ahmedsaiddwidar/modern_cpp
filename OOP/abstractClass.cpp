/*
a pure virtaul function:
A pure virtual function is a function declared in a base class that must be overridden /
in any derived class. It has no implementation in the base class.
*/

/*
its purposes:
- It makes the class abstract.
- You cannot create objects of a class that has at least one pure virtual function.
- It forces derived classes to provide their own version of the function.
- Any class with one or more pure virtual functions is called an abstract class.
*/

/*
the concept of abstraction:
is Hiding internal implementation and showing only necessary details using abstract classes 
(with pure virtual functions).
*/

#include<iostream>


const double PI = 3.14159;

class Shape{
    public:

    virtual double area() const = 0;
    virtual void printArea() const = 0;
};

class Rectangle : public Shape{
    public:

    double height;
    double width;

    Rectangle(double m_height, double m_width) 
    :height(m_height), width(m_width) {}

    double area() const override {
        return height * width;
    }

    void printArea(void) const override {
        std::cout<<"the area of the rectangle is = "<<area()<<std::endl;
    }
};
class Circle : public Shape{
    public:

    double radius;

    Circle(double m_radius) 
    :radius(m_radius){}

    double area() const override{
        return PI * radius * radius;
    }

    void printArea(void) const override {
        std::cout<<"the area of the circle is = "<<area()<<std::endl;
    }
};

int main(){

    Shape *pShape = new Circle(10);
    pShape ->area();
    pShape ->printArea();

    pShape = new Rectangle(10,5);
    pShape ->area();
    pShape ->printArea();
    
    delete pShape;
}