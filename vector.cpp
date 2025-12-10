#include<iostream>
#include<vector>
#include<memory>

// int main(){

//     std::vector<int>v = {1,2,3,4,5};

//     for(auto &i : v){
//         std::cout<<i<<std::endl;
//     }

// }

    struct said{
        std::string name;
        unsigned int age;

        said(std::string m_name, unsigned int m_age)
        : name(m_name), age(m_age){}
    };

// int main(){

//     std::vector<said>ahmed;

//     ahmed.push_back(said("dewidar",26));

//     std::cout<<ahmed[0].name<<std::endl<<ahmed[0].age<<std::endl;

//     ahmed.push_back(said("mahmoud",30));

//     std::cout<<ahmed[1].name<<std::endl<<ahmed[1].age<<std::endl;

//     ahmed.emplace_back("ahmed",35);
    
//     std::cout<<ahmed[2].name<<std::endl<<ahmed[2].age<<std::endl;

// }

int main(){

std::vector<std::unique_ptr<int>>vec;

vec.push_back(std::make_unique<int>(10));
vec.push_back(std::make_unique<int>(20));

for(const auto &ptr : vec){
    std::cout<<*ptr<<" ";
}

}