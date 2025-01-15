#include <iostream>

// Branched recursion function
void fun(int n) {
    if (n > 0) {
        std::cout << n << " ";

        // Last statement in the function
        fun(n - 1);
    }
}

// Driver Code
int main() {
    int x = 3;
    fun(x);
    return 0;
}