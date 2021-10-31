#include "quicksort.hpp"
#include <iostream>

std::string random_string(size_t len)
{
    auto randchar = []() -> char
    {
        const char charset[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[ rand() % max_index ];
    };
    std::string str(len, 0);
    std::generate_n(str.begin(), len, randchar);
    return str;
}

int runtest_integers(size_t len) {
    int arr[len];
    unsigned int i;
    for (i = 0; i < len; i++) {
      arr[i] = rand()%100;
    }
    quicksort(arr, len);
    return 0;
}

int runtest_strings(size_t len) {
    std::string arr[len];
    unsigned int i;
    for (i = 0; i < len; i++) {
      arr[i] = random_string(3);
    }
    quicksort(arr, len);
    return 0;
}

int main() {
    int n = 100;

    // test it using integers
    std::cout << "quick-sorting integers: ";
    if (runtest_integers(n) == 0)
        std::cout << "Success" << std::endl;
    else 
        std::cout << "Failues" << std::endl;

    std::cout << "quick-sorting strings: ";
    if (runtest_strings(n) == 0)
        std::cout << "Success" << std::endl;
    else 
        std::cout << "Failues" << std::endl;

    return 0;
}