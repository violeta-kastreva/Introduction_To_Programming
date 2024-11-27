#include <iostream>


void incrByOne(int num[5]) {
    if (num[0] != 0) {
        return;
    }

    int carryOver = 1;
    for (int i = 4; i >= 0; i--) {
        num[i] += carryOver;
        carryOver = num[i] / 10;
        num[i] %= 10;
    }
}

char* sumBigInts(char* num1, int n1, char* num2, int n2) {
    int n = std::max(n1, n2) + 1;
    char* res = new(std::nothrow) char[n]{};
    if (res == nullptr) {
        return nullptr;
    }

    int ni1 = n1-1, ni2 = n2-1, ni = n-1;

    char carryOver = 0;
    for (; ni1 >= 0 && ni2 >= 0;) {
        res[ni] = num1[ni1] + num2[ni2] + carryOver;
        carryOver = res[ni] / 10;
        res[ni] %= 10;

        ni1--;
        ni2--;
        ni--;
    }

    for (; ni1 >= 0;) {
        res[ni] = num1[ni1] + carryOver;
        carryOver = res[ni] / 10;
        res[ni] %= 10;

        ni1--;
        ni--;
    }

    for (; ni2 >= 0;) {
        res[ni] = num2[ni2] + carryOver;
        carryOver = res[ni] / 10;
        res[ni] %= 10;

        ni2--;
        ni--;
    }

    res[ni] = carryOver;

    return res;
}

int main() {
    char num1[] = {0, 0, 1, 1, 9, 3, 4};
    char num2[] = {0,0,0,8,7,3,6,9,0,0,9};
    // 8 7 3 8 0 9 4 3

    char* num = sumBigInts(num1, 7, num2, 11);
    for (int i = 0; i < 12; i++) {
        std::cout << (int)num[i] << ' ';
    }

    delete[] num;

    return 0;
}