#include<array>
#include<iostream>


std::array<int , 5>arr = {1,2,3,4,5};
-> is considered the onlly containers that allocate in _ALLOCA_S_STACK_MARKER

int x = arr[4]  //no problem
int y = arr.at[2] // runtime error