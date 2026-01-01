// How do I get the current item? (Dereference operator: *it)

// How do I move to the next item? (Increment operator: ++it)

// How do I know when I am finished? (Inequality operator: it != end)

#include <iostream>
#include <string>
#include <vector>

class BookIterator {
private:
    // The iterator holds a raw pointer to current position in the container's data array.
    std::string* m_ptr;

public:
    // explicit prevents implicit (automatic) conversions using this cons`tructor.
    // Constructor: Initialize the cursor to a specific position.
    explicit BookIterator(std::string* ptr)
    : m_ptr(ptr) {}

    // Requirement 1: How do I get the current item? (Dereference)
    // Returns a reference to the string at the current pointer location.
    // This is operator overloading syntax for the dereference operator (*).
    std::string& operator*() {
        return *m_ptr;
    }

    // Requirement 2: How do I move to the next item? (Increment)
    // Moves the pointer to the next memory address.
    // returning *this allows chaining (e.g., ++++it) though rarely used here.
    BookIterator& operator++() {
        m_ptr++;

        return *this;
    }

    // Requirement 3: How do I know when I am finished? (Inequality)
    // Compares this iterator's pointer with another iterator's pointer (usually the 'end' iterator).
    bool operator!=(const BookIterator& other) const {
        return m_ptr != other.m_ptr;
    }

};                              


// ==========================================
// 2. THE CUSTOM CONTAINER (Aggregate)
// ==========================================
// This holds the actual data. It doesn't know how to traverse itself.
// It delegates that job to the Iterator.
class LibraryShelf {
private:
    // Internal storage hidden from the world.
    std::vector<std::string> m_books;

public:
    void addBook(const std::string& title) {
        m_books.push_back(title);
    }

    // --- The Iterator Interface ---
    // C++ convention dictates these methods must be named begin() and end().

    // Creates an iterator pointing to the FIRST element.
    BookIterator begin() {
        // .data() returns a raw pointer to the start of the vector's memory array.
        return BookIterator(m_books.data());
    }

    // Creates an iterator pointing just PAST THE LAST element.
    // This is the standard "end" marker in C++.
    BookIterator end() {
        // Pointer arithmetic: start pointer + number of elements = address just after the end.
        return BookIterator(m_books.data() + m_books.size());
    }
};


// ==========================================
// 3. CLIENT CODE
// ==========================================
int main() {
    std::cout << "--- Setting up the Library Shelf ---\n";
    LibraryShelf fantasyShelf;
    fantasyShelf.addBook("The Hobbit");
    fantasyShelf.addBook("Mistborn");
    fantasyShelf.addBook("The Name of the Wind");

    std::cout << "Books added. Now iterating...\n\n";

    // ============================================================
    // THE MAGIC: Using a range-based for loop on a custom object!
    // ============================================================
    std::cout << "--- Iteration Output ---\n";
    for (const std::string& book : fantasyShelf) {
        std::cout << "Found book: " << book << "\n";
    }
    std::cout << "------------------------\n";

    // --- What the compiler actually generates under the hood ---
    // The range-based loop above is automatically re-written by the
    // compiler into something that looks roughly like this:
    /*
    std::cout << "\n(Manual equivalent under the hood):\n";
    auto it_begin = fantasyShelf.begin(); // Calls our begin()
    auto it_end = fantasyShelf.end();     // Calls our end()

    // The standard loop structure:
    for (auto it = it_begin; it != it_end; ++it) {
        const std::string& book = *it;    // Calls operator*
        std::cout << "Found book: " << book << "\n";
    }
    */

    return 0;
}