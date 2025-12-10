- namespaces -> we use it to avoid linking errors specially \
when two functions which are identical(name and arguments) so that we can define\
each one in a separate namespace 

- if we have namespace called ahmed , then we can use it with as:
1- ahmed :: (namespace member)
2- using namespace ahmed 

- it's recommended to include the namespace inside the scope i am in to avoid\
the naming problems(as libraries) and also for optimization

#include<iostream>

namespace MyNamespace {
    int value = 42;

    void printValue() {
        std::cout << "Value: " << value << std::endl;
    }
}

int main(){
    MyNamespace::printValue;
    MyNamespace::value;
}

there are types of namespace that could be used:
1- nested namespace
2- inline namespace
3- Anonymous (Unnamed) Namespaces
4- namespace aliases

1. Nested Namespaces (C++17)

Prior to C++17, creating nested namespaces required explicitly nesting the \
declarations:

namespace Outer {
    namespace Inner {
        void func() { /* ... */ }
    }
}

In C++17, nested namespaces can be written in a single line using namespace A::B { ... }:

namespace Outer::Inner {
    void func() { /* ... */ }
}

This syntax simplifies code and enhances readability, especially when working with \
deeply nested namespaces.

2. Inline Namespaces (C++11)

Inline namespaces allow you to create versioned namespaces or override functions \
and classes within namespaces. Members of an inline namespace are accessible \
as though they were part of the enclosing namespace. This feature is useful for \
library versioning.

namespace Library {
    inline namespace Version1 {
        void func() { std::cout << "Version 1" << std::endl; }
    }

    namespace Version2 {
        void func() { std::cout << "Version 2" << std::endl; }
    }
}

int main() {
    Library::func();           // Calls Version1::func() due to inline namespace
    Library::Version2::func();  // Calls Version2::func() explicitly
}

In this example, Library::func() refers to Version1::func() because Version1 is an \
inline namespace. This approach allows you to introduce new versions of functions \
or classes while keeping the old ones accessible.

3. Anonymous (Unnamed) Namespaces

Anonymous namespaces are a way to limit the scope of functions and variables \
to a single translation unit (source file), similar to declaring things as \
static in the global scope. Theyey are commonly used to avoid polluting \
the global namespace with internal functions and variables.

namespace {
    int internalValue = 10;  // Only accessible within this file

    void internalFunc() {
        std::cout << "Internal function" << std::endl;
    }
}

int main() {
    internalFunc(); // Works fine here
    return 0;
}

Using an anonymous namespace limits the visibility of internalValue and \
internalFunc to the current file, which can be useful for functions or \
variables meant to be used only locally.

4. Namespace Aliases

Namespace aliases provide a way to create shorter or more convenient names \
for long or nested namespaces. This is helpful when you work with deeply \
nested namespaces or libraries with long namespace names.

namespace Very::Deeply::Nested::Namespace {
    void func() { /* ... */ }
}

// Alias for easier access
namespace VDN = Very::Deeply::Nested::Namespace;

int main() {
    VDN::func(); // Calls Very::Deeply::Nested::Namespace::func()
    return 0;
}

Namespace aliases make the code easier to read and type, especially when \
working with complex 