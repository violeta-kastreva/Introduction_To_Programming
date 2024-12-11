#include <iostream>


int* createArray(int size) {
    if (size < 0) {
        return nullptr;
    }

    int* arr = new(std::nothrow) int[size];
    if (arr == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    return arr;
}

bool isSorted(int* arr, int n) {
    // a_i <= a_i+1, V i e {0, ..., n-2}
    for (int i = 0; i < n-1; i++) {
        if (arr[i] > arr[i+1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    std::cin >> n;

    int* arr = createArray(n);
    if (arr == nullptr) {
        return 1;
    }

    std::cout << isSorted(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;
}