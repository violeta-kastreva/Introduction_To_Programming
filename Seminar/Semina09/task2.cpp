#include <iostream>


int* createArray(int size) {
    if (size <= 0) {
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

int main() {
    int n;
    std::cin >> n;

    int* arr = createArray(n);
    if (arr == nullptr) {
        return 1;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}