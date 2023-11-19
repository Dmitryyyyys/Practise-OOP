#include <iostream>
#include <algorithm>

int main() {
    int arr[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    int n = sizeof(arr) / sizeof(int);

    std::make_heap(arr, arr + n);

    std::cout << "Heapified array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
