#include<stdio.h>

int size = 100 ; 

int front = -1 ; 
int rear = -1 ; 
void push ( int arr [] , int val ) {
    if ( rear == size  )
    return ; 
     if (front == -1) front = 0; 
    rear ++ ; 
    arr[rear] = val ; 
}

void pop ( int arr []) {
    if ( front  == size || front > rear  )
    return  ; 

        front++ ; 
    
}

int top ( int arr[])  {
    if ( front == -1 || front > rear )
    return -1 ; 
    return arr[front]; 
}

int main(){
        int arr[size] ; 
        push( arr , 1) ; 
        push( arr , 2) ; 
        push( arr , 3) ; 
        push( arr , 4) ;
        pop(arr)  ;
        push( arr , 5) ; 
        push( arr , 6) ; 
        int ans = top(arr); 
        printf("%d " , ans ) ; 
return 0 ; 

}