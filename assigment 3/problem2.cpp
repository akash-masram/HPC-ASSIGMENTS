#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;

void matrix_addition(vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int size) {
#pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main() {
    vector<int> sizes = { 250, 500, 750, 1000, 2000 };
    for (int size : sizes) {
        vector<vector<int>> A(size, vector<int>(size)), B(size, vector<int>(size)), C(size, vector<int>(size));

        // Initialize matrices
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                A[i][j] = rand() % 10;
                B[i][j] = rand() % 10;
            }
        }

        double start_time = omp_get_wtime();
        matrix_addition(A, B, C, size);
        double end_time = omp_get_wtime();

        cout << "Matrix size: " << size << " x " << size << endl;
        cout << "Time taken: " << (end_time - start_time) << " seconds" << endl;
    }

    return 0;
}
