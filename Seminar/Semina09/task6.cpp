#include <iostream>

void swap(int &a, int &b) {
    int buff = a;
    a = b;
    b = buff;
}

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

void reverseFirstHalf(int* arr, int n) {
    n /= 2;
    for (int i = 0; i < n/2; i++) {
        swap(arr[i], arr[n-1-i]);
    }
}

int main() {
    int n;
    std::cin >> n;

    int* arr = createArray(n);
    if (arr == nullptr) {
        return 1;
    }

    reverseFirstHalf(arr, n);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}