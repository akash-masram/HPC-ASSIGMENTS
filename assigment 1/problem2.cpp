#include <iostream>
#include <omp.h>

int main() {
    int num_threads;

    // Ask user for the number of threads
    std::cout << "Enter the number of threads: ";
    std::cin >> num_threads;

    // Print "Hello, World" sequentially
    std::cout << "Sequential Execution:" << std::endl;
    for (int i = 0; i < num_threads; ++i) {
        std::cout << "Hello, World" << std::endl;
    }

    // Set the number of threads for parallel execution
    omp_set_num_threads(num_threads);

    // Print "Hello, World" in parallel
    std::cout << "Parallel Execution:" << std::endl;
    #pragma omp parallel
    {
        std::cout << "Hello, World from thread " << omp_get_thread_num() << std::endl;
    }

    return 0;
}
