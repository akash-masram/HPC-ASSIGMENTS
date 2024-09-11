#include <iostream>
using namespace std;

int main() {
    int num_cores;
    double clock_speed; // in GHz
    int flop_per_cycle; // FLOP per cycle per core

    // Ask user for processor specifications
    cout << "Enter the number of cores: ";
    cin >> num_cores;
    cout << "Enter the clock speed (in GHz): ";
    cin >> clock_speed;
    cout << "Enter the number of FLOP per cycle per core: ";
    cin >> flop_per_cycle;

    // Calculate theoretical FLOPS
    double theoretical_flops = num_cores * clock_speed * flop_per_cycle * 1e9; // in FLOPS

    cout << "Theoretical FLOPS: " << theoretical_flops << " FLOPS" << endl;

    return 0;
}
