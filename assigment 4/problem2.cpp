#include <iostream>
#include <omp.h>
#include <queue>
using namespace std;

queue<int> buffer;
const int bufferSize = 5; // Maximum size of buffer
int itemCount = 0;

void producer(int itemsToProduce) {
#pragma omp critical
    {
        if (buffer.size() < bufferSize) {
            for (int i = 0; i < itemsToProduce; i++) {
                int item = ++itemCount;
                buffer.push(item);
                cout << "Produced: " << item << endl;
            }
        }
        else {
            cout << "Buffer is full. Producer is waiting." << endl;
        }
    }
}

void consumer(int itemsToConsume) {
#pragma omp critical
    {
        if (!buffer.empty()) {
            for (int i = 0; i < itemsToConsume && !buffer.empty(); i++) {
                int item = buffer.front();
                buffer.pop();
                cout << "Consumed: " << item << endl;
            }
        }
        else {
            cout << "Buffer is empty. Consumer is waiting." << endl;
        }
    }
}

int main() {
    int itemsToProduce, itemsToConsume;

    cout << "Enter number of items to produce: ";
    cin >> itemsToProduce;
    cout << "Enter number of items to consume: ";
    cin >> itemsToConsume;

#pragma omp parallel sections
    {
#pragma omp section
        producer(itemsToProduce);

#pragma omp section
        consumer(itemsToConsume);
    }

    return 0;
}
