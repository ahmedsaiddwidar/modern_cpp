----------templates-------------

Templates are a powerful feature in C++ that allow us to write generic and reusable code. \
Instead of writing separate code for each data type, templates enable us to write a single \
function or class that works with any type. They are foundational to generic programming.
--commonly used for its:
- Code Reusability: Avoid duplicating code for different data types.
- Type Safety: The compiler ensures type correctness during compilation.
- Flexibility: Works with user-defined types as well as built-in types.
- Performance: Templates are resolved at compile time, avoiding runtime overhead.

-> simple idea is to pass data type as a parameter so that we do not need to write same code for different types:
for example if sw company need to sort() for different types

---------- function templates-------------
- A function template allows you to create a function that works with any data type
- templates are considerd a feature of polymorphism

---------------------------------------------------------------------------------------------------------------

#include <iostream>

// Template Declaration
template <typename T>
T getMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    // Using the template with different types
    std::cout << "Max of 10 and 20: " << getMax(10, 20) << std::endl;         // int
    std::cout << "Max of 5.5 and 2.3: " << getMax(5.5, 2.3) << std::endl;     // double
    std::cout << "Max of 'A' and 'B': " << getMax('A', 'B') << std::endl;     // char

    return 0;
}

---------- class templates-------------
- A class template allows you to create a class that works with any data type.

The empty() function returns a boolean value (true or false):

    true: If the container has no elements.
    false: If the container contains one or more elements.

---------------------------------------------------------------------------------------------------------------

#include<iostream>
#include<vector>

template<typename T>

class stack{
    private:
    std::vector<T>v;

    public:

    void push(T element){
        v.push_back(element);
    }

    void pop(){
        if( !(v.empty() ) ){
            v.pop_back();
        }
    }

    T top(void)const{
        return v.back();
    }

    bool embty(void){
        return v.empty();
    }
};
int main(){

    stack<int> intStack;
    
    intStack.push(10);
    intStack.push(20);
    std::cout << "Top of intStack: " << intStack.top() << std::endl;

    stack<std::string> stringStack; // Stack for strings
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Top of stringStack: " << stringStack.top() << std::endl;

    return 0;
}
---------------------------------------------------------------------------------------------------------------
#include<iostream>

template<class T> T max(T a, T b){
    return (a > b) ?  a : b;
}

int main(){
    std::cout<<max(5,7)<<std::endl;
    std::cout<<max(0.3,0.1)<<std::endl;
    std::cout<<max("ahmed","said")<<std::endl;
}

#include <iostream>

template<class T> void buble_sort(T a[], T n){
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                std::swap(a[j], a[j - 1]);
}

int main()
{
    int a[5] = { 10, 50, 30, 40, 20 };
    int n = sizeof(a) / sizeof(a[0]);

    // calls template function
    buble_sort<int>(a, n);

    std::cout << " Sorted array : ";
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;

    return 0;
}

#include <iostream>

using namespace std ;

template<typename T>

class Array{
    private:
    T *p;
    int size;

    public:
    Array(T arr[], int s);
    void print();
};

template<typename T> Array<T>::Array(T arr[], int s){
    p = new T[s];

        size = s;
    for (int i = 0; i < size; i++)
        p[i] = arr[i];
}

template <typename T> void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << " " << *(p + i);
    cout << endl;
}

int main()
{
    int arr[5] = { 1, 2, 3, 4, 5 };
    Array<int> a(arr, 5);
    a.print();
    return 0;
}

---------------------------------------------------------------------------------------------------------------

#include<iostream>

template<typename T, typename Z> class entity{
    private:
    T x;
    Z y;

    public:
    entity(){std::cout<<"connstructor is called..\n";};
};

int main(){

    entity<char,char>e;
    entity<double,int>en;
}

---------------------------------------------------------------------------------------------------------------
-> We can pass non-type arguments to templates. Non-type parameters are mainly used for \
specifying max or min values or any other constant value for a particular instance of a template. \
The important thing to note about non-type parameters is, that they must be const. \
The compiler must know the value of non-type parameters at compile time. \
Because the compiler needs to create functions/classes for a specified non-type value at compile time. \
In the below program, if we replace 10000 or 256 with a variable, we get a compiler error.

#include<iostream>

template<class T, int min>

int getMin(T arr[],int n){
    int m = min;

    for(int i = 0; i < n; i++){
        if(arr[i] > m){
            m = arr[i];
        }
    }

    return m;
}

int main(){

    int a1[] = {10,8,12,7,11};
    int s1 = sizeof(a1) / sizeof(a1[0]);

    int a2[] = {15,17,14,19,13};
    int s2 = sizeof(a2) / sizeof(a2[0]);

    std::cout<<getMin<int, 0>(a1,s1)<<std::endl;
    std::cout<<getMin<int, 0>(a2,s2)<<std::endl;



    return 0;
}