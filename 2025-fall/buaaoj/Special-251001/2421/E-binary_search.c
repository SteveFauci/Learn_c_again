#include <stdio.h>

int arr[200005];

int lower_bound(int arr[], int key, int n) {
    int l = 0, r = n - 1;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] >= key) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int upper_bound(int arr[], int key, int n) {
    int l = 0, r = n - 1;
    int ans = n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] > key) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    while (q--) {
        int key;
        scanf("%d", &key);
        int ub = upper_bound(arr, key, n);
        int lb = lower_bound(arr, key, n);
        printf("%d %d\n", lb + 1, ub + 1);
    }
    return 0;
}