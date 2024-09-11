#include <iostream>
#include <omp.h>
#include <limits.h>
using namespace std;

#define N 1000 // Define the size of the vectors

// Function to compute the minimum scalar product
int min_scalar_product(int* a, int* b, int size) {
    int min_product = INT_MAX;

#pragma omp parallel
    {
        int local_min = INT_MAX;
#pragma omp for
        for (int i = 0; i < size; i++) {
            int product = a[i] * b[i];
            if (product < local_min) {
                local_min = product;
            }
        }

#pragma omp critical
        {
            if (local_min < min_product) {
                min_product = local_min;
            }
        }
    }

    return min_product;
}

int main() {
    int a[N], b[N];

    // Initialize vectors
    for (int i = 0; i < N; i++) {
        a[i] = rand() % 100;
        b[i] = rand() % 100;
    }

    double start_time = omp_get_wtime();
    int result = min_scalar_product(a, b, N);
    double end_time = omp_get_wtime();

    cout << "Minimum Scalar Product: " << result << endl;
    cout << "Time taken: " << (end_time - start_time) << " seconds" << endl;

    return 0;
}
