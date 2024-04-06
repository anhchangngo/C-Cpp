#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h> 

struct Car {
    int passengers;
    char id[20];
};

struct Train {
    struct Car c;
    struct Train* next;
};

typedef struct Train* train;

train makeCar(int passengers, const char* id) {
    train tmp = (train)malloc(sizeof(struct Train));
    tmp->c.passengers = passengers;
    strcpy(tmp->c.id, id);
    tmp->next = NULL;
    return tmp;
}

// Empty Check
bool empty(train a){
    return a = NULL;
}

int Size(train a){
    int cnt = 0;
    while(a != NULL){
       ++cnt;
       a = a->next;
    }
    return cnt;
}

//addCar()
// addCar() method is defined which adds a new node in the ens of the list
void addCar(train *a, int passengers, const char* id){
    train tmp = makeCar(passengers, id);
    if(*a == NULL){
        *a = tmp;
    }
    else {
        train p = *a;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = tmp;
    }
}

//removeCars() function is defined below
//it removes nodes where number of passengers are 0
void removeCar(train* a) {
    train current = *a;
    train previous = NULL;

    while (current != NULL) {
        if (current->c.passengers == 0) {
            printf("\n%d %s removed ", current->c.passengers, current->c.id);
            if (previous == NULL) {
                // Remove the first node
                *a = current->next;
            } else {
                // Remove a node in the middle or at the end
                previous->next = current->next;
            }
            train tmp = current;
            current = current->next;
            free(tmp);
        }
        //if passengers in temp node is not equal to 0
         else {
            previous = current;
            current = current->next;
        }
    }
}

//  display all cars’ information or the length of the train
void printTrain(train a){
    if(a == NULL){
        printf("The train has no cars!\n");
        return;
    }

    // Created temp pointer and stored address of a
    train tmp = a;
    while(tmp != NULL){
         printf("%d %s\n", tmp->c.passengers, tmp->c.id);
         tmp = tmp->next;
    }
}

int main() {
    train head = NULL;

    // Add cars to the train
    addCar(&head, 10, "car1");
    addCar(&head, 20, "car2");
    addCar(&head, 30, "car3");
    addCar(&head, 0, "car4");
    addCar(&head, 25, "car5");
    addCar(&head, 0, "car6");

    printf("Cars in the list:\n");
    printTrain(head);

    // Remove cars with 0 passengers
    removeCar(&head);
    printf("\n");
    printf("\nAfter removing cars with 0 passengers:\n");
    printTrain(head);

    int carCount = Size(head);
    printf("\nNumber of cars left in the train: %d\n", carCount);

    // Free allocated memory
    while (head != NULL) {
        train tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}