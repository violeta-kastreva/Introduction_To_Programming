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

void removeAt(int* arr, int n, int idx) {
    for (int i = idx; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    arr[n-1] = -1;
}

int main() {
    int n;
    std::cin >> n;

    int* arr = createArray(n);
    if (arr == nullptr) {
        return 1;
    }

    int idx;
    std::cin >> idx;
    removeAt(arr, n, idx);
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete[] arr;
    arr = nullptr;

    return 0;
}