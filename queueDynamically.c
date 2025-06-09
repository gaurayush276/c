#include <stdio.h>
#include <stdlib.h>

 struct Node {
    int data;
    struct Node* next;
};

 struct Node* front = NULL;
struct Node* rear = NULL;

 void insert() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  
    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted into the queue.\n", value);
}

 void delete() {
    if (front == NULL) {
        printf("Queue is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;

    if (front == NULL) {
        rear = NULL;  
    }

    free(temp);
}

  
void display() {
    struct Node* temp = front;

    if (temp == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

 int main() {
    int choice;

    while (1) {
        printf("\n----- Queue Menu -----\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            delete();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

return 0 ;
}
