#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL;

void display(struct node *r) {
    printf("List: ");
    while (r != NULL) {
        printf("%d <-> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}

void insert_at_begin(struct node **head_ref, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head_ref;
    new_node->prev = NULL;

    if (*head_ref != NULL)
        (*head_ref)->prev = new_node;

    *head_ref = new_node;
}

void insert_at_end(struct node **head_ref, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    struct node *temp = *head_ref;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = new_node;
    new_node->prev = temp;
}

void insert_at_specific(struct node **head_ref, int pos, int val) {
    if (pos < 1) {
        printf("Enter a valid position\n");
        return;
    }

    if (pos == 1) {
        insert_at_begin(head_ref, val);
        return;
    }

    struct node *temp = *head_ref;
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;

    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is beyond the length of the list.\n");
        return;
    }

    new_node->next = temp->next;
    new_node->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = new_node;

    temp->next = new_node;
}

void delete_begin(struct node **head_ref) {
    if (*head_ref == NULL)
        return;

    struct node *temp = *head_ref;
    *head_ref = temp->next;

    if (*head_ref != NULL)
        (*head_ref)->prev = NULL;

    free(temp);
    printf("Deleted from beginning\n");
}

void delete_end(struct node **head_ref) {
    if (*head_ref == NULL)
        return;

    struct node *temp = *head_ref;

    if (temp->next == NULL) {
        free(temp);
        *head_ref = NULL;
        printf("Deleted last remaining node\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
    printf("Deleted from end\n");
}

int main() {
    int ch, val, pos;

    while (1) {
        printf("\nMenu:\n1. Insert at End\n2. Insert at Begin\n3. Display\n4. Exit\n5. Delete from Begin\n6. Delete from End\n7. Insert at Specific Position\n");
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
                exit(0);
            case 5:
                delete_begin(&head);
                break;
            case 6:
                delete_end(&head);
                break;
            case 7:
                printf("Enter the position to insert: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &val);
                insert_at_specific(&head, pos, val);
                break;
            
        }
    }
    return 0 ; 
}