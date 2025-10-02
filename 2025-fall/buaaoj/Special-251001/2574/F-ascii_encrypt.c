#include <ctype.h>
#include <stdio.h>
#include <string.h>
char str1[105];
char str2[1005];
void my_gets(char* s, int limit) {
    fgets(s, limit, stdin);
    s[strcspn(s, "\n")] = '\0';
}
int main() {
    my_gets(str1, 105);
    my_gets(str2, 1005);
    int sz1 = strlen(str1);
    int sz2 = strlen(str2);
    for (int i = 0; i < sz2; i++) {
        int temp = i % sz1;
        if (isupper(str2[i]) && isupper(str1[temp]))
            str2[i] = (str2[i] - 'A' - (str1[temp] - 'A') + 26) % 26 + 'A';
        else if (isupper(str2[i]) && islower(str1[temp]))
            str2[i] = (str2[i] - 'A' - (str1[temp] - 'a') + 26) % 26 + 'A';
        else if (islower(str2[i]) && isupper(str1[temp]))
            str2[i] = (str2[i] - 'a' - (str1[temp] - 'A') + 26) % 26 + 'a';
        else if (islower(str2[i]) && islower(str1[temp]))
            str2[i] = (str2[i] - 'a' - (str1[temp] - 'a') + 26) % 26 + 'a';
    }
    puts(str2);
}