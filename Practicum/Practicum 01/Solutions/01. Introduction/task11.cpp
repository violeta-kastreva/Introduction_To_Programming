#include <iostream>

int main() {
    int grade;
    std::cin >> grade;
    if (grade >= 2 && grade <= 6) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}
