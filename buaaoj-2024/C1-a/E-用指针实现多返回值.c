#include <stdio.h>
void ExGCD(int a, int b, int* d, int* x, int* y) {
    if (b == 0) {
        *d = a;
        *x = 1;
        *y = 0;
        return;
    }
    int dd, xx, yy;
    ExGCD(b, a % b, &dd, &xx, &yy);
    *d = dd;
    *x = yy;
    *y = xx - a / b * yy;
}
int main() {
    int a, b, d, x, y;
    scanf("%d%d", &a, &b);
    ExGCD(a, b, &d, &x, &y);
    printf("%d = %d*(%d) + %d*(%d)\n", d, a, x, b, y);
    return 0;
}

// Pseudocode

// EXTENDED-EUCLID(a,b)
//  if b == 0
//      return (a, 1,0)
//  else (d',x', y') = ExTENDED-EUCLID(b,a mod b)
//      (d,x, y) = (d',y',x' - a/b * y)
//      return (d, x, y)