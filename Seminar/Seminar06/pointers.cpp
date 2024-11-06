#include <iostream>


void swapPtr(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapRef(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapPtrRef(int* &a, int* &b) {
    int* temp = a;
    a = b;
    b = temp;
}

void swapPtrPtr(int** a, int** b) {
    int* temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a = 5, b = 6;

    a++;
    (*(&a))++;

    std::cout << a << ' ' << b << '\n';
    swapPtr(&a, &b);
    std::cout << a << ' ' << b << '\n';
    swapRef(a, b);
    std::cout << a << ' ' << b << '\n';

    int* ptrA = &a;
    int* ptrB = &b;
    std::cout << ptrA << ' ' << ptrB << '\n';
    std::cout << (*ptrA) << ' ' << (*ptrB) << '\n';
    swapPtrPtr(&ptrA, &ptrB);
    std::cout << ptrA << ' ' << ptrB << '\n';
    std::cout << (*ptrA) << ' ' << (*ptrB) << '\n';

    return 0;
}