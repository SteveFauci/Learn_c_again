#include <stack>
#include <vector>
using namespace std;

class Solution {
  public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int sz = temperatures.size();
        stack<int> my_stack;
        vector<int> ans;
        for (int i = sz - 1; i >= 0; i--) {
            while(!my_stack.empty() && temperatures[i]>temperatures[my_stack.top()]){
                
            }
        }
    }
};