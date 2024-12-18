#include <iostream>
#include <bitset>

const unsigned char flagA = 0b00000001;
const unsigned char flagB = 0b00000010;
const unsigned char flagC = 0b00000100;
const unsigned char flagD = 0b00001000;
const unsigned char flagE = 0b00010000;
const unsigned char flagF = 0b00100000;
const unsigned char flagG = 0b01000000;
const unsigned char flagH = 0b10000000;


void swap(int &x, int &y) {
    x = x ^ y;
    y = x ^ y;
    x = x ^ y;
}

bool isBitOne(int num, int idx) {
    return num & (1<<idx);
}

void setBitToOne(int &num, int idx) {
    num = num | (1<<idx);
}

void setBitToZero(int &num, int idx) {
    num = num & (~(1<<idx));
}

void flipBit(int &num, int idx) {
    num = num ^ (1<<idx);
}

void subsets() {
    int arr[8];
    for (int i = 0; i < 8; i++) {
        arr[i] = i;
    }

    for (int subset = 0; subset < (1<<8); subset++) {
        for (int idx = 0; idx < 8; idx++) {
            if (subset & (1<<idx)) {
                std::cout << arr[idx] << ' ';
            }
        }
        std::cout << '\n';
    }
}

int main() {
    // Not, And, Or

    // X = 01010101
    const unsigned char X = 0b01010101;
    // Not(X) = 10101010
    std::cout << std::bitset<8>(~X) << '\n';

    // X = 01010101
    // Y = 11110000
    const unsigned char Y = 0b11110000;
    // And(X, Y) = 01010000
    std::cout << std::bitset<8>(X & Y) << '\n';

    // X = 01010101
    // Y = 11110000
    // Or(X, Y) = 11110101
    std::cout << std::bitset<8>(X | Y) << '\n';

    // X = 01010101
    // Y = 11110000
    // XOr(X, Y) = 10100101
    std::cout << std::bitset<8>(X ^ Y) << '\n';

    // Z = 11111111
    const unsigned char Z = 0b11111111;
    std::cout << '\n' << std::bitset<8>(Z) << '\n';
    std::cout << std::bitset<8>(Z<<1) << '\n';
    std::cout << std::bitset<8>(Z<<2) << '\n';
    std::cout << std::bitset<8>(Z<<3) << '\n';
    std::cout << std::bitset<8>(Z<<4) << '\n';
    std::cout << std::bitset<8>(Z<<5) << '\n';
    std::cout << std::bitset<8>(Z<<6) << '\n';
    std::cout << std::bitset<8>(Z<<7) << '\n';
    std::cout << std::bitset<8>(Z<<8) << '\n';

    std::cout << '\n' << std::bitset<8>(Z) << '\n';
    std::cout << std::bitset<8>(Z>>1) << '\n';
    std::cout << std::bitset<8>(Z>>2) << '\n';
    std::cout << std::bitset<8>(Z>>3) << '\n';
    std::cout << std::bitset<8>(Z>>4) << '\n';
    std::cout << std::bitset<8>(Z>>5) << '\n';
    std::cout << std::bitset<8>(Z>>6) << '\n';
    std::cout << std::bitset<8>(Z>>7) << '\n';
    std::cout << std::bitset<8>(Z>>8) << '\n';

    int a = 10000, b = 10;
    swap(a,b);
    std::cout << a << ' ' << b << '\n';

    unsigned int temp = 0;
    temp = ~temp;
    temp = temp>>5;
    temp = ~temp;
    std::cout << std::bitset<32>(temp) << '\n';

    // subsets();
}