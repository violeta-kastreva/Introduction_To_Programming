#include <iostream>
#include <climits>


int min(int a, int b) {
    return a < b ? a : b;
}

int main() {
    int current;

    int minimum = INT_MAX;
    int maximum = INT_MIN;
    do {
        std::cin >> current;
        if (current == 0) {
            break;
        }

        minimum = min(minimum, current);
        maximum = std::max(maximum, current);
    } while (current != 0);

    std::cout << "Minimum: " << minimum << '\n';
    std::cout << "Maximum: " << maximum << '\n';
}