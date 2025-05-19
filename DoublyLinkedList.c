#include <stdio.h>
#include <stdlib.h>

struct node {
    int data ; 
    struct node * next; 
    struct node * pre; 
} ;

struct node * head  = NULL ;

void display( struct node * head_ref ) {
    struct node * temp = head_ref ;
    while ( temp != NULL  ) {
        printf("%d -> " , temp->data) ; 
        temp = temp->next ;
    }
    printf("NULL") ; 
}
void display_rev( struct node * head_ref ) {
    struct node * temp = head_ref ;
    
    while ( temp->next != NULL  ){
        temp = temp->next ;
    }

    while ( temp != NULL ) {
        printf("%d -> " , temp->data) ; 
        temp = temp->pre ;
    }
    printf("NULL") ; 
}


 

void insert_at_end( struct node ** head_ref , int val ) {
    struct node * newNode = (struct node *)malloc( sizeof ( struct node)) ; 
    newNode->data = val ; 
    newNode->next = NULL ; 
    if ( *head_ref == NULL ) {
        *head_ref = newNode ; 
        return ;
    }
    struct node * temp = *head_ref ; 
    while (  temp ->next  != NULL ){
        temp = temp->next ;
    }
    temp->next = newNode ; 
    newNode->pre = temp ; 

}

void insert_at_begin ( struct node ** head_ref , int val ) {
    struct node * newNode = (struct node *)malloc( sizeof ( struct node)) ; 
    newNode->data = val ; 
    newNode ->next = *head_ref ; 
    newNode ->pre = NULL ; 
    if (*head_ref != NULL) {
        (*head_ref)->pre = newNode;
    }
   *head_ref = newNode ; 

}

void insert_at_specific(struct node ** head_ref , int pos, int val )
{
    if ( pos == 1 )
    {
        insert_at_begin( head_ref , val ) ;
        return ;  
    }

    struct node * newNode = (struct node *)malloc( sizeof ( struct node)) ; 
    newNode->data = val ; 
    newNode->next = NULL ; 
    newNode->pre = NULL ; 
    struct node * temp = *head_ref ; 

    for ( int i = 1 ; i < pos -1 ; i++ ) {
        temp = temp->next ;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    newNode->next= temp ->next ; 
    newNode->pre= temp  ; 
   
    if (temp->next != NULL) {
        temp->next->pre = newNode;
    }
    temp->next = newNode ; 

    

}
// void delete_begin(struct node ** head_ref  ) {
//         if ( *head_ref == NULL )
//         return ; 
//         struct node * temp =* head_ref ; 
//  /       * head_ref  =(*head_ref)->next ; 

// }

 

int main() {
    int ch, val;
    int pos ; 
    while (1) {
        printf("\nMenu:\n1. Insert at End\n2.insert at begin \n3. Display\n4. Display_reverse\n5. Exit\n 6.deletion from Begin\n 7. Delete from end \n8.insert at specific \n");
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
            case 4:
                display_rev(head);
                break;
             case 5: exit(1) ; 
                break;
            // case 6 : delete_begin(&head) ; 
            // break ; 
            // case 7 : delete_end(&head) ; 
            // break ; 
            case 8 :
            printf("\t enter the position where to insert\n")  ;
            scanf("%d" , &pos) ; 
            printf("\tEnter the data: ");
            scanf("%d", &val);
            insert_at_specific(&head , pos , val) ; 
            break ; 

        }
    }

    return 0;
}
