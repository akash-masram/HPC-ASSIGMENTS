#include <iostream>
#include <omp.h>
using namespace std;

int main() {
#pragma omp parallel
    {
        int thread_id = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
#pragma omp single
        {
            cout << "Number of threads: " << num_threads << endl;
        }

        // Family member names
        string family_members[] = { "akash", "shubham", "tejas", "mittal" };
        string job_ids[] = { "Engineer", "Doctor", "Artist", "Teacher" };

        if (thread_id < 4) {
            cout << "Thread " << thread_id << " -> Name: " << family_members[thread_id]
                << ", Job ID: " << job_ids[thread_id] << endl;
        }
    }
    return 0;
}
