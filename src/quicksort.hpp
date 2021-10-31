#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include <stddef.h>
#include <iostream>
#include <string>

template<class T>
void print_array(T *arr, size_t len) {
    unsigned int i;
    for (i = 0; i < len; i++) {
        if (i > 0) std::cout << " ";
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

// sorts the list of integers in place using comparison
template<class T>
void quicksort(T *arr, size_t len) {
    if (len <= 1)
        return;
    unsigned int k = rand()%len; // pick a random element
    T sep = arr[k];
    unsigned int i, j;
    i = 0; j = len - 1;
    while ((j > i) && (i < len)) {
        if ((arr[i] == sep) && (arr[j] == sep)) {
            j--;
        } else if ((arr[i] >= sep) && (arr[j] <= sep)) {
            T tmp = arr[i]; // maybe avoid using the constructer every time
            arr[i] = arr[j];
            arr[j] = tmp;
        } else if (arr[j] > sep) {
            j--;
        } else if (arr[i] < sep) {
            i++;
        } else if ((arr[i] == sep) && (arr[j] == sep)) {
            j--;
        }
    }
    k = i;
    if (k > 1)
        quicksort(arr, k);
    while ((arr[k] == sep) && (k < len))
        k++;
    if (len - k > 1)
        quicksort(arr+k, len-k);
}

#endif /* QUICKSORT_HPP */