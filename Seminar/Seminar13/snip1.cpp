#include <iostream>
#include <cstring>


void f() {
    static int counter =  1;
    std::cout << counter << '\n';
    counter++;
}

int main() {
    f();
    f();
    f();
    f();
    f();

    return 0;
}