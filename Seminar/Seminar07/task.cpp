#include <iostream>

const int ROWS = 3;
const int COLS = 4;

void readMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cin >> mat[i][j];
        }
    }
}

void printMatrix(int** mat, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << mat[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

void transpose(int** source, int** dest, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[j][i] = source[i][j];
        }
    }
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// source[n][n]
void rotate90(int** source, int** dest, int rows, int cols) {
    transpose(source, dest, rows, cols);

    swap(rows, cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols / 2; j++) {
            swap(dest[i][j], dest[i][cols-1-j]);
        }
    }
}

bool inBounds(int curRow, int curCol, int startRow, int startCol, int endRow, int endCol) {
    return curRow >= startRow && curCol >= startCol && curRow < endRow && curCol < endCol;
}

void printMatrixSpiral(int** mat, int rows, int cols) {
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int dbi[4] = {0,3,2,1};
    int dbd[4] = {1,-1,-1,1};

    int bounds[4] = {0, 0, rows, cols};

    int curRow = 0, curCol = -1;
    bool good = true;
    for (int d = 0; good; d++) {
        int di = d % 4;

        good = false;
        while (inBounds(curRow + dr[di], curCol + dc[di], bounds[0], bounds[1], bounds[2], bounds[3])) {
            curRow += dr[di];
            curCol += dc[di];
            std::cout << mat[curRow][curCol] << ' ';
            good = true;
        }

        bounds[dbi[di]] += dbd[di];
    }
}

void printMatrixSpiralAlt(int** mat, int rows, int cols) {
    int startRow = 0, startCol = 0, endRow = rows, endCol = cols;
    int curRow = 0, curCol = -1;
    bool good = true;
    while (good) {
        good = false;

        while (inBounds(curRow, curCol+1, startRow, startCol, endRow, endCol)) {
            curCol++;
            std::cout << mat[curRow][curCol] << ' ';
            good = true;
        }
        startRow++;

        while (inBounds(curRow+1, curCol, startRow, startCol, endRow, endCol)) {
            curRow++;
            std::cout << mat[curRow][curCol] << ' ';
            good = true;
        }
        endCol--;

        while (inBounds(curRow, curCol-1, startRow, startCol, endRow, endCol)) {
            curCol--;
            std::cout << mat[curRow][curCol] << ' ';
            good = true;
        }
        endRow--;

        while (inBounds(curRow-1, curCol, startRow, startCol, endRow, endCol)) {
            curRow--;
            std::cout << mat[curRow][curCol] << ' ';
            good = true;
        }
        startCol++;
    }
}

int main() {
    int mat[ROWS][COLS];
    int* ptrMat[ROWS];
    for (int i = 0; i < ROWS; i++) {
        ptrMat[i] = mat[i];
    }
    readMatrix(ptrMat, ROWS, COLS);

    int dest[COLS][ROWS];
    int* ptrDest[COLS];
    for (int i = 0; i < COLS; i++) {
        ptrDest[i] = dest[i];
    }

    // transpose(ptrMat, ptrTransposed, ROWS, COLS);
    // std::cout << "Transposed:\n";
    // printMatrix(ptrTransposed, COLS, ROWS);

    // rotate90(ptrMat, ptrDest, ROWS, COLS);
    // std::cout << "Rotated 90 degrees:\n";
    // printMatrix(ptrDest, COLS, ROWS);

    printMatrixSpiralAlt(ptrMat, ROWS, COLS);

    return 0;
}

/*
1 2 3 4
5 6 7 8
9 10 11 12

1 2 3 4 8 12 11 10 9 5 6 7
*/

/*
1 2  3  4
5 6  7  8
9 10 11 12
13 14 15 16

13 9 5  1
14 10 6 2
15 11 7 3
16 12 8 4
*/