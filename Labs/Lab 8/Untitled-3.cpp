#include <iostream>

using namespace std;

constexpr int QUEUE_SIZE = 10;

// Function prototypes
void enqueue(int arr[], int& front, int& rear, int& count, int item);
int dequeue(int arr[], int& front, int& rear, int& count);
bool isEmpty(int count);
bool isFull(int count);
bool checkProductEven(int arr[], int& front, int& rear, int& count);

int main() {
    int arr[QUEUE_SIZE];
    int front = 0, rear = 0, count = 0;

    // Enqueue three numbers onto the queue
    for (int i = 1; i <= 3; ++i) {
        enqueue(arr, front, rear, count, i);
    }

    // Remove two numbers and determine if their product is even
    if (checkProductEven(arr, front, rear, count)) {
        cout << "The product of the dequeued numbers is even.\n";
    } else {
        cout << "The product of the dequeued numbers is not even.\n";
    }

    // Attempt to remove two more numbers
    for (int i = 0; i < 2; ++i) {
        int num = dequeue(arr, front, rear, count);
        if (num == -1) {
            cout << "Queue underflow. No more elements to dequeue.\n";
            break;
        }
    }

    // Reloading the queue with 10 integers
    for (int i = 1; i <= 10; ++i) {
        enqueue(arr, front, rear, count, i);
    }

    // Dequeue and print all the values
    cout << "Dequeued values: ";
    while (!isEmpty(count)) {
        cout << dequeue(arr, front, rear, count) << " ";
    }
    cout << endl;

    // Store all the multiples of 5 in an array and reload the queue with them
    int multiplesOf5[QUEUE_SIZE];
    int index = 0;
    for (int i = 1; i <= 10; ++i) {
        if (i % 5 == 0) {
            multiplesOf5[index++] = i;
        }
    }

    // Reload the queue with the multiples of 5 from the array
    for (int i = 0; i < index; ++i) {
        enqueue(arr, front, rear, count, multiplesOf5[i]);
    }

    // Print the new queue elements
    cout << "New queue elements: ";
    while (!isEmpty(count)) {
        cout << dequeue(arr, front, rear, count) << " ";
    }
    cout << endl;

    return 0;
}

// Function to enqueue an item into the queue
void enqueue(int arr[], int& front, int& rear, int& count, int item) {
    if (!isFull(count)) {
        arr[rear] = item;
        rear = (rear + 1) % QUEUE_SIZE;
        count++;
    }
}

// Function to dequeue an item from the queue
int dequeue(int arr[], int& front, int& rear, int& count) {
    if (!isEmpty(count)) {
        int item = arr[front];
        front = (front + 1) % QUEUE_SIZE;
        count--;
        return item;
    }
    return -1;
}

// Function to check if the queue is empty
bool isEmpty(int count) {
    return count == 0;
}

// Function to check if the queue is full
bool isFull(int count) {
    return count == QUEUE_SIZE;
}

// Function to remove two numbers and determine if their product is an even number
bool checkProductEven(int arr[], int& front, int& rear, int& count) {
    int num1 = dequeue(arr, front, rear, count);
    int num2 = dequeue(arr, front, rear, count);
    if (num1 != -1 && num2 != -1) {
        int product = num1 * num2;
        return product % 2 == 0;
    }
    return false;
}
