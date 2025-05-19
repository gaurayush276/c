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
        printf("The number is removed from the stack\n") ; 
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

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1: {
                int num;
                printf("Enter the number to push: ");
                scanf("%d", &num);
                push(num, arr, size, &top);
                break;
            }
            case 2:
                pop(arr, size, &top);
                break;
            case 3:
                display(arr, size, &top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}