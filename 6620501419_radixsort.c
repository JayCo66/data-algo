#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the maximum queue size
#define MAX 20

// Define a structure for Queue
struct Queue {
    int front, rear;
    int arr[MAX];
};

// Function to initialize the queue
void initQueue(struct Queue* q) {
    q->front = q->rear = -1;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* q) {
    return q->front == -1;
}

// Function to enqueue an element
void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) {
        printf("Queue overflow\n");
        return; // Queue is full
    }

    if (q->front == -1)
        q->front = 0;

    q->arr[++q->rear] = value;
}

// Function to dequeue an element
int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue underflow\n");
        return -1; // Queue is empty
    }

    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1; // Reset the queue after last element
    } else {
        q->front++;
    }

    return data;
}

// A utility function to get the maximum value in num[]
int getMax(int num[], int n) {
    int max = num[0];
    for (int i = 1; i < n; i++)
        if (num[i] > max)
            max = num[i];
    return max;
}

// Function to perform Radix Sort using Queues
void radixSort(int num[], int n) {
    struct Queue queues[10]; // Create 10 queues for digits 0-9
    for (int i = 0; i < 10; i++) {
        initQueue(&queues[i]); // Initialize each queue
    }

    int max = getMax(num, n); // Get the maximum number
    int exp = 1; // Initialize exponent for least significant digit

    while (max / exp > 0) {
        // Distribute the numbers into the corresponding queues based on the current digit
        for (int i = 0; i < n; i++) {
            int digit = (num[i] / exp) % 10;
            enqueue(&queues[digit], num[i]);
        }

        // Collect the numbers back from the queues in order
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!isEmpty(&queues[i])) {
                num[index++] = dequeue(&queues[i]);
            }
        }

        exp *= 10; // Move to the next significant digit
    }
}

int main() {
    int i, n = 20;
    srand((unsigned) time(NULL)); // Initializes random number generator
    int num[n];

    printf("Numbers before sorting:\n");
    for (i = 0; i < n; i++) {
        num[i] = rand() % 32768; // random number between 0-32767
        printf("%d ", num[i]);
    }
    printf("\n");

    // Sorting using Radix Sort with Queues
    radixSort(num, n);

    printf("Numbers after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}