/*
bubble sort is the simplest sorting algorithm that works by repeatedly swapping \
the adjacent elements if they are in the wrong order.

To sort a data set using bubble sort algorithm, follow the below steps:

    Start by comparing the first two elements. If they are in the wrong order, swap them.
    Continue this process for all elements moving from left to right. After the first pass, the largest element will be at the end.
    In the next pass, skip the last element since it’s already sorted and repeat the above steps. The second-largest element will move to the second-last position.
    Repeat the steps until the entire array is sorted.
*/
#include <bits/stdc++.h>
#include<iostream>

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){

        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                std::swap(arr[j],arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[],int size) {
    for (int i = 0; i < size;i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int arr[5] = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    printArray(arr,5); 

    bubbleSort(arr,5);

    std::cout << "Sorted array: ";
    printArray(arr,5);

    return 0;
}