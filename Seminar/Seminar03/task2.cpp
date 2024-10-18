#include <iostream>


int main() {
    int x;
    std::cin >> x;

    if (x <= 1) {
        std::cout << "No";
        return 0;
    }

    // 1[2..x-1]x
    for (int divisor = 2; divisor < x; ++divisor) {
        if (x % divisor == 0) {
            std::cout << "No";
            return 0;
        }
    }
    
    std::cout << "Yes";

    return 0;
}