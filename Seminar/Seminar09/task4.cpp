#include <iostream>


void deallocSpecial(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        delete[] mat[i];
    }
    delete[] mat;
}

int** allocSpecial(int n) {
    if (n < 0) {
        return nullptr;
    }

    int** mat = new(std::nothrow) int*[n];
    if (mat == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = new(std::nothrow) int[n-i];
        if (mat[i] == nullptr) {
            deallocSpecial(mat, i);
            return nullptr;
        }

        for (int j = 0; j < n-i; j++) {
            mat[i][j] = j+1;
        }
    }

    return mat;
}

void print(int** mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

int main() {
    int n;
    std::cin >> n;

    int** mat = allocSpecial(n);
    if (mat == nullptr) {
        return 1;
    }

    print(mat, n);

    deallocSpecial(mat, n);

    return 0;
}