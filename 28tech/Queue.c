/*

Static array-based queue: arrays can be simply used to manipulate collections of items.
Dynamic array-based queue: malloc() is capable of representing a queue.
Linked queue: A very flexible mechanism for dynamic memory management is provided by pointers.

*/

#include <stdio.h>
#include <stdlib.h>


// Static Array-Based Queues
/*
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

    return 0;
}
*/

//---------------------------------------------------------------------------------------------

// A dynamic array-based Queue improves the static array-based implementation.


// Dynamic array-based Queue

/*
struct Queue {
    int front, back;
    int capacity;
    int *val;
};
typedef struct Queue Queue;

// init(): this function allows creating an empty queue.
void init(Queue *q, int N) {
    q->back = 0;
    q->front = 0;
    q->capacity = N;
    q->val = (int *)malloc(N * sizeof(int));
    if (q->val == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

// isEmpty(): check if the queue is empty.
int isEmpty(Queue *q) {
    return (q->front == q->back);
}

// isFull(): check if the queue is full.
int isFull(Queue *q) {
    return (q->back - q->front == q->capacity);
}

// enqueue(): add a new item at the back of the queue.
int enqueue(Queue *q, int newData) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return 0;
    }

    q->val[q->back] = newData;
    q->back++;
    return 1;
}

// dequeue(): remove the front item of the queue.
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0;
    } else {
        for (int i = 1; i < q->back; i++) {
            q->val[i - 1] = q->val[i];
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
    return q->val[q->front];
}

// display(): display the content of a queue.
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = q->front; i < q->back; i++) {
            printf("%d ", q->val[i]);
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    int capacity = 5;
    Queue myQueue;
    init(&myQueue, capacity);

    // Perform operations on the queue...
    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    display(&myQueue);

    printf("Front element: %d\n", front(&myQueue));

    dequeue(&myQueue);

    display(&myQueue);

    // Free allocated memory when done
    free(myQueue.val);

    return 0;
}
*/
//---------------------------------------------------------------------------------------------

// Queue Implementation with Linked Lists

// Define the data type for the queue
typedef int DataType; // You can change this to your desired data type

// Node structure for linked list
typedef struct Node {
    DataType data;
    struct Node *next;
} Node;

// Queue structure
typedef struct Queue {
    Node *pFront, *pBack;
    int size;
} Queue;

// Initialize the queue
void init(Queue *q) {
    q->size = 0;
    q->pFront = q->pBack = NULL;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return (q->pFront == NULL);
}

// Enqueue operation: add a new item to the back of the queue
void enqueue(Queue *q, DataType val) {
    Node *p = (Node *)malloc(sizeof(Node));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    p->data = val;
    p->next = NULL;

    if (isEmpty(q)) {
        q->pFront = q->pBack = p;
    } else {
        q->pBack->next = p;
        q->pBack = p;
    }

    q->size++;
}

// Dequeue operation: remove the front item from the queue
int dequeue(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return 0;
    } else {
        Node *temp = q->pFront;
        q->pFront = q->pFront->next;
        free(temp);

        if (q->pFront == NULL) {
            q->pBack = NULL;
        }

        q->size--;
        return 1;
    }
}

// Retrieve the front item of the queue
DataType front(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return -1; // Assuming -1 represents an invalid value
    }
    return q->pFront->data;
}

// Check if the queue is full
int isFull(Queue *q) {
    // Assuming a linked list implementation doesn't have a predefined maximum capacity
    return 0;
}

// Display the content of the queue
void display(Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        Node *current = q->pFront;
        while (current != NULL) {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    // Example usage
    Queue myQueue;
    init(&myQueue);

    enqueue(&myQueue, 10);
    enqueue(&myQueue, 20);
    enqueue(&myQueue, 30);

    printf("Front element: %d\n", front(&myQueue));
    display(&myQueue);

    if (isFull(&myQueue)) {
        printf("Queue is full.\n");
    } else {
        printf("Queue is not full.\n");
    }

    return 0;
}

