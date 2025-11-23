#include <stdio.h>

char canvas[1024][2048]; // 足够大：n<=10 → 高1024, 宽2048
int pow2[11];

// 画规模为 n 的图腾，左上角起始位置 (r, c)
void draw(int n, int r, int c) {
    if (n == 1) {
        // 画基础单元：2 行
        canvas[r][c + 1] = '/';
        canvas[r][c + 2] = '\\';
        canvas[r + 1][c] = '/';
        canvas[r + 1][c + 1] = '_';
        canvas[r + 1][c + 2] = '_';
        canvas[r + 1][c + 3] = '\\';
    } else {
        int h = pow2[n - 1]; // 子图高度 = 2^(n-1)
        int w = pow2[n];     // 子图宽度偏移
        // 上方子图（居中）
        draw(n - 1, r, c + h);
        // 左下方子图
        draw(n - 1, r + h, c);
        // 右下方子图
        draw(n - 1, r + h, c + w);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 预计算 2 的幂
    pow2[0] = 1;
    for (int i = 1; i <= 11; i++) {
        pow2[i] = 2 * pow2[i - 1];
    }
    
    // 初始化画布为空格
    int height = pow2[n];
    int width = pow2[n + 1];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }
    
    // 从 (0, 0) 开始画
    draw(n, 0, 0);
    
    // 输出，注意每行末尾不要有多余空格（但题目通常允许）
    for (int i = 0; i < height; i++) {
        // 可以 trim 尾部空格，但洛谷一般不需要
        // canvas[i][width] = '\0';
        printf("%s\n", canvas[i]);
    }
    return 0;
}