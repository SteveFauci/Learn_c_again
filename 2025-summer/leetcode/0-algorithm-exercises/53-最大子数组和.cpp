#include <algorithm>
#include <vector>
using namespace std;
// Kadane算法 BV17iTvzcEXN
// 动态规划有最优子结构 & 重叠子问题
// 变量名别用max
class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
        auto size = nums.size();
        int  current_sum = 0, max_sum = nums[0];
        for (int i = 0; i < size; i++) {
            current_sum = max(current_sum + nums[i], nums[i]);
            max_sum = max(current_sum, max_sum);
        }
        return max_sum;
    }
};