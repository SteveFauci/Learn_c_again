// https://accoding.buaa.edu.cn/problem/7749/index

#include <stdio.h>
int  power_3[10] = {1};
char f(int n, int i, int j) // 返回n次迭代中第i次迭代的一行中的第j个字符
{
    // 基本情况（递归出口）
    if(i == 0){
        return '-';
    }
    int len = power_3[n - 1];
    // 一般情况
    if(j < len){
        return f(n - 1, i - 1, j);
    }else if(j < 2 * len){
        return ' ';
    }else{
        return f(n - 1, i - 1, j - 2 * len);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) // 求出3的幂，备用
        power_3[i] = 3 * power_3[i - 1];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < power_3[n]; ++j)
            printf("%c", f(n, i, j));
        printf("\n"); // 每输出一行后要换行
    }
    return 0;
}