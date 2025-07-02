#include <stdio.h>
union Un {
    double        d;
    unsigned long lu;
    unsigned char ch[8];
};
int main() {
    union Un a;
    for (int i = 0; i < 8; i++) {
        scanf("%c", &a.ch[7 - i]);
    }
     //scanf("%lf", &a.d);
    printf("%lu\n", a.lu);
    printf("%lx\n", a.lu);
    for (int i = 0; i < 8; i++) {
        printf("%02x ", a.ch[7 - i]);
    }
    puts("");
    printf("%lf\n",a.d);
    for (int i = 0; i < 8; i++) {
        printf("%c", a.ch[7 - i]);
    }
    puts("");
}