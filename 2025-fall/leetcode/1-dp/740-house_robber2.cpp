#include <bits/stdc++.h>
using namespace std;

class Solution {
    int rob(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return nums[0];

        int f0 = nums[sz-1], f1 = nums[0];
        for (int x : nums) {
            int new_f = max(f1, f0 + x);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

  public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = -1;
        for (auto i : nums) {
            mx = max(mx, i);
        }
        vector<int> arr(mx + 1);
        for (auto i : nums) {
            arr[i] += i;
        }
        return rob(arr);
    }
};