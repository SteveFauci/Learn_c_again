#include <cstdio>
#include <vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
    auto size = nums.size();
    int  current_sum = 0, max_sum = nums[0];
    for (int i = 0; i < size; i++) {
        current_sum = max(current_sum + nums[i], nums[i]);
        max_sum = max(current_sum, max_sum);
    }
    return max_sum;
}

int main() {
    int n;
    scanf("%d", &n);
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("%d\n", maxSubArray(arr));
}
