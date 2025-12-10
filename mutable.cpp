mutables

- if we have an const method and for some reason we want it to modify a variable for example inside a class so we define this var as mutable

class Example {
private:
    mutable int accessCount = 0; // Can be modified even in const methods

public:
    int getValue() const {
        accessCount++;           // Allowed due to `mutable`
        return 42;
    }

    int getAccessCount() const {
        return accessCount;
    }
};

- keep tracking the code in debugging
- with lambdas when we want inside lambda to do an operation on a variable passed by value

auto f = [=]( )mutable {x++,print x};

- is useful with lambda expressions when you want to modify the values of captured variables by copy.\
 Normally, lambda captures by copy are const by default, meaning you cannot modify the captured variables inside the lambda body. \
 The mutable keyword allows you to bypass this restriction.



 int x = 10;

auto lambda = [x]() mutable {
    x++;         // Allowed: 'x' can be modified inside the lambda
    std::cout << "Inside lambda, x = " << x << std::endl;
};

lambda();

std::cout << "Outside lambda, x = " << x << std::endl;

-> Inside lambda, x = 11
-> Outside lambda, x = 10
