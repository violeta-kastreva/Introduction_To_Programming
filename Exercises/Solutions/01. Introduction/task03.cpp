#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;

    int diff = a - b;
    int sum = a + b;

    int diff_pow4 = diff * diff * diff * diff;

    int sum_pow2 = sum * sum;

    int result = diff_pow4 - sum_pow2;

    std::cout << result << std::endl;

    return 0;
}
