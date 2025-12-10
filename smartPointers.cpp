smart pointers
- Smart pointers in C++ are a part of the Standard Template Library (STL)\
 and provide automatic memory management to help avoid issues like memory leaks and \
 dangling pointers. Introduced in C++11, smart pointers manage the lifetime of \
 dynamically allocated objects by ensuring proper cleanup when the object is no longer \
 needed.Smart pointers are implemented in the <memory> header

 - the main types are:
 1- r (std::unique_ptr)
 2- Shared Pointer (stdUnique Pointe::shared_ptr)
 3- Weak Pointer (std::weak_ptr)

 -------------------------------------------------
 1- std::unique_ptr

 A std::unique_ptr is a smart pointer that owns a dynamically allocated object exclusively. \
 No two std::unique_ptr objects can manage the same object, ensuring unique ownership.

    The object is destroyed automatically when the std::unique_ptr goes out of scope.
    It cannot be copied but can be moved to transfer ownership.

#include<iostream>
#include<memory>

int main(){

    std::unique_ptr<int>p1 = std::make_unique<int>(10);// Creates and manages an integer with value 10
    //Use std::make_shared<T>() for exception-safe and efficient object creation.
    std::unique_ptr<int>p3(new int (5));
    // Transferring ownership
    std::unique_ptr<int> p2 = std::move(p1);
    if (!p1) {
        std::cout << "ptr1 is now null." << std::endl;
    }

    return 0; // ptr2 automatically deletes the object it owns
}

class entity{
    int x;
public:

entity(int n)
:x(n)
{}
void print(void)const{
std::cout<<this ->x << std::endl;
}

};
int main()
{
    std::unique_ptr<entity>ent(new entity(8));

    ent ->print();
}

 -------------------------------------------------
 2- std::shared_ptr
A std::shared_ptr is a smart pointer that allows multiple std::shared_ptr \
instances to share ownership of the same dynamically allocated object. \
The object is destroyed when the last std::shared_ptr managing it is \
destroyed or reset.

    It uses reference counting to track how many std::shared_ptr objects are managing the object.
    Suitable for shared ownership scenarios.

int main(){

    std::shared_ptr<int>ptr1 = std::make_unique<int>(9);// Creates and manages an integer with value 9
    std::
    std::cout << *ptr1 << std::endl;

    // Sharing ownership
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << "Reference count: " << ptr1.use_count() << std::endl; // Prints 2

    return 0; // Object is deleted when the last shared_ptr (ptr1 and ptr2) is destroyed
}

 -------------------------------------------------
 2- std::weak_ptr
A std::weak_ptr is a non-owning smart pointer that works with \
std::shared_ptr. It does not affect the reference count of the \
std::shared_ptr.

    Useful for breaking cyclic dependencies in std::shared_ptr objects.
    It can be used to observe an object managed by a std::shared_ptr \
    without participating in ownership.

#include <iostream>
#include <memory>

int main() {
    std::shared_ptr<int> shared = std::make_shared<int>(30);
    std::weak_ptr<int> weak = shared; // Weak pointer observing the shared pointer

    if (auto ptr = weak.lock()) { // Converts weak_ptr to shared_ptr safely
        std::cout << *ptr << std::endl; // Prints 30
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    return 0;
}
notes:
- Non-owning observer of std::shared_ptr.
- Breaks cyclic references between shared pointers.

Best Practices

    1- Use std::unique_ptr as the default choice for managing dynamic memory \
    unless shared ownership is explicitly required.
    2- Use std::make_unique and std::make_shared to create smart \
    pointers whenever possible for exception safety.
    3- Avoid raw pointers unless absolutely necessary. \
    Prefer std::weak_ptr over raw pointers to observe shared ownership safely.
    4- Use std::weak_ptr to resolve cyclic dependencies in std::shared_ptr.


    1. Reference Count in std::shared_ptr

When you create a std::shared_ptr, it keeps track of how many shared_ptr instances are \
managing the same object. This count is called the reference count.

    Each time a new std::shared_ptr is created or copied, the reference count increases.
    When a std::shared_ptr is destroyed or reset, the reference count decreases.
    When the reference count becomes zero, the object is deleted automatically.

Example: Reference Count

#include <iostream>
#include <memory>

int main() {
    auto ptr1 = std::make_shared<int>(42); // Reference count = 1
    auto ptr2 = ptr1; // Reference count = 2
    std::cout << "Reference count: " << ptr1.use_count() << std::endl; // Prints 2
    ptr2.reset(); // Reference count = 1
    std::cout << "Reference count: " << ptr1.use_count() << std::endl; // Prints 1
    return 0; // Object is destroyed when count = 0
}

2. What is a Cyclic Dependency?

A cyclic dependency occurs when two or more objects refer to each other using \
std::shared_ptr. Since std::shared_ptr uses reference counting, \
this cycle prevents the objects from being destroyed, causing a memory leak.
Example of Cyclic Dependency:

#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next; // Points to the next Node
};

