#include <iostream>


int* alloc1DArr(int n) {
    return new(std::nothrow) int[n];
}

void delete1DArr(int* &arr) {
    delete[] arr;
    arr = nullptr;
}

void delete2DArr(int** &mat, int n) {
    for (int i = 0; i < n; i++) {
        delete1DArr(mat[i]);
    }
    delete[] mat;
    mat = nullptr;
}

int** alloc2DArr(int n, int m) {
    int** mat = new(std::nothrow) int*[n];
    if (mat == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = alloc1DArr(m);
        if (mat[i] == nullptr) {
            delete2DArr(mat, i);
            return nullptr;
        }
    }

    return mat;
}

void delete3DArr(int*** &mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        delete2DArr(mat[i], m);
    }
    delete[] mat;
    mat = nullptr;
}

int*** alloc3DArr(int n, int m, int k) {
    int*** mat = new(std::nothrow) int**[n];
    if (mat == nullptr) {
        return nullptr;
    }

    for (int i = 0; i < n; i++) {
        mat[i] = alloc2DArr(m, k);
        if (mat[i] == nullptr) {
            delete3DArr(mat, i, m);
            return nullptr;
        }
    }

    return mat;
}

int main() {
    int*** mat = alloc3DArr(3, 2, 1);
    if (mat == nullptr) {
        return 1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 1; k++) {
                std::cin >> mat[i][j][k];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 1; k++) {
                std::cout << "mat[" << i << "][" << j << "][" << k << "] = " << mat[i][j][k] << '\n';
            }
        }
    }

    delete3DArr(mat, 3, 2);

    return 0;
}