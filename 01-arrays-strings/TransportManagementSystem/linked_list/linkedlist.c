#include <stdio.h>
#include <stdlib.h>

struct Node {
    char plate[15];
    char route[30];
    char driver[30];
    int capacity;
    float fare;
    struct Node *next;
};

struct Node *head = NULL;   // head points to the first node

// Operation 1: create an empty list
void createList() {
    head = NULL;
    printf("Empty list created.\n");
}

// makes one new node and asks the user for the bus details
struct Node *makeNode() {
    struct Node *newNode = malloc(sizeof(struct Node));

    printf("Plate number: ");
    scanf(" %14[^\n]", newNode->plate);
    printf("Route name: ");
    scanf(" %29[^\n]", newNode->route);
    printf("Driver name: ");
    scanf(" %29[^\n]", newNode->driver);
    printf("Capacity: ");
    scanf("%d", &newNode->capacity);
    printf("Fare: ");
    scanf("%f", &newNode->fare);

    newNode->next = NULL;
    return newNode;
}

// Operation 2: insert at the beginning
void insertAtBeginning() {
    struct Node *newNode = makeNode();
    newNode->next = head;   // new node points to the old first node
    head = newNode;         // head now points to the new node
    printf("Bus inserted at the beginning.\n");
}

// Operation 3: insert at the end
void insertAtEnd() {
    struct Node *newNode = makeNode();

    if (head == NULL) {          // list is empty
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {   // go to the last node
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Bus inserted at the end.\n");
}

// Operation 4: insert at a position given by the user
void insertAtPosition() {
    int pos;
    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position.\n");
        return;
    }

    struct Node *newNode = makeNode();

    if (pos == 1) {              // same as insert at beginning
        newNode->next = head;
        head = newNode;
        printf("Bus inserted at position 1.\n");
        return;
    }

    // move temp to the node just before the position
    struct Node *temp = head;
    for (int i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {          // position is too far
        printf("Position is too large for this list.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;  // new node points to the next one
    temp->next = newNode;        // previous node points to the new node
    printf("Bus inserted at position %d.\n", pos);
}

// Operation 5: display the list
void displayList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head;
    int number = 1;
    printf("\n%-4s %-12s %-20s %-18s %-6s %-8s\n",
           "No", "Plate", "Route", "Driver", "Cap", "Fare");

    while (temp != NULL) {
        printf("%-4d %-12s %-20s %-18s %-6d %-8.2f\n",
               number, temp->plate, temp->route,
               temp->driver, temp->capacity, temp->fare);
        temp = temp->next;
        number++;
    }
}


int main() {
    int choice;

    do {
        printf("\n===== BUS LINKED LIST =====\n");
        printf("1. Create list\n");
        printf("2. Insert at beginning\n");
        printf("3. Insert at end\n");
        printf("4. Insert at position\n");
        printf("5. Display list\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createList(); break;
            case 2: insertAtBeginning(); break;
            case 3: insertAtEnd(); break;
            case 4: insertAtPosition(); break;
            case 5: displayList(); break;
            case 0: printf("Goodbye.\n"); break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}