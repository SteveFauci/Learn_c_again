#include <cstddef>
#include <stack>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution1 {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>  my_stack;
        auto        size = nums2.size();
        auto        size2 = nums1.size();
        vector<int> answer(size, -1);
        // 单调栈，储存角标差
        for (size_t i = 0; i < size; i++) {
            while (!my_stack.empty() && nums2[i] > nums2[my_stack.top()]) {
                answer[my_stack.top()] = i - my_stack.top();
                my_stack.pop();
            }
            my_stack.push(i);
        }
        // 暴力查找，确实通过了，但是题解是用的hash表查找。
        vector<int> output;
         for (int i = 0; i < size2; i++) {
             for (int j = 0; j < size; j++) {
                 if (nums1[i] == nums2[j]) {
                     if (answer[j] != -1) {
                         output.push_back(nums2[j + answer[j]]);
                         continue;
                     } else {
                         output.push_back(-1);
                         continue;
                     }
                 }
             }
         }
        return output;
    }
};

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>  my_stack;
        auto        size = nums2.size();
        auto        size2 = nums1.size();
        vector<int> answer(size, -1);
        // 单调栈，储存角标差
        for (size_t i = 0; i < size; i++) {
            while (!my_stack.empty() && nums2[i] > nums2[my_stack.top()]) {
                answer[my_stack.top()] = i - my_stack.top();
                my_stack.pop();
            }
            my_stack.push(i);
        }

        // 改用hash表
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < size; i++) {
            map[nums2[i]] = answer[i];
        }
        for (int i = 0; i < size2; i++) {
            ans.push_back(map[nums2[i]]);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        stack<int> st;
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashmap[num] = st.empty() ? -1 : st.top();
            st.push(num);
        }
        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) {
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};
