/*
 -> the lower bound is a concept used to find the first element in a sorted range \
 that is not less than a given value. The lower_bound function is \
 part of the <algorithm> header in the Standard Template Library (STL).


->The std::lower_bound function returns an iterator pointing to the \
first element in the range [first, last) that is greater than or equal \
to (>=) the specified value.
If no such element is found, it returns last (the end iterator).

std::lower_bound(InputIterator first, InputIterator last, const T& value, Compare comp);

*/

#include<iostream>
#include<algorithm>
#include<vector>

int main(){
    std::vector<int>v = {1, 3, 3, 6, 8, 10};

    int x = 3;

    auto it = std::lower_bound(v.begin(),v.end(),x);

    if (it != v.end()) {
        std::cout << "Lower bound for " << x << " is at position: "
                  << (it - v.begin()) << std::endl;
        std::cout << "Element at lower bound: " << *it << std::endl;
    } else {
        std::cout << "No lower bound found for " << x << std::endl;
    }

    return 0;
}

lower_bound(v.begin(),v.end(),6); 
	
	
	// return an iterator to [[[ first number is not less than 6 ]]] 
	
	
	1 2 3 4 5 6 7 8 
	
	answer is 6 
	
	
	1 2 3 4 5  7 8 
	answer is 7 
	
	
	or it return iterator to end 
	
	
	
	
	

-- the vector must be sorted 


-- it use binary search ... O(logN) 