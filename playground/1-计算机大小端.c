#include <stdio.h>

int main() {
    int i = 0x12345678;
    char *p = (char *)&i;

    if (*p == 0x78) {
        printf("This is Little Endian\n");
    } else if (*p == 0x12) {
        printf("This is Big Endian\n");
    }

    return 0;
}