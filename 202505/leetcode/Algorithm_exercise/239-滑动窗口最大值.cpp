#include <vector>
#include <deque>
using namespace std;
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> my_que;
        auto size = nums.size();
        int max_n = -2147483648;
        for (int i = 0; i < size; i++) {
            max_n = max(max_n,nums[i]);
        }
    }
};