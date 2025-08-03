#include <stack>
#include<bits/stdc++.h>
#include <vector>
using namespace std;
class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto sz = temperatures.size();
        vector<int> ans(sz, 0);
        stack<int>  my_stack;
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

// [73,74,75,71,69,72,76,73]
// [ 1, 1, 4, 2, 1, 1, 0, 0]