#include <algorithm>
#include <cstdio>
#include <vector>
int main() {
    int n;
    scanf("%d", &n);
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    std::sort(arr.begin(), arr.end());
    int left = 0, right = n - 1;
    if (arr[0] == arr[n - 1])
        printf("0 %lld\n", 1ll * n * (n - 1) / 2);
    else {
        while (arr[left] == arr[0])
            left++;
        while (arr[right] == arr[n - 1])
            right--;
        printf("%d %lld\n", arr[n - 1] - arr[0], 1ll* left * (n - right - 1));
    }
    return 0;
}