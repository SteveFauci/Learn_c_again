#include <stack>
#include <string>
using namespace std;

class Solution {
  public:
    bool isValid(string s) {
        if (s.length() % 2)
            return false;
        else {
            stack<char> my_stack;
            for (int i = 0; i < s.length(); i++) {
                char ch = s[i];
                if (ch == '{' || ch == '(' || ch == '[') {
                    my_stack.push(ch);
                }
                else{ // (ch == '}' || ch == ')' || ch == ']') {
                    if(my_stack.empty())return false;
                    if(ch=='}'&&my_stack.top()=='{')my_stack.pop();
                    else if(ch==')'&&my_stack.top()=='(')my_stack.pop();
                    else if(ch==']'&&my_stack.top()=='[')my_stack.pop();
                    else return false;
                }
            }
            if(!my_stack.empty())return false;
            else return true;
        }
    }
};