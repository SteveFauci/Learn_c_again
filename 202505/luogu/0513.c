#include <stdio.h>

// 构造月份
int getmon(int year) {
    int d = year % 10;
    int c = (year % 100) / 10;
    return c + 10 * d;
}

// 构造日
int getday(int year) {
    int b = (year % 1000) / 100;
    int a = year / 1000;
    return a + 10 * b;
}

// 判断闰年
int isLeap(int y) {
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

// 获取某月的天数
int getDaysOfMonth(int y, int m) {
    switch (m) {
        case 1: case 3: case 5: case 7:
        case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeap(y) ? 29 : 28;
        default:
            return 0; // 不合法的月份返回0
    }
}

int main() {
    int date1, date2;
    scanf("%d%d", &date1, &date2);

    int year1 = date1 / 10000;
    int year2 = date2 / 10000;

    int count = 0;

    for (int y = year1; y <= year2; y++) {
        int m = getmon(y);
        int d = getday(y);

        if (m < 1 || m > 12) continue;
        if (d < 1 || d > getDaysOfMonth(y, m)) continue;

        int constructed = y * 10000 + m * 100 + d;

        if (constructed >= date1 && constructed <= date2) {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}