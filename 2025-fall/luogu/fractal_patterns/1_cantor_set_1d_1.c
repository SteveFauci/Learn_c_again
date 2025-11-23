// https://accoding.buaa.edu.cn/problem/7749/index

#include <stdio.h>
int  power_3[10] = {1};
void f(int n, int k) // 输出n次迭代中第i次迭代的一整行（不输出换行）
{
    // 基本情况（递归出口）
    if (k == 0) {
        for (int i = 0; i < power_3[n]; i++) {
            putchar('-');
        }
    } else {
        f(n - 1, k - 1);
        for(int i = 0; i < power_3[n - 1]; i++){
            putchar(' ');
        }
        f(n - 1, k - 1);
    }
    // 一般情况
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) // 求出3的幂，备用
        power_3[i] = 3 * power_3[i - 1];
    for (int i = 0; i <= n; ++i) {
        f(n, i);
        printf("\n"); // 每输出一行后要换行
    }
    return 0;
}