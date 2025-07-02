#include <stdio.h>
#include <stdlib.h>
int arr[1000005];
int cmp(const void* pp1, const void* pp2) {
    int* p1 = (int*)pp1;
    int* p2 = (int*)pp2;
    return *p1 > *p2;
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(arr[0]), cmp);
    int left = 0;
    for (int right = 0; right < n; right++) {
        if (arr[right] != arr[left]) {
            printf("%d ", arr[left]);
            left = right;
        }
        if(right == n -1)printf("%d\n", arr[left]);
    }
}