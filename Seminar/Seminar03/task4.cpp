#include <iostream>
#include <cmath>


int main() {
    int n;
    std::cin >> n;


    for (int x = std::max(2, n); x <= 100; x++) {
        bool prime = true;
        for (int divisor = 2; divisor < x; ++divisor) {
            if (x % divisor == 0) {
                prime = false;
                break;
            }
        }

        if (prime) {
            std::cout << x << ' ';
        }
    }

    return 0;
}