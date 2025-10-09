#include <stack>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        stack<int>  my_stack;
        vector<int> ans(sz, 0);
        for (int i = 0; i < sz; i++) {
            while (!my_stack.empty() && temperatures[my_stack.top()] < temperatures[i]) {
                ans[my_stack.top()] = i - my_stack.top();
                my_stack.pop();
            }
            my_stack.push(i);
        }
        return ans;
    }
};