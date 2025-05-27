#include <stdio.h>
#include <string.h>
char  A[50005];
char  cache[50005];
int   count[50005];
char  output[50005];
char* compressString(char* S) {
    char* p1 = S;
    char* p2 = S;
    char  ch;
    int   cnt = 0;
    int   j = 0;
    for (int i = 0; i < strlen(S) + 1; i++) {
        p2 = S + i;
        cnt++;
        if (*p2 != ch) {
            p1 = S + i;
            cache[j] = ch;
            count[j] = cnt;
            cnt = 0;
            ch = *p1;
            j++;
        }
    }
    for (int i = 1; i < j; i++) {
        sprintf(output + strlen(output), "%c%d", cache[i], count[i]);
    }
    return strlen(output) > strlen(S) ? S : output;
}

int main() {
    fgets(A, 50005, stdin);
    A[strlen(A) - 1] = '\0';
    puts(compressString(A));
}