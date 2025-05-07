#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    int data;
    struct node* next;
};

struct node* head = NULL;

void insert_at_end(struct node** head_ref, int data) {
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        new_node->next = *head_ref;
    } else {
        struct node* move = *head_ref;
        while (move->next != *head_ref) {
            move = move->next;
        }
        move->next = new_node;
        new_node->next = *head_ref;
    }
}

void insert_at_begin(struct node** head_ref, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;

    if (*head_ref == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } else {
        // ! because it's a circular list so we need to find the starting point 
        struct node* move = *head_ref;
        while (move->next != *head_ref) {
            move = move->next;
        }
        move->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
}

void insert_at_position(struct node** head_ref, int data, int position) {
    if (position < 1) {
        printf("Invalid position!\n");
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;  

    
    if (*head_ref == NULL) {
        if (position == 1) {
            new_node->next = new_node;
            *head_ref = new_node;
        } else {
            printf("Invalid position!\n");
        }
        return;
    }
            // @ Begin
    if (position == 1) {
        struct node* move = *head_ref;
        while (move->next != *head_ref) {
            move = move->next;
        }
        move->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
        return;
    }

    struct node* move = *head_ref;
    int i = 1;
    while (i < position - 1 && move->next != *head_ref) {
        move = move->next;
        i++;
    }

    if (i < position - 1) {
        printf("position out of bounds!\n");
        free(new_node);
        return;
    }

    new_node->next = move->next;
    move->next = new_node;
}

void delete_from_beginning(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* move = *head_ref;

    if (move->next == *head_ref) {
        printf("Deleted data: %d\n", move->data);
        free(move);
        *head_ref = NULL;
        return;
    }

    while (move->next != *head_ref) {
        move = move->next;
    }

    struct node* del = *head_ref;
    move->next = del->next;
    *head_ref = del->next;

    printf("Deleted data: %d\n", del->data);
    free(del);
}

void delete_from_end(struct node** head_ref) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head_ref)->next == *head_ref) {
        free(*head_ref);
        *head_ref = NULL;
    } else {
        struct node* temp = *head_ref;
        struct node* prev = NULL;

        while (temp->next != *head_ref) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = *head_ref;
        free(temp);
    }
}

void delete_specific(struct node** head_ref, int pos) {
    if (*head_ref == NULL) {
        printf("List is empty.\n");
        return;
    }

    int i = 1;
    struct node* temp = *head_ref;
    while (temp->next != *head_ref) {
        i++;
        temp = temp->next;
    }

    if (pos == 1) {
        if ((*head_ref)->next == *head_ref) {
            free(*head_ref);
            *head_ref = NULL;
        } else {
            struct node* last = *head_ref;
            while (last->next != *head_ref) {
                last = last->next;
            }
            struct node* del = *head_ref;
            *head_ref = (*head_ref)->next;
            last->next = *head_ref;
            free(del);
        }
    } else {
        pos = pos%i ; 
        struct node* curr = *head_ref;
        for (int i = 1; i < pos - 1; i++) {
            curr = curr->next;
        }
        struct node* temp = curr->next;
        curr->next = temp->next;
        free(temp);
    }
}

void display(struct node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct node* move = head;

    printf("Circular Linked List: ");
    do {
        printf("%d->", move->data);
        move = move->next;
    } while (move != head);

    printf("->\n");
}

int main() {
    int ch, val, pos, data;

    while (1) {
        printf("\nMenu:\n1.Insert at End\n2.Insert at Begin\n3.Display\n4.Delete from Begin\n5.Delete from End\n6.Insert at Position\n7.Exit\n8.Delete at Specific Position\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &val);
                insert_at_end(&head, val);
                break;

            case 2:
                printf("Enter the data: ");
                scanf("%d", &val);
                insert_at_begin(&head, val);
                break;

            case 3:
                display(head);
                break;

            case 4:
                delete_from_beginning(&head);
                break;

            case 5:
                delete_from_end(&head);
                break;

            case 6:
                printf("Enter the position where you want to insert: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &data);
                insert_at_position(&head, data, pos);
                break;

            case 7:
                exit(0);

            case 8:
                printf("Enter the position you want to delete: ");
                scanf("%d", &pos);
                delete_specific(&head, pos);
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0 ; 
}
