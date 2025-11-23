#include<vector>
#include<algorithm>
using namespace std;
class Solution39 {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &cand, int target, vector<int> &cur, int &cursum,int start){
        if(cursum == target){
            ans.push_back(cur);
        }
        if(cursum > target)return;
        for(int i = start; i < cand.size(); i++){
            cur.push_back(cand[i]);
            cursum += cand[i];
            dfs(ans,cand,target,cur,cursum, i);
            cursum -= cand[i];
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<vector<int>> ans;
        vector<int> cur;
        int start = 0;
        int cursum = 0;
        dfs(ans, cand, target, cur, cursum, start);
        return ans;
    }
};
class Solution40 {
public:
    void dfs(vector<vector<int>> &ans, vector<int> &cand, int target, vector<int> &cur, int & cursum,int start){
        if(cursum == target){
            ans.push_back(cur);
        }
        for(int i = start; i < cand.size(); i++){
            if(i > start && cand[i] == cand[i - 1])continue;
            if(cursum + cand[i]> target)break;
            cursum += cand[i];
            cur.push_back(cand[i]);
            dfs(ans,cand,target,cur,cursum, i + 1);
            cur.pop_back();
            cursum -= cand[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(), cand.end());
        vector<vector<int>> ans;
        vector<int> cur;
        int start = 0;
        int cursum = 0;
        dfs(ans, cand, target, cur, cursum, start);
        return ans;
    }
};
class Solution216 {
public:
    void dfs(vector<vector<int>> &ans, vector<int> & cur, int target, int k,int &cursum, int start){
        if(cursum == target && cur.size() == k){
            ans.push_back(cur);
        }
        if(cursum > target)return;
        for(int i = start; i < 10; i++){
            cur.push_back(i);
            cursum += i;
            dfs(ans,cur,target,k,cursum,i + 1);
            cursum -= i;
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> cur;
        vector<vector<int>> ans;
        int start = 1;
        int cursum = 0;
        dfs(ans,cur,n,k ,cursum,start);
        return ans;
    }
};