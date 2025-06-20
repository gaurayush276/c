#include<stdio.h>
#include <stdlib.h>
void push( int val , int arr[] , int size , int *top) {
        if ( *top == size -1 ){
            printf("Stack OverFlowed") ; 
            return ; 
        }
        else {
            (*top)++ ; 
            arr[*top] = val ;  
        }
}

void pop ( int arr[] , int size , int *top) {
    if ( *top == -1 ) {
        printf("Stack UnderFlowes") ; 
        return ;
    }
    else {
        printf("The number is removed from the stack %d \n" , arr[*top]) ;  
     (*top)-- ; 
    }
}

void display( int arr[] , int size , int * top) {
    
    
    if ( *top == -1 )
    {
        printf("stack is empty") ; 
        return  ; 
    }
     for ( int i = *top ; i>=0; i-- ) {
        printf("%d " , arr[i]) ; 
     }
     printf("\n") ; 
}

 

int main() {
    int n, size, top = -1;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int arr[size];

    

         
                push(1, arr, size, &top);
                push(2, arr, size, &top);
                push(3, arr, size, &top);
                push(4, arr, size, &top);
                push(5, arr, size, &top);
           display(arr, size, &top);
                pop(arr, size, &top);
                pop(arr, size, &top);
                pop(arr, size, &top);
                // pop(arr, size, &top);
                
                display(arr, size, &top);
                 
               

    return 0;
}