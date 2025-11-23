#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> ph = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(int i, int n,string &digits, string &val, vector<string> &ans){
        if(i == n){
            ans.push_back(val);
            return;
        }
        for(char ch : ph[digits[i] - '0']){
            val+=ch;
        }
    }
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if(n==0)return {};
        string val;
        val.resize(n);
        vector<string> ans;
        dfs(0, n, digits, val, ans);
        return ans;
    }
};