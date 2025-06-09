#include <iostream>

int A(int  m, int n, int  p) {
    if (p == 0)
        return m + n;
    else if (n == 0 && p == 0)
        return 1;
    else if (n == 0 && p == 1)
        return 0;
    else if (n == 0)
        return m;
    else
        return A(m, A(m, n - 1, p), p - 1);
}

int main() {
    int n = 2 ; 
    int m =2 ; 
    int p =3 ; 
    int result = A( m , n , p);
    printf("A(2, 2, 3) = %d\n", result);
return 0;
}
