#include <iostream>
#include <omp.h>
using namespace std;

int main() {
    #pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        if (thread_id == 0) {
            cout << "Thread " << thread_id << " prints: 2" << endl;
        } else if (thread_id == 1) {
            cout << "Thread " << thread_id << " prints: 4" << endl;
        }
    }
    return 0;
}
