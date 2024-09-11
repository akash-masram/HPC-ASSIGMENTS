#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int main() {
    int N;
    cout << "Enter the size of the matrix (NxN) and vector (N): ";
    cin >> N;

    vector<vector<int>> A(N, vector<int>(N, 0));
    vector<int> B(N, 0);
    vector<int> C(N, 0);

    cout << "Enter matrix A values:" << endl;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }

    cout << "Enter vector B values:" << endl;
    for (int i = 0; i < N; ++i) {
        cout << "B[" << i << "]: ";
        cin >> B[i];
    }

    #pragma omp parallel for
    for (int i = 0; i < N; ++i) {
        C[i] = 0;
        for (int j = 0; j < N; ++j) {
            C[i] += A[i][j] * B[j];
        }
    }

    cout << "Vector C (result of A * B):" << endl;
    for (int i = 0; i < N; ++i) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
