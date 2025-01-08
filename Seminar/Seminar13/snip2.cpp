#include <iostream>
#include <cstring>


const std::size_t MAX_CAPACITY = 1024 + 1;

int main() {
    char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    char str2[] = "Hello";
    const char* str3 = "Hello";

    char str4[MAX_CAPACITY];
    std::cin >> str4;

    std::cin.ignore();

    char str5[MAX_CAPACITY];
    std::cin.getline(str5, MAX_CAPACITY);

    std::cout << str1 << '\n';
    std::cout << str2 << '\n';
    std::cout << str3 << '\n';
    std::cout << str4 << '\n';
    std::cout << str5 << '\n';

    return 0;
}