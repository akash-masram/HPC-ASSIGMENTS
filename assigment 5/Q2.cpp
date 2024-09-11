#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int sum = 0;

#pragma omp parallel reduction(+:sum)
    {
        int thread_id = omp_get_thread_num();
        int square = thread_id * thread_id;

#pragma omp critical
        {
            cout << "Thread " << thread_id << " square: " << square << endl;
        }

        sum += square;
    }

    cout << "Sum of squares: " << sum << endl;
    return 0;
}
