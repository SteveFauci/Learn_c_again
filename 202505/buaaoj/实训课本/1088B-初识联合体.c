#include <stdio.h>
union un {
    int  a;
    char ch[8];
};
int main() {
    union un test;
    for (int i = 0; i < 4; i++) {
        scanf("%c", &test.ch[i]);
    }
    printf("%x\n", test.a);
    for(int i = 0;i<4;i++){
        printf("%x",test.ch[i]);
    }
}