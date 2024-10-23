#include <iostream>


int digitsCount(int num) {
    int digits = 0;
    do {
        digits++;
        num /= 10;
    } while (num > 0);
    
    return digits;
}

int power(int base, int power) {
    int res = 1;

    while (power > 0) {
        res *= base;
        power--;
    }

    return res;
}

// 123 ? 1^3+2^3+3^3 == 123
bool isPerfect(int num) {
    int originalNum = num;
    int digits = digitsCount(num);

    int sum = 0;
    do {
        int curDigit = num % 10;
        sum += power(curDigit, digits);
        num /= 10;
    } while (num > 0);

    return sum == originalNum;
}

void printPerfect(int start, int end) {
    for (int current = start; current <= end; current++) {
        if (isPerfect(current)) {
            std::cout << current << ' ';
        }
    }
}

int main() {
    int start, end;
    std::cin >> start >> end;

    printPerfect(start, end);

    return 0;
}