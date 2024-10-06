#include <iostream>

int main() {
    int a, b;
    std::cin >> a >> b;
  
    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;
    std::cout << "Quotient: " << a / b << std::endl;
    std::cout << "Remainder: " << a % b << std::endl;

    return 0;
}
