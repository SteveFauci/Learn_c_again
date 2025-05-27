//小端对齐-计算机组成原理？
#include <stdio.h>
typedef union {
  //  unsigned char  ch[4];
    unsigned short un[2];
    unsigned int   num;
} un;
int main() {
    un a;
    scanf("%u", &a.num);//输入aaff2025 -> 25 20 ff aa
//    printf("%u\n", a.num);
    printf("%u %u\n", a.un[1], a.un[0]);//去掉unsigned试试?
}
