
#include <iostream>
#include <vector>
#include <omp.h>
using namespace std;

void matrix_multiplication(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    vector<int> sizes = { 250, 500, 750, 1000, 2000 };
    for (int size : sizes) {
        vector<vector<int>> A(size, vector<int>(size, 1)), B(size, vector<int>(size, 2)), C(size, vector<int>(size, 0));

        // Serial matrix multiplication
        double start_time = omp_get_wtime();
        matrix_multiplication(A, B, C, size);
        double end_time = omp_get_wtime();

        cout << "Matrix size: " << size << " x " << size << ", Serial time: " << (end_time - start_time) << " seconds" << endl;
    }
    return 0;
}
