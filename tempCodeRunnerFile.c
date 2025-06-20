#include<stdio.h>
int size = 100 ; 
 int top = -1 ; 

 void push ( int arr [] , int val )  {
    if ( top == size -1 ) 
    return ; 
    top++ ; 
    arr[top] = val ; 
 }

 void pop ( int arr [] ) {
    if ( top == -1 ) 
    return ;

    top-- ; 

 }

 int peek ( int arr[] ) {
    if ( top != -1 || top != size )
    return arr[top]; 
 }

int main(){
     
    int arr [size] ; 
    push( arr , 1 )  ;
    push( arr , 2 )  ;
    push( arr , 3 )  ;
    push( arr , 4 )  ;
    pop( arr ) ; 
    int ans = peek( arr ) ; 
    printf("%d" , ans  ) ; 




return 0 ; 

}