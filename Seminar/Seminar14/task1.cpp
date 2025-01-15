#include <iostream>

bool even(int n);
bool odd(int n);

bool even(int n) {
    // Base
    if (n < 2) {
        return n%2 == 0;
    }

    return odd(n-1);
}

bool odd(int n) {
    // Base
    if (n < 2) {
        return n%2 == 1;
    }

    return even(n-1);
}

// Linear Tail recursion
void f_tail(int n) {
    if (n == 0) {
        return;
    }

    std::cout << n << '\n';

    f_tail(n-1);
}

// Linear Head recursion
void f_head(int n) {
    if (n == 0) {
        return;
    }

    f_head(n-1);

    std::cout << n << '\n';
}

// Branched
int fib(int n) {
    if (n < 2) {
        return n;
    }

    return fib(n-1) + fib(n-2);
}

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    std::cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << '\n';
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

long long pow(long long base, long long power) {
    if (power == 0) {
        return 1;
    }

    long long subRes = pow(base, power/2);
    subRes = subRes * subRes;

    if (power % 2 == 1) {
        return base * subRes;
    }

    return subRes;
}

void subSets(int* set, int n, int* subset, int m) {
    // std::cout << n << ' ' << m << '\n';
    if (n == 0) {
        for (int i = 0; i < m; i++) {
            std::cout << subset[i] << ' ';
        }
        std::cout << '\n';
        return;
    }

    // Dont take
    subSets(set+1, n-1, subset, m);

    // Take
    subset[m] = set[0];
    subSets(set+1, n-1, subset, m+1);
}

// Driver Code
int main() {
    // f_tail(5);
    // f_head(5);

    // std::cout << fib(0) << '\n';
    // std::cout << fib(1) << '\n';
    // std::cout << fib(2) << '\n';
    // std::cout << fib(3) << '\n';
    // std::cout << fib(4) << '\n';
    // std::cout << fib(5) << '\n';

    // towerOfHanoi(3, 'A', 'C', 'B');

    // std::cout << pow(2,0) << '\n';
    // std::cout << pow(2,1) << '\n';
    // std::cout << pow(2,2) << '\n';
    // std::cout << pow(2,3) << '\n';
    // std::cout << pow(2,4) << '\n';
    // std::cout << pow(2,5) << '\n';
    // std::cout << pow(2,6) << '\n';
    // std::cout << pow(2,7) << '\n';
    // std::cout << pow(2,8) << '\n';

    int arr[] = {1,2,3};
    int temp[3];
    subSets(arr, 3, temp, 0);

    return 0;
}