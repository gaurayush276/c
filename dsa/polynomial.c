 #include<stdio.h>
 #include<stdlib.h>
 
 struct node {
    int coeff ; 
    int exp ; 
    struct node  * next; 
 } ;

//  for creating the nodes to add in the  expression 
struct node * createNode (   int c, int e ) {
    struct node * temp = (struct node * ) malloc ( sizeof ( struct node)) ; 
    temp->exp = e ; 
    temp ->coeff = c ;
    temp->next = NULL ; 
    return temp ;
}

// function will add the nodes to make the expression 
void insert ( struct node ** poly , int c , int e) {
    struct node * temp = *poly ; 
    struct node * curr = createNode( c,e ) ; 
    if ( temp== NULL  ) {
    *poly = curr ;
    return ; }

    while ( temp->next != NULL ) {
        temp = temp->next ; 
    }
   temp->next = curr ; 
}

struct node * addPoly ( struct node * p1 , struct node *p2 ) {
        struct node * result = NULL ; 
        struct node ** tail = &result ; 
        while ( p1 !=  NULL && p2 != NULL  ) {
            if ( p1->exp == p2->exp) {
                insert ( tail , p1->coeff + p2->coeff , p1->exp ) ; 
                p1 = p1->next; 
                p2=p2->next ; 
            }
            else if ( p1->exp < p2->exp ) {
                insert ( tail , p2->coeff ,p2->exp) ; 
                p2 = p2->next ; 
            }
            else {
                insert ( tail , p1->coeff ,p1->exp) ; 
                p1 = p1->next ; 
            }
            tail =&((*tail )->next );
        }

        while ( p1 != NULL ) { 
             insert ( tail , p1->coeff ,p1->exp) ; 
                p1= p1->next ; 
                tail = &((*tail )->next );
        }
        while ( p2 != NULL ) { 
             insert ( tail , p2->coeff ,p2->exp) ; 
                p2 = p2->next ; 
                tail =&( (*tail) ->next );
        }
 
        return result  ;
}

struct node * diffPoly ( struct node * p1 , struct node *p2 ) {
        struct node * result = NULL ; 
        struct node ** tail = &result ; 
        while ( p1 !=  NULL && p2 != NULL  ) {
            if ( p1->exp == p2->exp) {
                insert ( tail , p1->coeff - p2->coeff , p1->exp ) ; 
                p1 = p1->next; 
                p2=p2->next ; 
            }
            else if ( p1->exp < p2->exp ) {
                insert ( tail , p2->coeff ,p2->exp) ; 
                p2 = p2->next ; 
            }
            else {
                insert ( tail , p1->coeff ,p1->exp) ; 
                p1 = p1->next ; 
            }
            tail =&((*tail )->next );
        }

        while ( p1 != NULL ) { 
             insert ( tail , p1->coeff ,p1->exp) ; 
                p1= p1->next ; 
                tail = &((*tail )->next );
        }
        while ( p2 != NULL ) { 
             insert ( tail , p2->coeff ,p2->exp) ; 
                p2 = p2->next ; 
                tail =&( (*tail) ->next );
        }
 
        return result  ;
}

struct node * mulPoly( struct node * p1 , struct node * p2 ) {
    struct node* result = NULL ;
     

    while ( p1 != NULL  ) {
        // tempProd contain the result of the product of  first element  to the second expression
        struct node * tempSecond = p2 ; 
        struct node * tempProd = NULL ; 
        while ( tempSecond != NULL ) {
            int coeff_val = p1->coeff * tempSecond->coeff  ; 
            int exp_val = p1->exp + tempSecond->exp  ; 
            insert ( &tempProd ,coeff_val , exp_val ) ; 
            tempSecond = tempSecond->next ; 
        }
        // to combine the overall expressionn if there si something that can add up 
        result  = addPoly( result , tempProd ) ; 
  
        p1= p1->next ; 
    }

    return result ; 
}


 
void dispaly ( struct node * p1 ) {
    while ( p1  != NULL ) {
        printf ("%d x ^%d + ", p1->coeff , p1->exp) ; 
        p1= p1->next ; 
    }
    printf("\n") ; 
}

 int main(){


    struct node * p1 = NULL ; 
    struct node * p2 = NULL ; 
    insert ( &p1 , 2 , 2 ) ; 
    insert ( &p1 , 3 , 1 ) ; 
    insert ( &p1 , 1 , 0 ) ; 

    insert( &p2 , 1 , 2 ) ; 
    insert( &p2 , 2 , 1 ) ; 
    insert( &p2 , 2 , 0 ) ; 


    dispaly(p1) ; 
    dispaly(p2) ;

    // struct node * ans1 = addPoly( p1 , p2 ) ; 
    //   dispaly(ans1) ; 
    // struct node * ans2 = diffPoly( p1 , p2 ) ; 
    //   dispaly(ans2) ; 
    // struct node * ans3 = mulPoly( p1 , p2 ) ; 
    struct node * ans3 = tempProd( p1 , p2 ) ; 
    
     dispaly(ans3 ) ; 
 
 return 0 ; 
 
 }


//  steps --
//  1 -> 
        //  struct node * p1 = NULL ; 
      // struct node * p2 = NULL ;  make the two expression 
 //  2 ->
    //   insert( &p2 , 1 , 2 ) ; 
    // insert( &p2 , 2 , 1 ) ; 
    // insert( &p2 , 0 , 2 ) ; 
    //  to initialze the expression 
// 3 -> 
    // insert -->  this will take the tail and make the node for like 2x then add it into the tail to make answer 