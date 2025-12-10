// Containers in C++ STL are data structures that hold collections of objects.

// Container->	Description
// vector->	Dynamic array
// list->	Doubly-linked list
// deque->	Double-ended queue
// set->	Sorted unique values
// map->	Key-value pairs
// unordered_map->	Hash table


// 1- std::vector -> example

#include<iostream>
#include<vector>
#include<map>

// int main(){

//     std::vector<int>v = {2,3,4};
//     v.push_back(5);

//     v.pop_back();

//     v[1] = 18;

//     for(auto i : v){

//         std::cout<<i<<"\t";
//     }
// }

// 1- std::map -> example


int main() {
    std::map<std::string, int> scores;
    scores["Ahmed"] = 90;
    scores["Lena"] = 85;

    for (auto& [name, score] : scores) {
        std::cout << name << " has " << score << "\n";
    }
}