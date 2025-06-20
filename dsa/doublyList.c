#include<stdio.h>
#include<stdlib.h>
struct node {
     int data ; 
      struct node * next  ; 
      struct node * pre  ; 
} ; 
struct node * head = NULL ; 

void insert_at_begin( struct node ** ref , int val ) {
     struct node * temp = (struct node *) malloc ( sizeof ( struct node )) ; 
     temp->data = val ; 
     temp->next = NULL ; 
     temp->pre = NULL ; 
    
     temp->next = *ref ;
     if ( (*ref) !=NULL ) 
    (*ref) ->pre = temp ;

    *ref = temp ; 
}
void delete_at_begin( struct node ** ref ) {
    if ( * ref == NULL ) 
    return ; 
    struct node * first = *ref ;
      if ( (*ref )->next == NULL ){
    *ref = NULL ; 
     free(first) ; 
    return ;
 }
    *ref = (*ref) ->next ; 
    (*ref)->pre = NULL ; 
    free(first) ; 
}
void insert_at_end(struct node **ref , int val ) {
    struct node * temp = (struct node *) malloc ( sizeof ( struct node )) ; 
    temp ->data = val ;
    temp->next= NULL ; 
    temp->pre = NULL ; 

    if ( *ref == NULL ) {
        *ref = temp ; 
        return ; 
    }
    struct node * trav = *ref ; 
    while ( trav ->next != NULL ) {
        trav = trav ->next ; 
    }
    trav->next = temp ; 
    temp->pre = trav ; 
}
void delete_at_end ( struct node ** ref ) {
    if ( *ref == NULL )
    return ; 
    else if ( (*ref)->next == NULL )
{
    *ref = NULL ; 
    return ; 
}
        struct node * trav = *ref ; 
        struct node * pre = NULL; 
        while ( trav -> next != NULL ) {
            pre = trav ; 
            trav = trav->next ; 
        }
        if (pre != NULL )
        pre->next = NULL ; 
        trav->pre = NULL ; 
}
void inesrt_at_specific ( struct node ** ref , int val,  int pos ) {
    struct node * temp= (struct node * ) malloc ( sizeof ( struct node )) ; 
    temp->data  = val ; 
    temp->next = NULL ; 
    temp->pre = NULL  ;
    if ( pos == 1 ) {
        temp->next = *ref ; 
        (*ref)->pre = temp ; 
        *ref = temp ; 
        return  ; 
    }
    struct node * trav = *ref ; 
    for ( int i =1 ; i <pos-1 ; i++ ) {
            trav = trav->next ; 
    }
    temp->next = trav->next ; 
    temp->pre = trav ; 
    if ( trav->next != NULL ) 
    trav->next->pre = temp ; 
    trav->next = temp ; 
}
void delete_at_specific ( struct node ** ref , int pos ) {
    if ( pos  == 1 ) {
        if ( *ref == NULL )
        return ;
       *ref = (*ref)->next ; 
       (*ref)->pre =  NULL ;
       return ; 
    }
    struct node *trav = *ref;
    for (int i = 1; i < pos - 1 && trav != NULL; i++) {
        trav = trav->next;
    }

    if (trav == NULL || trav->next == NULL) return;
    if ( trav->next ->next != NULL ){ 
    struct node * toDelete = trav->next ; 
    trav->next = toDelete->next ; 
    toDelete->next->pre = trav ; 
}
        else {
            trav->next = NULL ; 
            // trav->next->pre = NULL ;
        }
}
void print_begin( struct node * temp ) {
    while ( temp != NULL ) {
        printf("%d " , temp->data) ; 
        temp = temp->next ; 
    }

    printf("\n") ; 
}
void print_end( struct node * temp ) {
    while ( temp->next != NULL ) {
        temp = temp->next ; 
    }
    while ( temp!= NULL ) {
        printf("%d ", temp->data ) ; 
        temp=  temp->pre ;
    }
    printf("\n") ; 

}

int main(){

   
    // insert_at_begin( & head , 1 ) ;  
    // insert_at_begin( & head , 2) ;  
    // insert_at_begin( & head , 3 ) ;  
    // insert_at_begin( & head , 4 ) ;  
    insert_at_end(&head , 1 ) ; 
    insert_at_end(&head , 2 ) ; 
    insert_at_end(&head , 3 ) ; 
    insert_at_end(&head , 4 ) ; 
    insert_at_end(&head , 5 ) ; 
    insert_at_end(&head , 6 ) ; 
    // inesrt_at_specific(&head , 100,4 ) ;
    printf("before\n") ; 
    print_begin(head ) ; 
    print_end(head ) ;  
    // delete_at_begin(&head ) ; 
    // delete_at_end(&head ) ; 
    delete_at_specific(&head ,6) ; 
    printf("after\n") ; 
    print_begin(head ) ; 
    print_end(head ) ; 

return 0 ; 

}