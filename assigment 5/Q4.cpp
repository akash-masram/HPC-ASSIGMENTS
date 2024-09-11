#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    int total_sum = 0;

    #pragma omp parallel shared(total_sum)
    {
        int partial_sum = 0;

        #pragma omp for
        for (int i = 1; i <= 20; i++) {
            partial_sum += i;
        }

        #pragma omp critical
        {
            total_sum += partial_sum;
        }
    }

    cout << "Total sum: " << total_sum << endl;
    return 0;
}
