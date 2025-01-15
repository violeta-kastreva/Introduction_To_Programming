#include <iostream>

// Linear recursive function
void fun(int n) {
    if (n > 0) {
        // First statement in the function
        fun(n - 1);

        std::cout << " "<< n;
    }
}

// Driver code
int main() {
    int x = 3;
    fun(x);
    return 0;
}