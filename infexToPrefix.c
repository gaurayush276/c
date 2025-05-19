#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c) {
    if (c == '^') return 3;
    else if (c == '/' || c == '*') return 2;
    else if (c == '+' || c == '-') return 1;
    else return -1;
}

char associativity(char c) {
    if (c == '^') return 'R';  // right-associative
    return 'L';                // default: left-associative
}

void infixToPostfix(char s[]) {
    char result[100];
    int ri = 0;
    int len = strlen(s);
    char stack[100];
    int si = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || 
            (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9')) {
            result[ri++] = c;
        }
        else if (c == '(') {
            stack[++si] = c;
        }
        else if (c == ')') {
            while (si >= 0 && stack[si] != '(') {
                result[ri++] = stack[si--];
            }
            si--; // pop '('
        }
        else {
            while (si >= 0 && 
                   (prec(c) < prec(stack[si]) || 
                   (prec(c) == prec(stack[si]) && associativity(c) == 'L')) &&
                   stack[si] != '(') {
                result[ri++] = stack[si--];
            }
            stack[++si] = c;
        }
    }

    while (si >= 0) {
        result[ri++] = stack[si--];
    }

    result[ri] = '\0';  // null terminate the result string
    printf("Postfix Expression: %s\n", result);
}

int main() {
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(exp);
    return 0;
}
