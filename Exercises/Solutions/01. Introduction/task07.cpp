#include <iostream>

int main() {
    const double PI = 3.14159;
    double r;
    std::cin >> r;
    double circumference = 2 * PI * r;
    double area = PI * r * r;
    std::cout << "Circumference: " << circumference << std::endl;
    std::cout << "Area: " << area << std::endl;
    return 0;
}
