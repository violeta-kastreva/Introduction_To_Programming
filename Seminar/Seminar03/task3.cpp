#include <iostream>


// No duplicates
int main() {
    int x;
    std::cin >> x;

    // Make sure x >= 0
    if (x < 0) {
        x = -x;
    }

    // For each digit
    for (int digit = 0; digit <= 9; digit += 2) {
        // DONT MODIFY x
        int xCopy = x;

        do {
            int lastDigit = xCopy % 10;

            if (lastDigit == digit) {
                std::cout << digit;
                break;
            }

            xCopy /= 10;
        } while (xCopy > 0);
    }

    return 0;
}

// With duplicates
// int main() {
//     int x;
//     std::cin >> x;

//     if (x < 0) {
//         x = -x;
//     }

//     do {
//         int lastDigit = x % 10;

//         if (lastDigit % 2 == 0) {
//             std::cout << lastDigit;
//         }

//         x /= 10;
//     } while (x > 0);

//     return 0;
// }