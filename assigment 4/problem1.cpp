#include <iostream>
#include <omp.h>
using namespace std;

// Function to compute Fibonacci numbers
int fibonacci(int n) {
    if (n <= 1) return n;
    int fib1 = 0, fib2 = 1, fib_next;
    #pragma omp parallel for shared(fib1, fib2) ordered
    for (int i = 2; i <= n; i++) {
        #pragma omp ordered
        {
            fib_next = fib1 + fib2;
            fib1 = fib2;
            fib2 = fib_next;
        }
    }
    return fib2;
}

int main() {
    int n;
    cout << "Enter the number for Fibonacci computation: ";
    cin >> n;

    double start_time = omp_get_wtime();
    int result = fibonacci(n);
    double end_time = omp_get_wtime();

    cout << "Fibonacci of " << n << " is: " << result << endl;
    cout << "Time taken: " << (end_time - start_time) << " seconds" << endl;

    return 0;
}
