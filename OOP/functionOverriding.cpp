#include<iostream>

// class vehicle{
//     public:

//     void start(void){
//         std::cout<<"the vehicle has started"<<std::endl;
//     }
// };


// class car : public vehicle {

//     public:
//     void honk(void){
//         std::cout<<"the car is honking"<<std::endl;
//     }
// };

// int main(){

//     car automobile;


//     automobile.start();
//     automobile.honk();

// }

// class user{
//     protected:
//     std::string username;

//     public:

//     user(std::string u_name): username(u_name){}

//     virtual void displayRole(void) const {
//         std::cout<< username <<" is a generic user. \n";
//     }

//     virtual ~user(){
//         std::cout<<"destroying the username: "<< username << std::endl;
//     }
// };

// class admin : public user {
//     public:

//     admin(std::string uname) : user(uname) {}

//     void displayRole(void) const override {
//         std::cout<<username <<" is an admin.\n";
//     }

//     ~admin() {
//         std::cout<<"destroying admin "<< username << std::endl;
//     }

// };

// int main(){
//     user *pUser1 = new admin("ahmed");
//     pUser1 ->displayRole();

//     delete pUser1;

// }
/*
overriding is a key feature of polymorphism in object-oriented programming. /
It allows a derived (child) class to provide a specific implementation of a function /
that is already defined in its base (parent) class. This is useful when you want different /
behaviors for the same function name depending on the object type.
*/

/*
- To change or extend the behavior of a function in a derived class.
- Enables runtime polymorphism, which allows decisions to be made at runtime rather than compile-time.
- It's useful in scenarios like implementing different behaviors for a draw() function in different shapes (e.g., Circle, Rectangle).
*/

/*
the use of keyword virtual:
When you call a function using a base class pointer or reference, and that function is marked as virtual, /
C++ will check the actual object type at runtime and call the correct function.

Without virtual, C++ uses compile-time binding (early binding), /
meaning it will call the base class version even if the object is a derived type.

*/