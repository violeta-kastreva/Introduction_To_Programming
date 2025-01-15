#include <iostream>

const int N = 9;


void print(int arr[N][N]) {
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++)
            std::cout << arr[i][j] << " ";
        std::cout << '\n';
    }
}

void next(int &row, int &col) {
    if (col == N-1) {
        row++;
        col = 0;
    } else {
        col++;
    }
}

void prev(int &row, int &col) {
    if (col == 0) {
        row--;
        col = N-1;
    } else {
        col--;
    }
}

bool isValid(int arr[N][N], int row, int col) {
    for (int i = 0; i < N; i++) {
        if (arr[i][col] == arr[row][col] && row != i) {
            return false;
        }
        if (arr[row][i] == arr[row][col] && col != i) {
            return false;
        }
    }

    int startRow = 3*(row/3);
    int startCol = 3*(col/3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int nrow = startRow + i;
            int ncol = startCol + j;

            if (arr[nrow][ncol] == arr[row][col] && (nrow != row || ncol != col)) {
                return false;
            }
        }
    }


    return true;
}

bool solve(int arr[N][N], int row = 0, int col = 0) {
    if (row == N) {
        return true;
    }
    if (arr[row][col] != 0) {
        next(row, col);
        return solve(arr, row, col);
    }

    int old = arr[row][col];

    for (int num = 1; num <= N; num++) {
        arr[row][col] = num;
        if (!isValid(arr, row, col)) {
            continue;
        }

        next(row, col);
        if (solve(arr, row, col)) {
            return true;
        }
        prev(row, col);
    }

    arr[row][col] = old;

    return false;
}

int main(int argc, char* argv[]) {
    int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

    if (solve(grid)) {
        print(grid);
    }

    for (int i = 0; i < argc; i++) {
        std::cout << argv[i] << '\n';
    }

    return 0;
}