// 一遍过
// clang-format off
#include <stack>
#include <string>
#include <vector>

using namespace std;
class Solution {
  public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        auto size = tokens.size();
        for (int i = 0; i < size; i++) {
            if (tokens[i].size() == 1 && isOperator(tokens[i][0])) {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                nums.push(calc(num1,num2,tokens[i][0]));
            } else {
                nums.push(stod(tokens[i]));
            }
        }
        return nums.top();
    }
  private:
    bool isOperator(char ch) {
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
            return true;
        return false;
    }
    int calc(int num1, int num2, char op) {
        switch (op) {
        case ('+'):return num1 + num2;
        case ('-'):return num1 - num2;
        case ('*'):return num1 * num2;
        case ('/'):return num1 / num2;
        default: return -1;
        }
    }
};