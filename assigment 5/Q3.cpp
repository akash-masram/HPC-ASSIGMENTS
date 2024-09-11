#include <iostream>
#include <omp.h>
using namespace std;

int main() {
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int Aryabhatta = 10; // Private to each thread
        int result = thread_id * Aryabhatta;

        cout << "Thread " << thread_id << " result: " << result << endl;
    }
    return 0;
}
