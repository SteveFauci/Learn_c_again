#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int min_time = 2147483647;
    int max_time = 0;
    for (int i = 0; i < m; i++) {
        int x;
        char d;
        scanf("%d %c", &x, &d);
        if (d == 'L') {
            int t0 = x;
            if (t0 < min_time) min_time = t0;
            if (t0 > max_time) max_time = t0;
        } else {
            int t0 = n + 1 - x;
            if (t0 < min_time) min_time = t0;
            if (t0 > max_time) max_time = t0;
        }
    }
    printf("%d %d\n", min_time, max_time);
    return 0;
}