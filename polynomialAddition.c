#include<stdio.h>
#include<stdlib.h>


struct Node {
        int coeff ; 
        int exp ; 
        struct Node * next ; 

    } ; 
struct Node *createNode( int coeff , int exp) {
        struct Node * newNode = (struct Node *) malloc(sizeof(struct Node)) ; 
        newNode ->coeff = coeff ; 
        newNode ->exp = exp ; 
        newNode ->next = NULL ; 
        return  newNode ; 

    }
    
void insert ( struct Node ** poly , int coeff , int exp ) {
    struct Node * temp = *poly ; 
    struct Node * newNode  = createNode(coeff , exp) ; 
    if ( * poly == NULL)
    *poly = newNode ;
    else {
        while (temp->next != NULL)
        {
            temp= temp->next ; 
        }
        temp->next =newNode ; 
        
    }
}
struct Node * addPolynomials(struct Node * poly1 , struct Node *poly2) {
    struct Node * result = NULL ; 
    struct Node ** tail = &result ; 

    while (poly1 != NULL && poly2 != NULL ) {
        if (poly1->exp == poly2->exp) {
            insert(tail , poly1->coeff + poly2->coeff , poly1->exp) ; 
            poly1 = poly1->next ; 
            poly2 = poly2->next ; 
        }
        else if (poly1->exp > poly2->exp) {
            insert(tail , poly1->coeff , poly1->exp) ; 
            poly1 = poly1->next ; 
        }
        else {
            insert(tail , poly2->coeff , poly2->exp) ; 
            poly2 = poly2->next ; 
        }

        tail = &((*tail)->next) ;
    }

    while (poly1 != NULL) {
        insert(tail , poly1->coeff , poly1->exp) ; 
        poly1 = poly1->next ; 
        tail = &((*tail)->next) ;
    }

    while (poly2 != NULL) {
        insert(tail , poly2->coeff , poly2->exp) ; 
        poly2 = poly2->next ; 
        tail = &((*tail)->next) ;
    }

    return result ;
}

struct Node * subPolynomials(struct Node * poly1 , struct Node *poly2) {
    struct Node * result = NULL ; 
    struct Node ** tail = &result ; 

    while (poly1 != NULL && poly2 != NULL ) {
        if (poly1->exp == poly2->exp) {
            insert(tail , poly1->coeff - poly2->coeff , poly1->exp) ; 
            poly1 = poly1->next ; 
            poly2 = poly2->next ; 
        }
        else if (poly1->exp > poly2->exp) {
            insert(tail , poly1->coeff , poly1->exp) ; 
            poly1 = poly1->next ; 
        }
        else if (poly1->exp < poly2->exp) {
            insert(tail , -poly2->coeff , poly2->exp) ; 
            poly2 = poly2->next ; 
        }

        tail = &((*tail)->next) ;
    }

    while (poly1 != NULL) {
        insert(tail , poly1->coeff , poly1->exp) ; 
        poly1 = poly1->next ; 
        tail = &((*tail)->next) ;
    }

    while (poly2 != NULL) {
        insert(tail , poly2->coeff , poly2->exp) ; 
        poly2 = poly2->next ; 
        tail = &((*tail)->next) ;
    }

    return result ;
}

struct Node* multiplyPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* result = NULL;

    struct Node *tempResult = NULL ;
    struct Node *tempPoly = NULL ;

    while (tempPoly != NULL ) {
        struct Node * tempPoly = poly1 ; 

        while (tempPoly )
        
        
    }

    return result;
}
 
void display(struct Node * poly ) {
    while ( poly != NULL ) {
       printf("%dx^%d + " , poly->coeff ,poly->exp) ; 
       poly= poly->next ; 
    }
    printf("\n") ;
}
int main(){

    
    struct Node * poly1 = NULL  ; 
    struct Node * poly2 = NULL  ; 

    insert(&poly1  , 5, 2 ) ; 
    insert(&poly1  , 4, 1 ) ; 
    insert(&poly1  , 2, 0 ) ; 


    insert(&poly2 , -3, 3 ) ; 
    insert(&poly2 , 2, 1 ) ; 
    insert(&poly2 , 1, 0 ) ; 

    // printing the first list 
    display(poly1) ; 
    // printing the second list 
    display(poly2) ; 

    printf("-------------the addition is----------- \n\n") ; 
    struct Node * addition = addPolynomials(poly1, poly2) ; 
    display(addition) ;
    printf("-------------the substraction is-------- \n\n") ; 
    struct Node * subs = subPolynomials(poly1, poly2) ; 
    display(subs) ;

    



return 0 ; 

}