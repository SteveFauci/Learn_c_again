// 注意用hash表统计元素个数的时候，如果hash[i]为0，应该hash.erase(i);
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int sz = nums.size();
        unordered_map<int, int> my_map;
        long long ans = 0, sum = 0;
        for(int i = 0; i < sz; i++){
            sum += nums[i];
            my_map[nums[i]]++;
            if(i < k-1)continue;
            if(my_map.size()==k)ans = max(ans,sum);
            int temp = nums[i-k+1];
            my_map[temp]--;
            if(my_map[temp]==0)my_map.erase(temp);
            sum -= temp;
        }
        return ans;
    }
};