#include <iostream>

const int matrix_len = 2;

using namespace std;

int** matrixMultiply(int** matrix1, int** matrix2) {
    int** result_matrix = new int* [matrix_len] { 
        new int[matrix_len], new int[matrix_len] 
    };

    for (int i = 0; i < matrix_len; i++)
        for (int j = 0; j < matrix_len; j++)
            result_matrix[i][j] = matrix1[i][0] * matrix2[0][j] + matrix1[i][1] * matrix2[1][j];
    return result_matrix;
}

int** matrixPower(int** matrix, int power) {
    if (power == 1) return matrix;
    
    if (power == 0) return new int*[matrix_len] {
        new int[matrix_len] {1, 0},
        new int[matrix_len] {0, 1},
    };
    
    return matrixMultiply(
        matrixMultiply(
            matrixPower(matrix, power / 2), 
            matrixPower(matrix, power / 2)), 
        matrixPower(matrix, power % 2)
    );
}

int fibonachiNum(int fib_pos) {
    if (fib_pos == 1) return 0;
    if (fib_pos == 2) return 1;

    int** fib_matrix = new int* [matrix_len] {
        new int[matrix_len] {1, 0}, new int[matrix_len] {0, 0}
    };
    
    int** scale_matrix = new int* [matrix_len] {
        new int[matrix_len] {0, 1}, new int[matrix_len] {1, 1}
    };
    
    return matrixMultiply(fib_matrix, matrixPower(scale_matrix, fib_pos))[0][0];
}

int main() {
    int fib_pos; cin >> fib_pos;
    cout << "Seeking fib number is " << fibonachiNum(fib_pos) << endl;
}
