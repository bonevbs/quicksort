#include <iostream>

void print_array(int *arr, size_t len);
void quicksort(int *arr, size_t len);

int main() {
    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++) {
      arr[i] = rand()%100;
    }
    print_array(arr, n);
    quicksort(arr, n);
    print_array(arr, n);
    return 0;
}

void print_array(int *arr, size_t len) {
    for (int i = 0; i < len; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// sorts the list of integers in place using comparison
void quicksort(int *arr, size_t len) {
    if (len <= 1)
        return;
    int k = rand()%len; // pick a random element
    int sep = arr[k];
    int i, j;
    i = 0; j = len - 1;
    while ((j > i) && (i < len) && (j >= 0)) {
        if ((arr[i] == sep) && (arr[j] == sep)) {
            j--;
        } else if ((arr[i] >= sep) && (arr[j] <= sep)) {
            int tmp = arr[i]; // maybe avoid using the constructer every time
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