int main() {
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    node1->next = node2; // node1 owns node2
    node2->next = node1; // node2 owns node1 (cyclic dependency)

    return 0; // Memory leak: neither node1 nor node2 is destroyed
}

    Why is there a memory leak?
        node1 and node2 share ownership of each other, forming a cycle.
        Even when node1 and node2 go out of scope, their reference counts \
        never reach zero because they reference each other.

3. How std::weak_ptr Solves Cyclic Dependency

A std::weak_ptr is a non-owning pointer that "observes" the object managed by a \
std::shared_ptr. Unlike std::shared_ptr, a std::weak_ptr \
does not increase the reference count of the object.
Key Points:

    It observes a shared_ptr without contributing to the reference count.
    It can check whether the observed object still exists.
    It can be converted back to a std::shared_ptr to access the object safely.

By using std::weak_ptr, you can break the ownership cycle in cases like \
cyclic dependencies.
4. Example of Breaking a Cyclic Dependency with std::weak_ptr

Here’s the solution to the cyclic dependency issue in the previous example:

#include <iostream>
#include <memory>

struct Node {
    std::shared_ptr<Node> next; // Points to the next Node
    std::weak_ptr<Node> prev;  // Weak pointer to the previous Node
};

int main() {
    auto node1 = std::make_shared<Node>();
    auto node2 = std::make_shared<Node>();

    node1->next = node2; // node1 owns node2
    node2->prev = node1; // node2 observes node1, does not own it

    return 0; // No memory leak: weak_ptr prevents cyclic ownership
}

How It Works:

    node1 owns node2 using std::shared_ptr.
    node2 observes node1 using std::weak_ptr.
    Since std::weak_ptr does not increase the reference count, \
    the cycle is broken, and the objects are destroyed properly when no \
    std::shared_ptr points to them.

5. **Observing a shared_ptr with weak_ptr

A std::weak_ptr can observe an object managed by a std::shared_ptr. \
This means it keeps track of the object but does not own it.
Example:

#include <iostream>
#include <memory>

int main() {
    auto shared = std::make_shared<int>(42); // Shared ownership
    std::weak_ptr<int> weak = shared;       // Weak observation

    std::cout << "Shared pointer use count: " << shared.use_count() << std::endl; // 1

    if (auto locked = weak.lock()) { // Convert weak_ptr to shared_ptr safely
        std::cout << "Weak pointer observed value: " << *locked << std::endl; // 42
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    shared.reset(); // Shared pointer is destroyed

    if (auto locked = weak.lock()) {
        std::cout << "Weak pointer still holds the object." << std::endl;
    } else {
        std::cout << "The object is no longer available." << std::endl;
    }

    return 0;
}

Explanation:

    weak.lock() attempts to create a temporary std::shared_ptr from the std::weak_ptr.
    If the object is still available, lock() returns a valid std::shared_ptr. Otherwise, it returns nullptr.

Output:

Shared pointer use count: 1
Weak pointer observed value: 42
The object is no longer available.

