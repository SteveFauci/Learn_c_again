#include <stdio.h>
int add(int a, int b) {
    while (b != 0) {
        int sum_without_carry = a ^ b;
        int carry = a & b;
        a = sum_without_carry;
        b = carry << 1;
    }
    return a;
}
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = add(a, b);
    printf("%d\n", c);
    return 0;
}