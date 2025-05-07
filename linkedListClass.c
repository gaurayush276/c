#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *head = NULL;

void display(struct node *r) {
    while (r != NULL) {
        printf("%d -> ", r->data);
        r = r->next;
    }
    printf("NULL\n");
}



void insert_at_begin(struct node **head_ref, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insert_at_end(struct node **head_ref, int new_data) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    struct node *temp = *head_ref;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}
void insert_at_specific ( struct node ** head_ref , int pos , int val) {
    if ( pos < 0 ) {
        printf("Enter the vad position \n") ; 
        return ; 
    }
    if ( pos == 1 ) {
        insert_at_begin(head_ref ,val ) ; 
        return ;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node)) ; 
    new_node ->data  = val ; 
    struct node * temp = *head_ref  ; 
    
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next; 
    }
    new_node->next = temp->next; 
    temp->next = new_node ; 
}
void delete_begin( struct node  **head_ref ) {
        if (* head_ref == NULL )
        return ;
        printf("Nodes before deletion \n") ;  
        display(head) ; 
        printf("nodes deleted") ; 
        *head_ref = (*head_ref )->next ; 
}  
void delete_end( struct node  **head_ref ) {
    if ( *head_ref == NULL  || (*head_ref )->next == NULL  )
        return ;
     struct node * temp = *head_ref ; 
    while (  temp->next ->next != NULL  ){
            temp = temp -> next ;
    }
    free(temp->next) ; 
    temp-> next = NULL ; 
}  

int main() {
    int ch, val;
    int pos ; 
    while (1) {
        printf("\nMenu:\n1. Insert at End\n2.insert at begin \n3. Display\n4. Exit\n 5.deletion from Begin\n 6. Delete from end \n7.insert at specific \n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &val);
                insert_at_end(&head, val);
                break;
            case 2 :
                printf("Enter the data: ");
                    scanf("%d", &val);
                     insert_at_begin(&head , val) ; 
                break ; 
            case 3:
                display(head);
                break;
//  ^ exit is  an inbuilt function
            case 4: exit(1) ; 
                break;
            case 5 : delete_begin(&head) ; 
            break ; 
            case 6 : delete_end(&head) ; 
            break ; 
            case 7 :
            printf("\t enter the position where to insert\n")  ;
            scanf("%d" , &pos) ; 
            printf("\tEnter the data: ");
            scanf("%d", &val);
            insert_at_specific(&head , pos , val) ; 
            break ; 

            default:
                printf("You have entered wrong choice\n");
        }
    }

    return 0;
}
