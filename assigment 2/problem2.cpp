#include <iostream>
#include <omp.h>
#include <random>

using namespace std;

int main() {
    int num_points;

    // Get user input
    cout << "Enter the number of random points: ";
    cin >> num_points;

    int inside_circle = 0; // Points inside the unit circle

    // Start timing
    double start_time = omp_get_wtime();

#pragma omp parallel
    {
        // Each thread has its own random engine
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(0.0, 1.0);

        int local_inside_circle = 0;

#pragma omp for
        for (int i = 0; i < num_points; ++i) {
            double x = dis(gen);
            double y = dis(gen);
            if (x * x + y * y <= 1.0) {
                local_inside_circle++;
            }
        }

#pragma omp atomic
        inside_circle += local_inside_circle;
    }

    // End timing
    double end_time = omp_get_wtime();
    double pi_estimate = (double)inside_circle / num_points * 4;
    cout << "Estimated value of Pi: " << pi_estimate << endl;
    cout << "Time taken for Pi Calculation: " << (end_time - start_time) << " seconds." << endl;

    return 0;
}
