/*
Selection Sort is a comparison-based sorting algorithm. \
It sorts an array by repeatedly selecting the smallest (or largest) element \
from the unsorted portion and swapping it with the first unsorted element. \

This process continues until the entire array is sorted.

    First we find the smallest element and swap it with the first element. This way we get the smallest element at its correct position.
    Then we find the smallest among remaining elements (or second smallest) and move it to its correct position by swapping.
    We keep doing this until we get all elements moved to correct position.

*/

#include <bits/stdc++.h>
#include<iostream>

void bubbleSort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){

        for(int j = i + 1; j < size; j++){
            if(arr[i] > arr[j]){
                std::swap(arr[i],arr[j]);
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