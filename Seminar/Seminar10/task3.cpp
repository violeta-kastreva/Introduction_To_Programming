#include <iostream>
#include <fstream>


int main() {
    int n;
    std::cin >> n;

    std::ofstream out("out3.txt");
    if (!out) {
        std::cerr << "Could not open a file for writing.";

        return 1;
    }

    for (int i = 1; i <= n; i++) {
        out << i << '\n';
    }

    out.close();

    return 0;
}