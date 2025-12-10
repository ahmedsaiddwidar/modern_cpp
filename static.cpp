// static keyword has two meanings if we use it inside or outsude the class
// outside the class means that the variable scope is only for the particular file it as defined in
// with local variables the var will mainatin its value from one function call to another and will exist until the program ends

// inside the class that means there is one instance for static data methods or variables shared between all class instances which also means\
if we changed them at any class instance their changes will be applied to ther instances ->> \
If a static variable is modified through one instance of the class from the class, the change will be reflected across all other instances. \
Since there's only one copy, any changes apply universally.

// and that looks like we created two variables inside namespace with class name(we define and access them by resulution op ::))
// same as we created glopal variables but it could be public,private or protected 


#include<iostream>

class myClass{
    public:

    static int staticVar;

    void setStaticVar(int val){
        staticVar = val;
    }

    void printStaticVar(void) const{
        std::cout<<staticVar<<std::endl;;
    }
};

int myClass::staticVar = 0;

int main(){

    myClass obj1,obj2;

    obj1.setStaticVar(5);
    obj1.printStaticVar();  // Output: staticVar: 5
    obj2.printStaticVar();  // Output: staticVar: 5

    obj2.setStaticVar(10);
    obj1.printStaticVar();  // Output: staticVar: 10
    obj2.printStaticVar();  // Output: staticVar: 10

    return 0;
}


#include <iostream>
using namespace std;

class MyClass {
    private:
    static int privatStaicVar;

    public:
    static int publicStaticVar;

    static void setPrivateStaticVar(int val){
        privatStaicVar = val;
    }

    static int getPrivateStaticVar(void){
        return privatStaicVar;
    }
};

// Definition outside the class using the scope resolution operator ::
int MyClass::publicStaticVar = 0;
int MyClass::privatStaicVar = 0;

int main() {
    // Accessing and modifying static variables via the class name
    MyClass::publicStaticVar = 5;

    MyClass obj;
    cout << "Public Static Variable: " << MyClass::publicStaticVar << endl;

    // Using public static methods to modify private static variables
    MyClass::setPrivateStaticVar(10);
    cout << "Private Static Variable (accessed via method): " << MyClass::getPrivateStaticVar() << endl;

    

    return 0;
}

// we can not access not static data inside static method because static method does not belong to a class instance
// classes are just a functions with hidden parameteres, every time we define a member it create a class instance \\
means they become a parameter for this function
