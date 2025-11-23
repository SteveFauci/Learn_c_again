#include<string>
#include<vector>
using namespace std;
class Solution {
    public:
    const vector<string> ph = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(vector<string>&ans, string& cur, string& digits, int i){
        if(cur.size() == digits.size()){
            ans.push_back(cur);
            return;
        }
        for(char ch : ph[digits[i] - '0']){
            cur.push_back(ch);
            dfs(ans,cur,digits,i + 1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string cur;
        dfs(ans,cur,digits,0);
        return ans;
    }
};