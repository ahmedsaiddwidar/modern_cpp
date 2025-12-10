- auto deduces the type of a variable from the initializer, \
making it easier to manage complex types.
- For complex types, auto eliminates the need to repeatedly \
write out long type names.

- Ease of Iteration with Ranged-based For Loops
- When capturing values in lambda expressions, \
auto deduces the return type automatically.
- Simplifying Function Return Types

When writing generic code where the type may vary, \
auto ensures the correct type is always used.

auto square = [](int x) {return 2 * x;};
std::cout<<square<<std::endl;

std::verctor<int>numbers = {1,2,3,4};
for(auto element : numbers){
    //do somthing
}



