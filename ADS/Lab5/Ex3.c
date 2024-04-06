#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node structure for a singly linked list
struct Node {
    int data;
    struct Node *next;
};

typedef struct Node *node;

node head = NULL;

// Create a new node with the given data
node makeNode(int x) {
    node tmp = (node)malloc(sizeof(struct Node));
    tmp->data = x;
    tmp->next = NULL;
    return tmp;
}

// Insert a new node at the end of the linked list
void insert(int data) {
    node new_node = makeNode(data);

    if (head == NULL) {
        head = new_node;
        return;
    }

    node last = head;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Binary Search on a linked list
int binarySearch(node list, int v) {
    int low = 0, high = 0;
    node current = list;

    while (current != NULL) {
        high++;
        current = current->next;
    }
    high--;

    while (low <= high) {
        int mid = (low + high) / 2;
        current = list;
        for (int i = 0; i < mid; i++) {
            current = current->next;
        }

        if (current->data == v)
            return mid;
        else if (current->data < v)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Perform insertion sort on the linked list
void insertion_sort() {
    node ref = NULL;
    node current = head;

    while (current != NULL) {
        node next = current->next;

        node previous = NULL;
        node temp = ref;

        int position = binarySearch(ref, current->data);

        for (int i = 0; i < position; i++) {
            previous = temp;
            temp = temp->next;
        }

        if (previous == NULL) {
            current->next = ref;
            ref = current;
        } else {
            current->next = previous->next;
            previous->next = current;
        }
        current = next;
    }
    head = ref;
}

// Display the linked list
void disp() {
    node temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n = 5; // Number of elements in the random list
    // Or you can input any n you want by scanf("%d", &n);

    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        int randomValue = rand() % 1000;
        insert(randomValue);
    }

    // Original list
    printf("Original random list with %d elements: ", n);
    disp();

    // Add a new value to the list
    int v = 800; // You can change this value as needed
    printf("Add element v with value %d\n", v);
    insert(v);

    // Sorted list
    printf("Sorted array after add new value %d : ", v);
    insertion_sort();
    disp();

    // Find the correct position for the new value
    int pos = binarySearch(head, v);
    printf("The correct position for %d in the list is %d\n", v, pos);

    return 0;
}


/*
Linked lists are my choice
- Traversing each element in both directions is easy when comparing elements and adjusting their position in the list. 
  Because linked lists provide dynamic memory allocation.
- When reaching enough capacity, linked lists do not need to be resized, while arrays or stacks are unlikely to do so
- By using pointers, traversing linked lists is simplified
- The stack follows the First In First Out (LIFO) principle, so it is difficult to compare one element with 
  all previous elements efficiently. Because the stack only allows access to the top element.
- Queues follow the First In First Out (FIFO) principle. Comparing an element with all previous elements 
  will involve removing elements from the queue, breaking the order of usage. use queue.
- Insert Sort on linked lists does not require random access to elements, making it suitable for situations where 
  direct access to elements is inefficient, unlike stack or queue.
*/
