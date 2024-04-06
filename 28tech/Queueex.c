// LIFO : STACK : last in first out
// FIFO FIFO: QUEUE : first in first out

#include <stdio.h>
#include <stdlib.h>


// Static Array-Based Queues

#define CAPACITY 100 // Assuming a fixed capacity for the queue

struct Queue {
    int data[CAPACITY];
    int front, back;
    // front is optional
};
typedef struct Queue Queue;

// init(): this function allows creating an empty queue.
void init(Queue *q) {
    q->front = 0;
    q->back = 0;
}

// isEmpty(): this operation verifies that a queue is empty.
int isEmpty(Queue *q) {
    return (q->back == q->front);
}

// length(): this operation returns the queue size.
int length(Queue *q) {
    return q->back - q->front;
}

// There are three cases to be proceeded for enqueue(): the queue is full, empty, and has at least one item
int enqueue(Queue *q, int newData) {
    if (length(q) == CAPACITY) {
        printf("Queue is full!\n");
        return 0;
    }

    q->data[q->back] = newData;
    q->back++;
    return 1;
}

// Two possible cases for dequeue() must be manipulated: when the queue is empty or not empty.
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        for (int i = 1; i < length(q); i++) {
            q->data[i - 1] = q->data[i];
        }
        q->back--;
        return 1;
    }
}

// front(): retrieve the front item of the queue.
int front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Assuming -1 represents an invalid value
    }
    return q->data[q->front];
}

// isFull(): check if the queue is full.
int isFull(Queue *q) {
    return (length(q) == CAPACITY);
}

// display(): display the content of a queue.
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i < q->back; i++) {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

int main() {
    Queue myQueue;
    init(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    printf("Front element: %d\n", front(&myQueue));

    dequeue(&myQueue);

    display(&myQueue);

    printf("Front element: %d\n", front(&myQueue));

    printf("Queue length : %d \n", length(&myQueue));

    return 0;
}