 Basic Structure

try {
    // Code that may throw an exception
}
catch (const ExceptionType& e) {
    // Code to handle the exception
}

🚦 How It Works

    Code inside try is executed normally.

    If an exception is thrown (e.g., throw std::runtime_error("Oops")),
    execution jumps immediately to the catch block.

    If no exception is thrown → catch block is skipped.

✅ Example 1 – Basic Integer Division

#include <iostream>
#include <stdexcept>

int divide(int a, int b) {
    if (b == 0)
        throw std::runtime_error("Cannot divide by zero");
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
        std::cout << "Result: " << result << "\n";
    }
    catch (const std::runtime_error& e) {
        std::cout << "Error: " << e.what() << "\n";
    }
}

🧾 Output:

Error: Cannot divide by zero

🔥 Explanation

    divide(10, 0) throws a runtime_error

    catch block catches it and prints the error using e.what()

    No crash — handled cleanly 🙌

💡 Catching by Reference (const T&)

Always catch exceptions by const reference, like const std::exception& e:

    Avoids object slicing

    Prevents copying

    Enables polymorphism

🧺 Multiple Catch Blocks

try {
    // some risky code
}
catch (const std::out_of_range& e) {
    std::cout << "Out of range: " << e.what() << "\n";
}
catch (const std::exception& e) {
    std::cout << "General error: " << e.what() << "\n";
}

The first matching catch is executed.
🌀 Catch-All Handler

catch (...) {
    std::cout << "Unknown error occurred\n";
}

Use this as a fallback for anything not caught earlier.
⚙️ Memory Behavior

If an exception is thrown:

    Stack unwinds → destructors are called for all local objects

    No memory leaks if RAII is used

✅ Always use smart pointers or RAII-style classes to avoid leaks in exceptions.
🧪 Example 2 – Custom Exception Class

#include <iostream>
#include <exception>

class MyException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Something went wrong in MyException!";
    }
};

int main() {
    try {
        throw MyException();
    }
    catch (const MyException& e) {
        std::cout << "Caught custom exception: " << e.what() << "\n";
    }
}

🛠️ noexcept and throw()

In modern C++:

    noexcept marks a function that does not throw

    Helps with performance and safety

void myFunction() noexcept {
    // Guaranteed not to throw
}

⛔ When Not to Use Exceptions

    In performance-critical code (e.g., embedded systems, real-time)

    When you can use error codes safely instead

    Avoid using exceptions for normal control flow