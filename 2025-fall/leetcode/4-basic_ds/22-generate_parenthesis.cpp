#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    void dfs(vector<string>& ans, string& cur, int n, int left, int right){
        if(left == n && right == n){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur.push_back('(');
            dfs(ans, cur, n, left + 1,right);
            cur.pop_back();
        }
        if(right < left){
            cur.push_back(')');
            dfs(ans, cur, n, left,right + 1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        int left = 0,right = 0;
        dfs(ans,cur,n,left,right);
        return ans;
    }
};