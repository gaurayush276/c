#include<stdio.h>
#include<stdlib.h>

 struct node {
    int data ; 
    struct node * next ; 
 } ;

struct node * head = NULL ; 


void print ( struct node* head ) {
  struct node * temp = head ; 
       do{
        printf("%d ", temp->data) ; 
        temp= temp->next ;
       }
       while ( temp != head ) ; 
}

void insert_at_end( struct node ** ref , int val) {
    struct node * temp = (struct node * ) malloc( sizeof ( struct node )) ; 
    temp->data = val ; 
    temp->next = NULL ; 
        if ( *ref == NULL ){
            *ref = temp ;
            temp->next = *ref ; 
            return ; 
        }
        struct node * trav = * ref ; 
        while ( trav->next != *ref ) {
            trav = trav->next ; 
        }
        trav->next = temp ; 
        temp->next= *ref ; 
        // printf("fine ") ;
}
void delete_at_end( struct node ** ref  ) {
      
        if ( *ref == NULL ){
            return ; 
        }
        if ( (*ref)->next == NULL  ){
            *ref = NULL  ; 
        return ;}
        struct node * trav = * ref ; 
        struct node * pre = NULL; 
        while ( trav->next!= NULL ) {
            pre = trav ; 
            trav = trav->next ; 
        }
        pre->next = NULL  ;

        free(trav) ; 
}
void insert_at_begin( struct node ** ref , int val) {
    struct node * temp = (struct node * ) malloc( sizeof ( struct node )) ; 
    temp->data = val ; 
    if ( *ref == NULL ) {
        *ref = temp ;
        temp->next = *ref ; 
        return  ; 
    }
    struct node * last = *ref ; 
    while ( last->next != *ref )
    last = last ->next ; 

    last->next = temp ;
    temp->next = *ref ; 
    *ref = temp ;
     
       
    
}
void delete_at_begin( struct node ** ref ) {
   if ( *ref == NULL )
   return ; 

   struct node * first = *ref ; 
   *ref = (*ref)->next  ;

   free(first) ;
       
    
}
void delete_at_specific( struct node ** ref , int pos) {
    if ( pos == 1 ){
        * ref = (*ref)->next ; 
        return ; 
    }
    
    struct node* trav = *ref ; 
    for ( int i = 1 ;i < pos -1 ; i++ ) {
        trav = trav->next ;
    }
    if ( trav->next != NULL ) 
    trav->next =trav->next->next ; 
    // if we are at the last node 
    else 
    trav->next = NULL ; 
}
void insert_at_specific( struct node ** ref , int val, int pos) {
    
    if ( pos == 1 ){
        insert_at_begin(ref , val ) ; 
        return  ; 
    }
    struct node * temp = (struct node * ) malloc( sizeof ( struct node )) ; 
    temp->data = val ; 
    temp->next = NULL; 

    struct node * trav = * ref ; 
    for ( int i = 1 ; i < pos -1 && trav!= NULL; i++ ) {
        trav = trav->next ; 
    }
    if ( trav == NULL ){
    printf("Out ot bound ") ; 
    return ;}
    temp->next = trav->next ; 
    trav->next  = temp ; 
    
}
void delete_num ( struct node ** ref , int num ) {
        if ( (*ref) ->data == num ) 
        {
            *ref = (*ref)->next ;
            return ; 
        }

        struct node * pre = NULL ; 
        struct node * curr = *ref ; 
        while ( curr!= NULL  ){
            if ( curr->data == num ) {
                    pre->next = curr->next;
                    return ;
            }
            pre = curr ; 
            curr= curr->next ; 
        }
        return ; 
}
int main(){

    insert_at_end(&head , 1 ) ; 
    insert_at_end(&head , 2 ) ; 
    insert_at_end(&head , 3 ) ; 
    insert_at_end(&head , 4 ) ; 
    insert_at_end(&head , 5 ) ; 
    insert_at_end(&head , 6 ) ; 
    // insert_at_begin(&head , 1 ) ; 
    // insert_at_begin(&head , 2 ) ; 
    // insert_at_begin(&head , 3 ) ; 
    // insert_at_begin(&head , 4 ) ; 
    // insert_at_begin(&head , 5 ) ; 
    insert_at_specific( &head , 100 , 7); 
    // delete_at_begin(&head) ; 
    print(head) ; 
    printf("\n") ; 
    // delete_at_end(&head) ; 
    // delete_at_specific(&head ,6) ; 
    // delete_num( & head , 7) ; 
    // print(head ) ; 




return 0 ; 

}