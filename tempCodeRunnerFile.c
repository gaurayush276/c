#include<stdio.h>
void TOH( int n , char s , char d , char a ) {
    if ( n == 0 ) {
        return  ; 
    }
    TOH ( n -1 , s , a ,d ) ; 
    printf("move disk %d from %c to %c \n" , n , s ,d ) ; 
    TOH ( n -1 , a , d ,  s )  ; 

     
}
int main(){

    int n ; 
    printf("Enter the numer\n") ; 
    scanf("%d" , &n) ; 
    TOH ( n , 'S' , 'D' , 'A') ;

return 0 ; 

}