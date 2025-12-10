// --------------typeAliases--------------

// using uint8 = unsigned char;
// typedef unsigned int u32 ;
// uint8 c = 8;

// --------------enum classs--------------

// ->enum class is a modern and safer alternative to traditional enum, \
// promoting strong typing, scoping, and better integration with other C++ features. \
// It’s particularly useful in large codebases, \
// libraries, or situations requiring strict type safety.

// enum class Color { Red, Green, Blue };
// enum class Size { Small, Medium, Large };

// Color c = Color::Red;
// // int value = c;            // Error: No implicit conversion to int
// // if (c == Size::Small) {}  // Error: Incompatible types

// --------------return by ref and ptr--------------



// ---------------------------------------------------------------------------------------
// #include<iostream>


// std::string globalName = "Ahmed";

// // Function returning reference to global variable
// std::string& getName() {
//     return globalName;
// }


// int main() {
//     std::cout << getName() << std::endl; // Outputs: Ahmed

//     getName() = "Dwidar"; // Modifies the global variable
//     std::cout << globalName << std::endl; // Outputs: Dwidar
// }
// #include<iostream>
// #include<vector>

// class MyContainer {
// private:
//     std::vector<int> data;
// public:
//     MyContainer() : data{1, 2, 3, 4, 5} {}

//     int& getElement(size_t index) {
//         return data[index];
//     }
// };

// int main() {
//     MyContainer container;
//     container.getElement(2) = 42; // Modifies the internal vector

//     std::cout << container.getElement(2) << std::endl; // Outputs: 42
// }

 غير كده اي تغيير مش هيسمع برا ياصاحبييي عايز تعدل علي اي حاجة جلوبال او خارج الاسكوب يبفي حط ريفرينس جمب الفانكشن عشان تعرف تباصيها 

// -----------------------------------------------------------------------------------

// int globalValue = 42;

// // Function returning a pointer to a global variable
// int* getGlobalValue() {
//     return &globalValue;
// }

// int main() {
//     int* ptr = getGlobalValue();
//     std::cout << *ptr << std::endl; // Outputs: 42

//     *ptr = 100; // Modifies the global variable
//     std::cout << globalValue << std::endl; // Outputs: 100
// }

// -----------------------------------------------------------
// - std::optional:
// is a powerful tool in modern C++ for representing optional values. \
// It improves code readability, safety, and expressiveness, \
// making it an essential utility for handling nullable or optional data \
// in a clean and type-safe manner.

// #include <optional>
// #include <iostream>
// #include <string>

// std::optional<std::string> findUserById(int id) {
//     if (id == 1) return "Ahmed";
//     return std::nullopt; // Represents no value
// }

// int main() {
//     auto user = findUserById(1);
//     if (user) {
//         std::cout << "User found: " << *user << std::endl; // Outputs: User found: Ahmed
//     } else {
//         std::cout << "User not found!" << std::endl;
//     }
// }

