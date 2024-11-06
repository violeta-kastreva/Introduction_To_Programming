#include <iostream>


int main() {
    int array[2][3] = {{0,},};

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            array[i][j] = 10*(i+1) + j+1;
            // std::cout << array[i][j] << ' ';
            std::cout << *(*(array + i) + j) << ' ';
        }
        std::cout << '\n';
    }

    for (int i = 0; i < 6; i++) {
        // std::cout << array[0][i] << ' ';
        std::cout << *(*array + i) << ' ';
    }

    return 0;
}