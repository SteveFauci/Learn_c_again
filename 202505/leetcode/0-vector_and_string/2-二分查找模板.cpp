#include <vector>
using namespace std;
// clang-format off
class Solution {
  public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1,mid;
        while (l <= r) {
            mid = l + (r - l) / 2;//我这个吊毛这行一开始写在while外面，难怪求不出来。
            if (nums[mid] == target)return mid;
            if (nums[mid] > target)r = mid-1;
            if (nums[mid] < target)l = mid+1;
        }
        return l;
    }
};