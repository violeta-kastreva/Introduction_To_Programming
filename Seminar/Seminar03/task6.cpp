#include <iostream>


int main() {
    int n;
    std::cin >> n;

    // Make sure x >= 0
    if (n < 0) {
        std::cout << "N is negative!";
        return 1;
    }

    // Top half (including middle row)
    for (int i = 0; i < n; i++) {
        // Print leading spaces
        const int SPACES = n - i - 1;
        for (int j = 0; j < SPACES; j++) {
            std::cout << ' ';
        }
        // Print stars
        const int STARS = 2 * i + 1;
        for (int j = 0; j < STARS; j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    // Bottom half
    for (int i = n - 2; i >= 0; i--) {
        // Print leading spaces
        const int SPACES = n - i - 1;
        for (int j = 0; j < SPACES; j++) {
            std::cout << ' ';
        }
        // Print stars
        const int STARS = 2 * i + 1;
        for (int j = 0; j < STARS; j++) {
            std::cout << '*';
        }
        std::cout << '\n';
    }

    return 0;
}