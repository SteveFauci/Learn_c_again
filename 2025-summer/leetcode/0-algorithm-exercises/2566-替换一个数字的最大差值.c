#include<string.h>
#include<stdio.h>
int mypow(int n) {
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= 10;
    }
    return ans;
}
int minMaxDifference(int num) {
    char str1[15], str2[15];
    sprintf(str1, "%d", num);
    sprintf(str2, "%d", num);
    int sum1 = 0,sum2 = 0;
    int len = strlen(str1);
    char ch = str1[0];//第一个数直接换成0就是最小的
    char ch2 = '\0';//第一个非9的全换成9是最大的
    for (int i = 0; i < len; i++) {
        if(str2[i]!='9'){ch2 = str2[i];break;}
    }
    for (int i = 0; i < len; i++) {
        if(str1[i]==ch)str1[i]='0';//这里换成0
        if(str2[i]==ch2)str2[i]='9';
    }

    for (int i = 0; i < len; i++) {
        sum1 += (str1[i] - '0') * mypow(len - i - 1);
        sum2 += (str2[i] - '0') * mypow(len - i - 1);
    }
    return sum2 - sum1;
}