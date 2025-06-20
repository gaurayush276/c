 
 #include<stdio.h>
#include<stdlib.h>

 struct node {
    int data ; 
    struct node * next ; 
 } ;

struct node * head = NULL ; 

void print ( struct node* temp ) {
        while ( temp != NULL ) {
            printf("%d " , temp->data  ) ; 
            temp = temp->next ; 
        }
        printf("\n") ; 
}
// push insert at begin 
void push( struct node ** ref , int val) {
    struct node * temp = (struct node * ) malloc( sizeof ( struct node )) ; 
    temp->data = val ; 
    temp->next = *ref ; 
    *ref = temp ;
       
    
}

// pop delete at begin 
void pop( struct node ** ref ) {
   if ( *ref == NULL )
   return ; 

   struct node * first = *ref ; 
   *ref = (*ref)->next  ;
    printf("%d popped\n" , first->data)  ; 
   free(first) ;
       
    
}


int main(){
 
    push(&head , 1 ) ; 
    push(&head , 2 ) ; 
    push(&head , 3 ) ; 
    push(&head , 4 ) ; 
    push(&head , 5 ) ; 
 
  print(head ) ;
 
    pop(&head) ; 
    
    print(head ) ; 




return 0 ; 

}