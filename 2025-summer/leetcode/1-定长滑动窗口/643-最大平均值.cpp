#include <vector>
using namespace std;
class Solution {
  public:
    double findMaxAverage(vector<int>& nums, int k) {
        auto   size = nums.size();
        double sum = 0, max_n = -2147483647;
        for (int i = 0; i < size; i++) {
            sum += nums[i];// 入
            if (i < k - 1) continue;
            max_n = max(max_n, sum);// 更新
            sum -= nums[i - k + 1];// 出
        }
        return max_n / k;
    }
};