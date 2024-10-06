#include <iostream>

int main() {
    int n;
    std::cin >> n;

    int digit1 = n / 1000;        // Get the first digit
    int digit2 = (n / 100) % 10;  // Get the second digit
    int digit3 = (n / 10) % 10;   // Get the third digit
    int digit4 = n % 10;          // Get the fourth digit

    int sum = digit1 + digit2 + digit3 + digit4;

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}
