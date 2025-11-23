#include <stdio.h>
int  power_3[10] = {1};
char canvas[11][59050];
void draw(int x, int y, int n) {
    int size = power_3[n];
    for (int i = 0; i < size; i++) {
        canvas[x][y + i] = '-';
    }
    if(n >= 1){
        int sub_size = power_3[n - 1];
        draw(x + 1, y, n - 1);
        draw(x + 1, y + 2 * sub_size, n - 1);
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) // 求出3的幂，备用
        power_3[i] = 3 * power_3[i - 1];
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j < power_3[n]; ++j)
            canvas[i][j] = ' ';
    draw(0, 0, n);
    for (int i = 0; i <= n; ++i) {
        puts(canvas[i]);
    }
    return 0;
}