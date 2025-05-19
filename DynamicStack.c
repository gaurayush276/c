#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;

void display(struct node *r) {
    while (r != NULL) {
        printf("%d ", r->data);
        r = r->next;
    }
    printf("\n") ; 
}



void push(struct node **head_ref, int val) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

 
 
void pop( struct node  **head_ref ) {
        if (* head_ref == NULL ){
        printf("Stack UnderFlowed \n") ; 
        return ;
    }
        printf("Nodes before deletion \n") ;  
        display(top) ; 
        printf("nodes deleted") ; 
        *head_ref = (*head_ref )->next ; 
}  
 

int main() {
    int ch, val;
    int pos ; 
    while (1) {
        printf("\nMenu:\n1. Push\n2.Pop \n3. Display\n4. Exit\n ");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            
            case 1 :
                printf("Enter the data: ");
                    scanf("%d", &val);
                     push(&top , val) ; 
                break ;
                case 2 : pop(&top) ; 
                break ;  
            case 3:
                display(top);
                break;
 
            case 4: exit(0) ; 
                break;

        }
    }

    return 0;
}
