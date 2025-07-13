#include<stdio.h>
#include<string.h>
int top = -1 ; 
int size  = 100 ; 

void push ( int arr[] , int val  ) {
    if ( top == size )
    return  ; 
    top ++ ; 
    arr[top] = val ; 
}
void pop( int arr[]) {
    if ( top == -1 )
    return ; 

    top-- ;
}
int peek ( int arr[]) {
    if ( top  == -1 )
    return 1e9 ; 
    return arr[top] ; 
}

int isEmpty( int arr[]) {
    if ( top == -1 )
    return 1 ; 
    return 0 ; 
}

int evaluatePostfix( char exp[], int n) {
 
    int st[size]  ; 
    for ( int i = 0 ; i <n ;i++ ) {
        if ( exp[i] >= '0'  && exp[i] <='9' )
        push( st, exp[i] -'0') ; 
        else {
            int first = peek(st) ; 
            pop(st) ; 
            int second = peek(st) ; 
            pop(st) ; 
            int temp = 0 ; 
            if ( exp[i] =='+') 
            temp = second + first ;
            else   if ( exp[i] =='-') 
            temp = second - first ;
            else   if ( exp[i] =='*') 
            temp = second * first ;
            else   
            temp = second / first ;

            push( st , temp ) ; 
        }
    }

    return peek(st) ; 
}


int main(){

    // char exp [ ] = "54+38*2/-" ; 
    // char exp [] = "98+7*654+*3*+2+" ; 
    char exp [] = "54+38*2/-"; 
    int n = strlen(exp) ; 
    printf("\n The Postfix expression : %d ", evaluatePostfix(exp , n )) ; 




return 0 ; 

}