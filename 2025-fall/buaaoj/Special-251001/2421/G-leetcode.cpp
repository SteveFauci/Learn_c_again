#include <vector>
using namespace std;

class Solution {
  public:
    int my_count = 0;
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return my_count;
    }
    // 合并两个已排序的子数组：[left, mid] 和 [mid+1, right]
    void merge(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int         j = mid + 1;

        for (int i = left; i <= mid; i++) {
            while (j <= right && (long long)arr[i] > 2ll * (long long)arr[j]) {
                j++;
            }
            my_count += j - (mid + 1);
        }

        int i = left; // 左子数组的起始索引
        j = mid + 1;  // 右子数组的起始索引
        int k = 0;    // 临时数组的索引
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
};
