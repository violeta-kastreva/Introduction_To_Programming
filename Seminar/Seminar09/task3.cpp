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

int main() {
    int n;
    std::cin >> n;

    int* arr = createArray(n);
    if (arr == nullptr) {
        return 1;
    }

    // sum, min, max
    if (n == 0) {
        std::cout << "Empty array\n";
        delete[] arr;
        return 0;
    }

    int sum = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (min > arr[i]) {
            min = arr[i];
        }
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    std::cout << sum << ' ' << min << ' ' << max << '\n';

    delete[] arr;
    arr = nullptr;

    return 0;
}