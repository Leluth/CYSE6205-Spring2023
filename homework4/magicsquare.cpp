/*----------------------------------------------------------------
Copyright (c) 2023 Author: Jagadeesh Vasudevamurthy
file: magicsquare.cpp
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file has magicsquare class definition
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
NOTHING CAN BE CHANGED
-----------------------------------------------------------------*/
#include "magicsquare.h"

/*----------------------------------------------------------------
WRITE CODE BELOW
-----------------------------------------------------------------*/
void magicsquare::print_magic_square(const int n){
    vector<vector<int>> matrix;
    allocate(n, matrix);
    init(n, matrix);
    magic_square(n, matrix);
    assert(verify(n, matrix));
    print(n, matrix);
}

void magicsquare::allocate(const int n, vector<vector<int>> &matrix){
    matrix.resize(n, vector<int>(n));
}

void magicsquare::init(const int n, vector<vector<int>> &matrix){
    for (int i = 0; i < n; i++) {
        fill(matrix[i].begin(), matrix[i].end(), 0);
    }
}

void magicsquare::magic_square(const int n, vector<vector<int>> &matrix){
    int x = 0, y = n / 2;
    int number = 0;
    while (number < n * n) {
        if (x < 0 || x >= n || y < 0 || y >= n) {
            x = (x + n) % n;
            y = (y + n) % n;
        }
        if (matrix[x][y]) {
            x += 2;
            y++;
            continue;
        }
        number++;
        matrix[x][y] = number;
        x--;
        y--;
    }
}

bool magicsquare::verify(const int n, vector<vector<int>> &matrix){
    const int sum = (n * n + 1) / 2 * n;
    vector<int> rows(n, 0), cols(n, 0);
    int left = 0, right = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            rows[i] += matrix[i][j];
            cols[j] += matrix[i][j];
            if(i == j) {
                left += matrix[i][j];
            }
            if(i + j == n-1) {
                right += matrix[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (rows[i] != sum || cols[i] != sum) {
            return false;
        }   
    }
    return left == sum && right == sum;
}

void magicsquare::print(const int n, vector<vector<int>> &matrix){
    const int sum = (n * n + 1) * n / 2;
    cout << "--------------------------------" << endl;
    cout << "Magic square for n = " << n << " sum = " << sum << endl;
    if (n < 11) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%5d", matrix[i][j]);
            }
            cout << endl;
        }
    }
}
//EOF
