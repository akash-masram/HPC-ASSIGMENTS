#include <iostream>
#include <omp.h>
using namespace std;

#define SIZE 200

void vector_addition_static(int* vec, int scalar) {
#pragma omp parallel for schedule(static, 10)
    for (int i = 0; i < SIZE; i++) {
        vec[i] += scalar;
    }
}

void vector_addition_dynamic(int* vec, int scalar) {
#pragma omp parallel for schedule(dynamic, 10)
    for (int i = 0; i < SIZE; i++) {
        vec[i] += scalar;
    }
}

int main() {
    int vec[SIZE];
    int scalar = 5;

    // Initialize vector
    for (int i = 0; i < SIZE; i++) {
        vec[i] = i;
    }

    double start_time, end_time;

    // Static scheduling
    start_time = omp_get_wtime();
    vector_addition_static(vec, scalar);
    end_time = omp_get_wtime();
    cout << "Static scheduling time: " << (end_time - start_time) << " seconds" << endl;

    // Reset vector
    for (int i = 0; i < SIZE; i++) {
        vec[i] = i;
    }

    // Dynamic scheduling
    start_time = omp_get_wtime();
    vector_addition_dynamic(vec, scalar);
    end_time = omp_get_wtime();
    cout << "Dynamic scheduling time: " << (end_time - start_time) << " seconds" << endl;

    return 0;
}
