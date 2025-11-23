#include<vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &ans, vector<int> & nums, vector<int> &cur, int lyr){
        ans.push_back(cur);
        for(int i = lyr; i < nums.size(); i++){
            cur.push_back(nums[i]);
            dfs(ans, nums, cur, lyr + 1);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(ans, nums, cur, 0);
        return ans;
    }
};