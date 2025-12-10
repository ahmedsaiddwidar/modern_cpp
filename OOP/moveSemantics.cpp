#include <iostream>
#include <cstring>

class Buffer {
private:
    char* data;
    size_t size;

public:
    // Constructor
    Buffer(size_t s) : size(s) {
        data = new char[size];
        std::cout << "Constructed\n";
    }

    // Copy constructor (deep copy)
    Buffer(const Buffer& other) : size(other.size) {
        data = new char[size];
        std::memcpy(data, other.data, size);
        std::cout << "Copied\n";
    }

    // Move constructor
    Buffer(Buffer&& other) noexcept : data(other.data), size(other.size) {
        other.data = nullptr;
        other.size = 0;
        std::cout << "Moved\n";
    }

    // Destructor
    ~Buffer() {
        delete[] data;
        std::cout << "Destroyed\n";
    }
};

Buffer createBuffer() {
    Buffer temp(1024); // temporary object
    return std::move(temp);;       // RVO or move, This tells the compiler: "treat temp as an rvalue, move it!"
}

int main() {
    Buffer b1 = createBuffer(); // move semantics here
}