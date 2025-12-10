- const -> means the variable is immutable after initialization ,regardless of its value is known at compile time or not.

const int x = 10; // known at compile-time
int y = 20;
const int z = y;  // known at runtime

1- It can be used in any scope (global or local).
2- If it’s at the global or static scope, it has internal linkage by default.
3- Can be used to make read-only pointers or references.

but!!!!

- constexpr -> means its value is evaluated at compile time for performance and optimization purposes

used for values or functions that you want to guarantee will be resolved at compile time.

constexpr int x = 10; // known at compile-time
constexpr int square(int x) { return x * x; }
constexpr int y = square(5); // evaluated at compile time

1- A constexpr function can be used in constexpr contexts or with non-constexpr arguments at runtime.
2- All constexpr variables are implicitly const.
3- Great for metaprogramming or compile-time optimizations.

but!!!!

- constinit -> it means we must initilaize the variable in compile time (c++ 20) and we could change its value \
throughout the program code it Enforces compile-time initialization for static or global variables.

constinit int x = 42; // must be initialized at compile time

1- Useful for static or global variables that must be initialized at compile time to avoid the "static initialization order fiasco."
2- Unlike constexpr, constinit does not make the variable constant; it can be modified after initialization.
3- Helps avoid accidental runtime initialization for variables that should be initialized at compile time.