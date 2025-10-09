#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> my_stack;
        int sz = nums.size();
        vector<int> res(sz,-1);
        for(int i = 0 ; i < sz; i++){
            while(!my_stack.empty() && nums[my_stack.top()] < nums[i]){
                int index = my_stack.top();
                res[index] = nums[i];
                my_stack.pop();
            }
            my_stack.push(i);
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> nextGreaterElements(vector<int>& nums) {
//         stack<int> my_stack;
//         int sz = nums.size();
//         vector<int> res(2 * sz,-1);
//         vector<int> my_nums(2 * sz);
//         for(int i = 0; i < sz; i++){
//             my_nums[i] = my_nums[sz + i] = nums[i];
//         }
//         for(int i = 0 ; i < 2 * sz; i++){
//             while(!my_stack.empty() && my_nums[my_stack.top()] < my_nums[i]){
//                 int index = my_stack.top();
//                 res[index] = my_nums[i];
//                 my_stack.pop();
//             }
//             my_stack.push(i);
//         }
//         res.resize(sz);
//         return res;
//     }
// };