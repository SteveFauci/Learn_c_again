#include<stack>
#include<vector>
using namespace std;
//    2  1  5  6  2  3
//r [ 1,-1, 4, 4,-1,-1]
//l [-1,-1, 1, 2, 1, 4]
class Solution{
public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        stack<int> my_stack;
        vector<int> left(n,n),right(n,-1);
        for(int i = 0; i < n; i++){
            while(!my_stack.empty() && heights[my_stack.top()] > heights[i]){
                left[my_stack.top()] = i;
                my_stack.pop();
            }
            my_stack.push(i);
        }
        my_stack = stack<int>();
        for(int i = n - 1; i >= 0; i--){
            while(!my_stack.empty() && heights[my_stack.top()] > heights[i]){
                right[my_stack.top()] = i;
                my_stack.pop();
            }
            my_stack.push(i);
        }
        int ans = -1;
        for(int i = 0; i < n; i++){
            int r = left[i];
            int l = right[i];
            ans = max(ans,heights[i] * (r - l - 1));
        }
        return ans;
    }
};
