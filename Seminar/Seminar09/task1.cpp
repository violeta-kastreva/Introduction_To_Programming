#include <iostream>


void swap(double &a, double &b) {
    double buff = a;
    a = b;
    b = buff;
}


int main() {
    double a, b;
    std::cin >> a >> b;

    swap(a, b);

    std::cout << a << ' ' << b << '\n';

    return 0;
}