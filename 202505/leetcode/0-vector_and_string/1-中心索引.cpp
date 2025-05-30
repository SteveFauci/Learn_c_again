#include <vector>
using namespace std;

// 过是过了，但是非常的不优雅。895ms超过了6%的人
class Solution {
  public:
    int pivotIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int l_sum = 0, r_sum = 0;
            for (int j = 0; j < i; j++) {
                l_sum += nums[j];
            }
            for (int j = i + 1; j < nums.size(); j++) {
                r_sum += nums[j];
            }
            if (l_sum == r_sum)
                return i;
        }
        return -1;
    }
};
// 下面这个349ms超过8.16%
class Solution2 {
  public:
    int pivotIndex(vector<int>& nums) {
        int total = 0;
        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];
        }
        for (int i = 0; i < nums.size(); i++) {
            int current_total = 0;
            for (int j = 0; j < i; j++) {
                current_total += nums[j];
            }
            if (2 * current_total + nums[i] == total)
                return i;
        }
        return -1;
    }
};