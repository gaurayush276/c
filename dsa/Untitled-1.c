#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top == MAX - 1) return;
    stack[++top] = ch;
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1) return '\0';
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int priority(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    else return 0;
}

void infixToPostfix(char infix [],  int n ) {
    int i = 0, k = 0;
    int size = n ; 

    char postfix[100] ; 

   for ( int i = 0 ; i < n ; i++ ) {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (!isEmpty() && peek() != '(') {
                postfix[k++] = pop();
            }
            pop(); // Remove '(' from stack
        }
        else {
            while (!isEmpty() && priority(peek()) >= priority(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        
    }
    
    while (!isEmpty()) {
        postfix[k++] = pop();
    }
    printf ("%s " , postfix ) ; 

}

int main() {
    char infix[] = "a+b*(c^d-e)^(f+g*h)-i";
     int n = strlen ( infix ) ; 
    infixToPostfix(infix , n );
    

    return 0;
}
