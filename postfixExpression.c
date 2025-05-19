#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>


struct stck {
    int top  ; 
    unsigned capacity ; 
    int * array ; 

} ; 

struct stck * createStack ( unsigned capacity ) {
    struct stck * stack = ( struct  stck *) malloc ( sizeof (struct stck)) ; 

    // checks if the allocations fails 
    if ( !stack )
    return NULL ; 

    stack ->top = -1  ; 
    stack->capacity = capacity  ; 
    stack->array = ( int *) malloc ( stack->capacity * sizeof( int )) ; 

    
    // checks if the allocations fails 
    if ( !stack->array ) return NULL  ;

    return stack ; 
}

int isEmpty( struct stck * stack){
    return  stack->top == -1 ; 
}

int pop ( struct stck * stack ) {
    if( !isEmpty( stack ))
    return stack->array [ stack->top--] ; 

    return '$' ; 
}

void push ( struct  stck * stack , int val ) {
    stack->top++ ; 
    stack->array[stack->top] = val ; 
}

int evaluatePostfix ( char * exp  ){
    struct stck * stack = createStack(strlen(exp)) ; 
    int i ; 
    if (!stack)
    return -1 ; 
    for( i = 0 ; exp[i] ; i++ ) {
        if (isdigit(exp[i]))
        push(stack , exp[i] - '0') ; 
        else {
            int val1 = pop(stack ) ;
            int val2 = pop(stack) ; 
            printf("\nTop two values are %d %d ", val1 , val2 ) ; 
            switch( exp[i]) {

                case '/'  : push(stack, val2 / val1 ) ;
                break ; 
                case '*' : push(stack , val1 * val2 ) ; 
                break ;
                case '+' : push(stack , val1 + val2 ) ; 
                break ; 
                case '-' : push(stack , val2 - val1)  ; 
                break ;

            }
        }
    }
    return pop(stack) ; 
}

int main(){

    // char exp [ ] = "54+38*2/-" ; 
    char exp [ ] = "98+7*654+*3*+2+" ; 
    printf("\n The Postfix expression : %d ", evaluatePostfix(exp)) ; 




return 0 ; 

}