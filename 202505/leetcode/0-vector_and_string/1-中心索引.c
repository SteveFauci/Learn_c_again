// 不知道那些人时间是怎么凹的，我看题解就这两种思路。
int pivotIndex(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        int l_sum = 0, r_sum = 0;
        for (int j = 0; j < i; j++) {
            l_sum += nums[j];
        }
        for (int j = i + 1; j < numsSize; j++) {
            r_sum += nums[j];
        }
        if (l_sum == r_sum)
            return i;
    }
    return -1;
}

int pivotIndex2(int* nums, int numsSize) {
    int total = 0;
    for (int i = 0; i < numsSize; i++) {
        total += nums[i];
    }
    for (int i = 0; i < numsSize; i++) {
        int current_total = 0;
        for (int j = 0; j < i; j++) {
            current_total += nums[j];
        }
        if (2 * current_total + nums[i] == total)
            return i;
    }
    return -1;
}