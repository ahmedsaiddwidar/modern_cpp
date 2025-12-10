/*
Binary search is an efficient algorithm to find the position of a target value within a sorted array. \
It operates by repeatedly dividing the search interval in half, hence reducing the time complexity to O(log⁡n)O(logn).

    Divide the search space into two halves by finding the middle index “mid”. 
    Compare the middle element of the search space with the key. 
    If the key is found at middle element, the process is terminated.
    If the key is not found at middle element, choose which half will be used as the next search space.
        If the key is smaller than the middle element, then the left side is used for next search.
        If the key is larger than the middle element, then the right side is used for next search.
    This process is continued until the key is found or the total search space is exhausted.
*/

#include<iostream>

int binarySearch(int arr[], int size, int keyElement){
    int low = 0;
    int high = size - 1;
    int mid = ( ( high - low ) / 2 );
    int i,j,keyIndex;

    for(i = 0; i < size; i++){
        if(arr[i] == keyElement){
            keyIndex = i;
            break;
        }
        else{
            if(arr[i] < keyElement){
                low = mid;
                mid = ( ( high - low ) / 2 );
            }
            else if(arr[i] > keyElement){
                high = mid;
                mid = ( ( high - low ) / 2 );
            }
        }
    }
    return keyIndex;
}


int main(){

    int a[11] = {0,1,2,3,4,5,6,7,8,9,10};

    int res = binarySearch(a,11,9);

    std::cout<<res<<std::endl;

    return 0;
}