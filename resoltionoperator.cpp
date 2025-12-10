// The :: operator is used to explicitly refer to the global scope to avoid ambiguity between \
// local and global variables.
// Example: Accessing Global Variables

#include <iostream>
using namespace std;

int x = 10; // Global variable

void display() {
    int x = 5;  // Local variable
    cout << "Local x: " << x << endl;
    cout << "Global x: " << ::x << endl;  // Access global x
}

int main() {
    display();  // Will show both local and global x
    return 0;
}

// Output:

// Local x: 5
// Global x: 10

// ✔ ::x is used to refer to the global variable x, even though there is a local x in the display() function.
// 2️⃣ Accessing Namespaces

// The :: operator is used to refer to variables, functions, or classes that belong to a namespace.
// Example: Accessing a Namespace Member

// #include <iostream>
// using namespace std;

// namespace MyNamespace {
//     int value = 42;
// }

// int main() {
//     cout << "Namespace value: " << MyNamespace::value << endl;
//     return 0;
// }

// Output:

// Namespace value: 42

// ✔ MyNamespace::value accesses the value variable inside the MyNamespace namespace.
// 3️⃣ Accessing Class Members

// The :: operator is used to access static members or define class functions outside the class definition.
// Example: Accessing Static Members

// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     static int count;
// };

// int MyClass::count = 0;  // Definition of static member outside the class

// int main() {
//     cout << "Static count: " << MyClass::count << endl;
//     return 0;
// }

// Output:

// Static count: 0

// ✔ MyClass::count accesses the static member count of the class MyClass.
// 4️⃣ Defining Member Functions Outside the Class

// You can use the :: operator to define member functions of a class outside the class definition.
// Example: Defining Member Function Outside the Class

// #include <iostream>
// using namespace std;

// class MyClass {
// public:
//     void display();
// };

// // Definition of display function outside the class
// void MyClass::display() {
//     cout << "Display function called!" << endl;
// }

// int main() {
//     MyClass obj;
//     obj.display();  // Calls the member function
//     return 0;
// }

// Output:

// Display function called!

// ✔ MyClass::display() defines the member function display() outside the class.
// 5️⃣ Accessing Enum Values

// The :: operator is used to access enumerator values inside an enum class.
// Example: Accessing Enum Values

// #include <iostream>
// using namespace std;

// enum class Color {
//     Red,
//     Green,
//     Blue
// };

// int main() {
//     Color c = Color::Red;
//     if (c == Color::Red) {
//         cout << "Color is Red!" << endl;
//     }
//     return 0;
// }

// Output:

// Color is Red!

// ✔ Color::Red accesses the Red value from the enum class Color.
// 6️⃣ Accessing Derived Class Members (Inheritances)

// The :: operator can also be used in the context of class inheritance to refer to base class members.
// Example: Accessing Base Class Members

// #include <iostream>
// using namespace std;

// class Base {
// public:
//     void show() { cout << "Base class show function!" << endl; }
// };

// class Derived : public Base {
// public:
//     void display() { cout << "Derived class display function!" << endl; }
// };

// int main() {
//     Derived obj;
//     obj.show(); // Base class function
//     obj.display(); // Derived class function
//     return 0;
// }

// Output:

// Base class show function!
// Derived class display function!

// ✔ The :: operator is not explicitly required here, but it would be useful if we \
// wanted to refer to a specific function in a base or derived class.