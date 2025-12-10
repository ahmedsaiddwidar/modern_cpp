---- variables lifetime(storage duration):
- local(block/automatic)
- static(until program ends)
- dynamic(until freed)

-----variables scope
- glopal
- local
- class
- namespace
- file scope(static)

------threads

- provide a way to perform multiple tasks concurrently within a program. \
They are a fundamental part of parallel programming, enabling you to run multiple parts of code simultaneously, \
which can improve efficiency and performance, especially on multi-core processors. \
C++ introduced native support for threads in C++11 through the <thread> library.

Creating and Using Threads

To create a new thread, you instantiate an std::thread object, passing a function or callable object as an argument. \
Here are some examples of how to create and manage threads in C++.

Example 1: Creating a Thread with a Function

#include <iostream>
#include <thread>

void printMessage() {
    std::cout << "Hello from a thread!" << std::endl;
}

int main() {
    std::thread t(printMessage); // Create a new thread that runs printMessage
    t.join(); // Wait for the thread to finish
    return 0;
}

    std::thread t(printMessage);: Creates a new thread t that runs the printMessage function.
    t.join();: Waits for thread t to complete its execution before proceeding. \
    If join is not called, the program may terminate before the thread finishes.

Example 2: Creating a Thread with a Lambda

#include <iostream>
#include <thread>

int main() {
    std::thread t([] {
        std::cout << "Hello from a lambda thread!" << std::endl;
    });
    t.join();
    return 0;
}

3. Detaching Threads

Instead of calling join(), you can call detach(), which allows the thread to run independently. However, \
once detached, the thread is no longer associated with the std::thread object, so you cannot check on or join it later.

std::thread t([] {
    std::cout << "Detached thread!" << std::endl;
});
t.detach(); // The thread will continue to run independently

    Warning: Detached threads can be risky because they run independently, \
    and accessing shared resources without synchronization may lead to undefined behavior.

4. Passing Arguments to Threads

Arguments can be passed to the function run by the thread, and they are passed by value. \
If you want to pass arguments by reference, you need to use std::ref or std::cref for constant references.

#include <iostream>
#include <thread>

void printSum(int a, int b) {
    std::cout << "Sum: " << (a + b) << std::endl;
}

int main() {
    int x = 10, y = 20;
    std::thread t(printSum, x, y); // Pass arguments to the thread function
    t.join();
    return 0;
}

For references:

#include <iostream>
#include <thread>

void increment(int& num) {
    ++num;
}

int main() {
    int value = 10;
    std::thread t(increment, std::ref(value)); // Pass by reference
    t.join();
    std::cout << "Value after increment: " << value << std::endl;
    return 0;
}

5. Synchronization in Threads

When multiple threads access shared resources (like variables or data structures), \
you need synchronization to avoid race conditions. The most common tools for synchronization in C++ are:

    Mutexes (std::mutex): Used to lock resources so that only one thread can access them at a time.
    Locks (std::lock_guard, std::unique_lock): Manage mutex locking and unlocking automatically, providing exception safety.
    Condition Variables (std::condition_variable): Allow threads to wait for certain conditions to become true.

Example: Using a Mutex

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Mutex to protect shared resource
int counter = 0;

void increment() {
    std::lock_guard<std::mutex> lock(mtx); // Automatically locks and unlocks the mutex
    ++counter;
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}

In this example, the std::lock_guard automatically locks the mutex when created and unlocks it \
when the guard goes out of scope, ensuring that counter is safely accessed by only one thread at a time.
6. Thread Management
Checking if a Thread is Joinable

You can check if a thread is joinable (i.e., if it hasn’t yet been joined or detached) using the joinable() function:

std::thread t(printMessage);
if (t.joinable()) {
    t.join();
}

Hardware Concurrency

You can check the number of threads that your hardware can run concurrently using std::thread::hardware_concurrency(). \
This is useful for deciding how many threads to create for optimal performance.

unsigned int n = std::thread::hardware_concurrency();
std::cout << "Hardware supports " << n << " concurrent threads." << std::endl;

7. Example of a Thread Pool

For more complex applications, a thread pool is a collection of reusable threads that can be used to handle multiple tasks efficiently.

Here’s a simple conceptual example:

#include <iostream>
#include <vector>
#include <thread>

void doWork(int id) {
    std::cout << "Thread " << id << " is working\n";
}

int main() {
    int numThreads = std::thread::hardware_concurrency();
    std::vector<std::thread> threadPool;

    for (int i = 0; i < numThreads; ++i) {
        threadPool.emplace_back(doWork, i);
    }

    for (auto& t : threadPool) {
        t.join();
    }
    return 0;
}

This code creates a simple thread pool that launches one thread per core, each running the doWork function.