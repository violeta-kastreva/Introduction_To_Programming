#include <iostream>


void init(int* &arr, int &size, int &capacity) {
    arr = nullptr;
    size = 0;
    capacity = 0;
}

bool reAlloc(int* &arr, int &size, int &capacity, int newCapacity) {
    int* newArr = new(std::nothrow) int[newCapacity];
    if (newArr == nullptr) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;

    return true;
}

bool push_back(int* &arr, int &size, int &capacity, int element) {
    if (size >= capacity) {
        if (!reAlloc(arr, size, capacity, capacity ? capacity*2 : 1)) {
            return false;
        }
    }

    arr[size] = element;
    size++;
    return true;
}

void deAlloc(int* &arr, int &size, int &capacity) {
    delete[] arr;
    arr = nullptr;
    size = 0;
    capacity = 0;
}

void print(const int*const &arr, const int &size, const int &capacity) {
    std::cout << "len=" << size << " cap=" << capacity << " {";

    if (size) {
        std::cout << arr[0];
    }
    for (int i = 1; i < size; i++) {
        std::cout << ", " << arr[i];
    }
    std::cout << "}\n";
}

void pop_back(int* &arr, int &size, int &capacity) {
    if (size) {
        size--;
    }
}

void selectionSort(int* &arr, int &size, int &capacity) {
    for (int i = 0; i < size; i++) {
        int minIdx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        std::swap(arr[i], arr[minIdx]);
    }
}

bool binarySearch(int* &arr, int &size, int &capacity, int target) {
    int l = 0, r = size-1;

    while (l <= r) {
        int m = l + (r-l)/2;

        if (arr[m] == target) {
            return true;
        } else if (target < arr[m]) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    return false;
}

int main() {
    int n;
    std::cin >> n;

    int *arr, size, capacity;
    init(arr, size, capacity);

    for (int i = 0; i < n; i++) {
        int el;
        std::cin >> el;

        if (!push_back(arr, size, capacity, el)) {
            deAlloc(arr, size, capacity);
            return 1;
        }
    }

    selectionSort(arr, size, capacity);
    print(arr, size, capacity);
    for (int i = 0; i < 10; i++) {
        std::cout << i << ' ' << binarySearch(arr, size, capacity, i) << '\n';
    }

    deAlloc(arr, size, capacity);

    return 0;
}