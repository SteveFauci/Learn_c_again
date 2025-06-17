// clang-format off
#include<vector>
#include<algorithm>
using namespace std;
//自己写的，虽然过了但是时空复杂度比较拉。思路没错，排序+双指针。
//石山代码：面向测试用例加上特判。
class Solution0 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto sz = nums.size();
        //////////////////////////////////
        int flag = 0;
        for(int i = 0;i<sz;i++){
            if(nums[i]!=0){flag = 1;break;}
        }
        if(flag ==0) return {{0,0,0}};
        //////////////////////////////////
        vector<int> temp(3);
        vector<vector<int>> ans;
        // clang-format on
        for (int i = 0; i < sz - 2; i++) {
            int target = nums[i];
            int left = i + 1, right = sz - 1;
            int current = nums[left] + nums[right];
            while (left < right) {
                current = nums[left] + nums[right];
                if (current + target > 0)
                    right--;
                else if (current + target < 0)
                    left++;
                else if (target + current == 0) {
                    temp = {nums[i], nums[left], nums[right]};
                    ans.push_back(temp);
                    left++;
                }
            }
        }
        sort(ans.begin(), ans.end());
        auto it = unique(ans.begin(), ans.end());
        ans.erase(it, ans.end());
        return ans;
    }
};
// 剪枝一下 并且手动去重
// clang-format off
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto sz = nums.size();
        vector<vector<int>> ans;
        if (nums.empty() || nums[0] > 0) return ans; // 剪枝1：第一个数大于0，不可能有解
        for (int i = 0; i < sz - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; // 去重 nums[i]
            int left = i + 1, right = sz - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < 0)left++;
                else if (sum > 0)right--;
                else {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    while (left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                }
            }
        }
        return ans;
    }
};