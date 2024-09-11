#include <iostream>
#include <omp.h>
#include <vector>

using namespace std;

int main() {
    int N;
    float scalar;

    // Get user input
    cout << "Enter the size of the vector (N): ";
    cin >> N;
    cout << "Enter the scalar value to add: ";
    cin >> scalar;

    vector<float> vec(N, 1.0f); // Initialize vector with value 1.0

    // Start timing
    double start_time = omp_get_wtime();

    #pragma omp parallel for
    for(int i = 0; i < N; ++i) {
        vec[i] += scalar;
    }

    // End timing
    double end_time = omp_get_wtime();
    cout << "Time taken for Vector Scalar Addition: " << (end_time - start_time) << " seconds." << endl;

    return 0;
}
