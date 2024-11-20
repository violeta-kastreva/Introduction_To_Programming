#include <iostream>


int main() {
    int n;
    std::cin >> n;

    int* dynVar = new(std::nothrow) int;
    if (dynVar == nullptr) { // Could not allocate
        std::cout << "Could not allocate memory!\n";
        return 1;
    }
    int* arr = new(std::nothrow) int[n];
    if (arr == nullptr) {
        delete dynVar;
        dynVar = nullptr;
        std::cout << "Could not allocate memory!\n";
        return 1;
    }

    std::cin >> *dynVar;
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << *dynVar << '\n';
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << ' ';
    }

    delete dynVar;
    dynVar = nullptr;
    delete[] arr;
    arr = nullptr;

    return 0;
}