#include <iostream>


int main() {
    int x;
    std::cin >> x;

    // Make sure x >= 0
    if (x < 0) {
        x = -x;
    }

    int bestDigitCount = 1;
    int bestDigit = x%10;
    for (int curDigit = 0; curDigit <= 9; ++curDigit) {
        int xCopy = x;
        int curDigitCount = 0;

        do {
            int lastDigit = xCopy % 10;

            if (lastDigit == curDigit) {
                ++curDigitCount;
            }

            xCopy /= 10;
        } while (xCopy > 0);

        if (curDigitCount > bestDigitCount) {
            bestDigitCount = curDigitCount;
            bestDigit = curDigit;
        }
    }

    std::cout << "Digit '" << bestDigit << "' occurs " << bestDigitCount << " times\n";

    return 0;
}