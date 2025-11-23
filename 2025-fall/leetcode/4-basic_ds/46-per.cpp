#include<vector>

using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>>& ans, vector<int>& nums, vector<int> & visited, vector<int> &cur){
        if(cur.size() == nums.size()){
            ans.push_back(cur);
        }
        for(int i = 0; i < nums.size(); i++){
            if(!visited[i]){
                visited[i] = 1;
                cur.push_back(nums[i]);
                dfs(ans,nums,visited,cur);
                visited[i] = 0;
                cur.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans = {};
        vector<int> visited(n,0), cur  = {};
        dfs(ans,nums,visited,cur);
        return ans;
    }
};