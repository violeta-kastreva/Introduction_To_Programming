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

bool isPalindrom(int* arr, int n) {
    for (int i = 0; i < n/2; i++) {
        if (arr[i] != arr[n-1-i]) {
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

    std::cout << isPalindrom(arr, n);

    delete[] arr;
    arr = nullptr;

    return 0;
}