#include <iostream>
using namespace std;

int main() {
    const int SIZE = 1000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++) {
        arr[i] = i + 1;
    }

    int total_sum = 0;
    for (int i = 0; i < SIZE; i++) {
        total_sum += arr[i];
    }

    cout << "Total sum: " << total_sum << endl;
    return 0;
}
