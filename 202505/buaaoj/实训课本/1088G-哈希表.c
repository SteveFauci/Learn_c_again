#include <stdio.h>
int nums[1000005];
int main() {
    int n, m;
    int key;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int j = 1; j <= m; j++) {
        scanf("%d", &key);
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (flag == 1) {
                break;
            }
            if (key == nums[i]) {
                printf("%d ", i);
                flag = 1;
            }
        }
        if (flag == 0) {
            printf("0 ");
        }
    }
}