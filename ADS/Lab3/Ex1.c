#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Item struct
struct Item {
    char item_name[20];
    int quantity;
    int price;
    struct Item *next;
};
typedef struct Item Item;

void init(Item **q) { //  a pointer to a pointer to an Item object
    *q = NULL;
}

// Customer struct
struct Customer {
    char customer_name[20];
    char item_name[20];
    int product_buy;
    struct Customer *next;
};
typedef struct Customer Customer;

// CustomerQueue struct
struct CustomerQueue {
    Customer *front;
    Customer *back;
    int size;
};
typedef struct CustomerQueue CustomerQueue;

// initialize a customer queue
void initCustomerLine(CustomerQueue *c) {
    c->front = NULL;
    c->back = NULL;
    c->size = 0;
}

// Update the quantity of an item
void updateItem(Item **q, char name[], int qty, int price) {
  Item *curr = *q;
  Item *prev = NULL;
while(curr != NULL) {
    if(strcmp(curr->item_name, name) == 0) {
      curr->quantity += qty;  // Update quantity  
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  Item *newItem = malloc(sizeof(Item));
  newItem->quantity = qty;
  strcpy(newItem->item_name, name);
  newItem->price = price;
  newItem->next = NULL;
  if(prev == NULL) {
    newItem->next = *q; // Add to head
    *q = newItem;
  }
  else {
    prev->next = newItem; // Add to end
  }

}

// Add a customer to the customer queue and reduce the quantity of the products from the stock
void enqueue(CustomerQueue *cus, Item *stock, char cn[], char in[], int iq) {
    Item *prod_chose = stock;
    while (prod_chose != NULL) {
        if (strcmp(prod_chose->item_name, in) == 0) {
            break;
        }
        prod_chose = prod_chose->next;
    }
    if (prod_chose == NULL) {
        printf("Item '%s' not found in stock.\n", in);
        return;
    }
    if (prod_chose->quantity < iq) {
        printf("Insufficient quantity of '%s' in stock.\n", in);
        return;
    }
    Customer *tmp = (Customer *)malloc(sizeof(Customer));
    strcpy(tmp->customer_name, cn);
    strcpy(tmp->item_name, in);
    tmp->product_buy = iq;
    tmp->next = NULL;

    if (cus->front == NULL) {
        cus->front = tmp;
        cus->back = tmp;
    } 
    else {
        cus->back->next = tmp;  
        cus->back = tmp;  // add customer at the end
    }
    // quantity of goods decreases according to the number of customers buying
    prod_chose->quantity -= iq; 
    cus->size++;
}

// Remove the first customer from the customer queue and can also return the customer's item quantity to the stock list.
void dequeue(CustomerQueue *queue, Item *stock, bool return_item) {
    if (queue->size == 0) {
        printf("No customer in the queue\n");
        return;
    }
    // If return_item is true, add the product_quantity back to the stock list
    if (return_item) {  // true -> number of items returned
        Item *prod_chose = stock;
        while (prod_chose != NULL) {
            if (strcmp(prod_chose->item_name, queue->front->item_name) ==0) { // compare item_name of stock and customer
                break;
            }
            prod_chose = prod_chose->next; //go to next item
        }

        if (prod_chose == NULL) {
            printf("Item '%s' not found in stock.\n", queue->front->item_name);
            return;
        }
        prod_chose->quantity += queue->front->product_buy; // the number of goods is increased instead of the customer's goods
    }
    Customer *tmp = queue->front;
    queue->front = queue->front->next; //points to the next customer
    free(tmp);

    queue->size--;

    if (queue->front == NULL) {
        queue->back = NULL;
    }
}

// Displays information about the customer queue
void displayCustomer(CustomerQueue *queue) {
    if (queue->size == 0) {
        printf("No customer in the queue\n");
        return;
    }
    Customer *tmp = queue->front;
    printf("Queue of Customers:\n");
    printf("---------------------------------------------------------------\n");
    while (tmp != NULL) {
         printf("Name: %s\t\tItem: %s\t\tQuantity: %d\n", tmp->customer_name, tmp->item_name, tmp->product_buy);
        tmp = tmp->next;
    }
    printf("\n");
}

// Displays information about the product list
void displayStock(Item *stock) {
    if (stock == NULL) {
        printf("Stock is empty\n");
        return;
    }
    Item *tmp = stock;
    printf("Stock List:\n");
    printf("----------------------------------------------------------------\n");
    while (tmp != NULL) {
        printf("Item: %s\t\tQuantity: %d\t\tPrice: %d\n", tmp->item_name, tmp->quantity, tmp->price);
        tmp = tmp->next;
    }
    printf("\n");
}

int main() {
    Item *stock = NULL;
    init(&stock);

    // Adding products to the stock
    updateItem(&stock, "MacBook", 10, 2000);
    updateItem(&stock, "DELL", 15, 1500);
    updateItem(&stock, "VivoBook", 20, 900);
    displayStock(stock);

    CustomerQueue queue;
    initCustomerLine(&queue);

    // Adding customers to the queue
    enqueue(&queue, stock, "Phuong", "MacBook", 4);
    enqueue(&queue, stock, "Minh", "DELL", 8);
    enqueue(&queue, stock, "Tun", "VivoBook", 2);
    
    // Displaying the customer queue
    displayCustomer(&queue);
    
    //  display a message that successfully purchases and reduce the number of products in stock
    printf("Customer successfully purchases products, the remaining products are in stock\n");
    displayStock(stock);

    printf("Customer leave\n");
    dequeue(&queue, stock, false);
    dequeue(&queue, stock, false);
    dequeue(&queue, stock, false);
    printf("\n");
    // Adding customers to the queue
    enqueue(&queue, stock, "Dat", "MacBook", 3);
    enqueue(&queue, stock, "Bach", "DELL", 5);
    enqueue(&queue, stock, "Dung", "VivoBook", 6);
    displayCustomer(&queue);
    displayStock(stock);
    // Customers take turns to leave
    printf("Customer leave and do not by anything\n");
    dequeue(&queue, stock, true);
    dequeue(&queue, stock, true);
    dequeue(&queue, stock, true);
    displayStock(stock);
    
    printf("Restock quantity of MacBook\n");
    updateItem(&stock, "MacBook", 10, 2000);
    displayStock(stock);
    return 0;
}