#include <iostream>


int main() {
    int x;
    std::cin >> x;

    if (x < 1) {
        std::cout << 'N';
        return 0;
    }

    while (x % 2 == 0) {
        x /= 2;
    }
    
    std::cout << (x == 1 ? 'Y' : 'N');

    return 0;
}

// int main() {
//     int x;
//     std::cin >> x;

//     int powOfTwo = 1;
//     for (; powOfTwo < x; powOfTwo = powOfTwo * 2) {
        
//     }
    
//     std::cout << (powOfTwo == x ? 'Y' : 'N');

//     return 0;
// }