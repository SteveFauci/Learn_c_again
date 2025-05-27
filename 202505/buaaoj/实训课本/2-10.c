#include <stdio.h>
//小写字母字符串加密，K为密钥，编码a-z为0-25，下一个字符的编码加密为(前一个编码+K*(M-13))mod26
int main() {
    int K;
    scanf("%d", &K);
    getchar();
    char ch;
    int  m = 1;
    while ((ch = getchar()) != '\n') {
        int ans=((ch - 'a') + K * (m - 13)) % 26;
        if(ans<0)ans+=26;
        putchar(ans + 'a');
        m = ans;
    }
}
// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     int K;
//     printf("请输入密钥 K: ");
//     if (scanf("%d", &K) != 1) {
//         printf("无效的密钥输入\n");
//         return 1;
//     }
//     getchar(); // 消除换行符

//     char ch;
//     int m = 1; // 初始状态相同

//     printf("请输入密文字符串（仅限小写字母）: ");
//     while ((ch = getchar()) != '\n') {
//         if (!islower(ch)) {
//             printf("忽略非小写字母字符: %c\n", ch);
//             continue;
//         }

//         int cipher_code = ch - 'a';
//         int plain_code = (cipher_code - K * (m - 13)) % 26;
//         if (plain_code < 0) plain_code += 26;

//         putchar(plain_code + 'a');
//         m = cipher_code; // 更新 m 为当前加密后的值
//     }
//     putchar('\n');

//     return 0;
// }