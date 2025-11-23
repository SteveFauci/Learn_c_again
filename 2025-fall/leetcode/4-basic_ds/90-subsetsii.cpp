#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> & ans, vector<int>& nums, vector<int> &cur, int start){
        ans.push_back(cur);
        for(int i = start; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) continue;
            cur.push_back(nums[i]);
            dfs(ans,nums,cur,i+1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> cur;
        int start = 0;
        dfs(ans,nums,cur,start);
        return ans;
    }
};