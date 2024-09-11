#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    const int SIZE = 1000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }
    
    int total_sum = 0;

    #pragma omp parallel
    {
        int local_sum = 0;

        #pragma omp for
        for (int i = 0; i < SIZE; i++) {
            local_sum += arr[i];
        }

        #pragma omp critical
        {
            total_sum += local_sum;
        }
    }

    cout << "Total sum: " << total_sum << endl;
    return 0;
}
