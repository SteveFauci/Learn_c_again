#include <cstdio>
#include <vector>
using namespace std;

int my_k;

long long my_count = 0;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int         j = mid + 1;
    // 把下面统计“反转对”的代码删掉，就是归并排序
    ///////////////////////////////////
    for (int i = left; i <= mid; i++) {
        while (j <= right &&
               (long long)arr[i] > (long long)my_k * (long long)arr[j]) {
            j++;
        }
        my_count += j - (mid + 1);
    }
    ///////////////////////////////////
    int i = left;
    j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (int idx = 0; idx < k; ++idx) {
        arr[left + idx] = temp[idx];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
long long reversePairs(vector<int>& nums) {
    my_count = 0;
    mergeSort(nums, 0, nums.size() - 1);
    return my_count;
}

int main() {
    int n;
    scanf("%d%d", &n, &my_k);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%lld\n", reversePairs(arr));
}