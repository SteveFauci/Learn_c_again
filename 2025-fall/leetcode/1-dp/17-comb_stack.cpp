#include<string>
#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<string> ph = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty())return {};
        vector<string> res = {};
        stack<pair<string,int>> my_stack;
        my_stack.push({"",0});
        while(!my_stack.empty()){
            auto temp = my_stack.top();
            auto cur_str = temp.first;
            auto cur_idx = temp.second;
            my_stack.pop();
            if(cur_str.size() == digits.size()) res.push_back(cur_str);
            else{
                char digit = digits[cur_idx];
                for(auto ch : ph[digits[cur_idx] - '0']){
                    my_stack.push({cur_str+ch, cur_idx+1});
                }
            }
        }
        return res;
    }
};