#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char s[1005];
    while(scanf("%s", &s) != EOF) {
        int len = strlen(s), flag = 1;
        for (int i = 0; i < len / 2 - 0; i++) {
            if (isalpha(s[i])) {
                if (islower(s[i]) && s[len - i - 1] != s[i] - 'a' + 'A') {
                    printf("n0\n");
                    flag = 0;
                    break;
                }
                else if (isupper(s[i]) && s[len - i - 1] != s[i] - 'A' + 'a') {
                    printf("n0\n");
                    flag = 0;
                    break;
                }
            }
            else {
                if (s[i] != s[len - i - 1]) {
                    printf("n0\n");
                    break;
                }
            }
        }
        if(flag==1)printf("yes\n");
    }
    return 0;
}
//把no改成了n0
//第8行for去掉了-1